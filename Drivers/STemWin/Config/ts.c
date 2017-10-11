#include "ts.h"

extern SPI_HandleTypeDef hspi2;

Pen_Holder Pen_Point;

unsigned char flag=0;


int GUI_TOUCH_X_MeasureX()
{
	  unsigned short i;
	  unsigned short sum=0;
	  for(i=0;i<8;i++)
	   	sum+=TPReadX();
	  return sum>>3;

}

int GUI_TOUCH_X_MeasureY()
{
	  unsigned short i;
	  unsigned short sum=0;
	  for(i=0;i<8;i++)
	   	sum+=TPReadY();
	  return sum>>3;
}


void pfSendCmd(unsigned char Data)
{
//	while(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_TXE)==RESET);
////	SPI_I2S_SendData(SPI2,Data);			//mel need to get ADS7486 Datasheet
	HAL_SPI_Transmit(&hspi2, &Data, sizeof(Data), 100U);
//	SPI_RW_Byte(Data);						//not quite matching up to XPT2046??
}

unsigned short int pfGetResult()
{
	unsigned short int x=0;
	SPI_Delay(50);

//	SPI_I2S_ReceiveData(SPI2);
	SPI_RW_Byte(0x50); //
	SPI_Delay(50);	//
	x=SPI_RW_Byte(0x00);
	x<<=8;
	x+=SPI_RW_Byte(0x00);

	x=x>>4;
	x= x & 0xFFF;
	return x;
}

char pfGetBusy()
{
//	if(SPI_I2S_GetFlagStatus(SPI2,SPI_I2S_FLAG_BSY))
	if(__HAL_SPI_GET_FLAG(&hspi2,SPI_FLAG_BSY))
		return 1;
	else
		return 0;
}


void pfSetCS(char OnOff)
{
	if(OnOff)
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
}

char pfGetPENIRQ()
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12))
		return 0;
	else
		return 1;

}

  
unsigned char SPI_RW_Byte(unsigned char num)
{
	unsigned char Data = 0;

	HAL_SPI_TransmitReceive(&hspi2,&num, &Data,1, 100U);

	return Data;
}

void SPI_Delay(unsigned int DelayCnt)
{
	unsigned int i;
	for(i=0;i<DelayCnt;i++);
}

unsigned short int TPReadY(void)
{
	unsigned short int y=0;
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
	SPI_Delay(50);
	SPI_RW_Byte(0xD0);
	SPI_Delay(50);
	y=SPI_RW_Byte(0x00);
	y<<=8;
	y+=SPI_RW_Byte(0x00);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
	y=y>>4;
	y= y & 0xFFF;
	return y;
}


unsigned short int TPReadX(void)
{
	unsigned short int x=0;
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
	SPI_Delay(50);
	SPI_RW_Byte(0x90);
	SPI_Delay(50);
	x=SPI_RW_Byte(0x00);
	x<<=8;
	x+=SPI_RW_Byte(0x00);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);

	x = x>>4;
	x  = x & 0xFFF;
	return x;
}



#define TSLEFT 137
#define TSRIGHT 1909
#define TSTOP 161
#define TSBOTTOM 1850

//hard code these so not to recalculate every time
//#define XDIVISOR (TSRIGHT-TSLEFT)/320
//#define YDIVISOR (TSBOTTOM-TSTOP)/240

#ifdef ILI9481

#define XDIVISOR 3.69  	//TSRIGHT-TSLEFT)/480
#define YDIVISOR 5.28	//TSBOTTOM-TSTOP)/320

#elif SSD1963

#define XDIVISOR 2.82  	//TSBOTTOM-TSTOP)/600
#define YDIVISOR 2.22	//TSRIGHT-TSLEFT)/800

#else

#define XDIVISOR 5.54	//(TSRIGHT-TSLEFT)/320
#define YDIVISOR 7.04	//(TSBOTTOM-TSTOP)/240

#endif

void Convert_Pos(void)
{
	Pen_Point.X=GUI_TOUCH_X_MeasureX();
	Pen_Point.Y=GUI_TOUCH_X_MeasureY();

	Pen_Point.X0=(int)((Pen_Point.X-TSLEFT)/XDIVISOR); //widescreen xy, 00 upper left
	Pen_Point.Y0=(int)((Pen_Point.Y-TSTOP)/YDIVISOR);

	pstate.x = Pen_Point.X0;
	pstate.y = Pen_Point.Y0;

	if (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12))
		pstate.Pressed = 0;		//pressed active lo
	else
		pstate.Pressed = 1;

	GUI_PID_StoreState(&pstate);
}

