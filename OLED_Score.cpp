#include "OLED_Score.h"

/*#define SDA2	43	// PB14
#define SCL2	44	// PB13
*/
#define I2C_400KHZ	400000	//Hz, HIGH SPEED I2C
//TwoWire WIRE2(SDA2, SCL2);  //SDA=PB11 & SCL=PB10

Adafruit_SSD1306 disp(-1);	

Oled_Score::Oled_Score(TwoWire *dev_i2c) // define new I2C for specific application
{
	Disp_Wire = dev_i2c;
}

void Oled_Score::init(void)
{
  //disp=new Adafruit_SSD1306(0);
  disp.begin(SSD1306_SWITCHCAPVCC, 0x3C, Disp_Wire);  // initialize with the I2C addr 0x3D (for the 128x64)
  Disp_Wire->setClock(I2C_400KHZ);
  disp.clearDisplay();
  disp.dim(false);
}

void Oled_Score::display(uint16_t value)
{
	if(value<1000)
	{
		disp.clearDisplay();
		disp.drawBitmap(0,YPOS_DISPLAY, number_bmp[(char)(value/100)], BMP_NB_WIDTH, BMP_NB_HEIGHT, WHITE);
		value-=(char)(value/100)*100;
		disp.drawBitmap(44,YPOS_DISPLAY, number_bmp[(char)(value/10)], BMP_NB_WIDTH, BMP_NB_HEIGHT, WHITE);
		value-=((char)(value/10))*10;
		disp.drawBitmap(86,YPOS_DISPLAY, number_bmp[value], BMP_NB_WIDTH, BMP_NB_HEIGHT, WHITE);
		disp.display();
	}
}

