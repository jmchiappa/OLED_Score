#include "OLED_Score.h"

#define I2C_SPEED	400000	//Hz, HIGH SPEED I2C

Oled_Score::Oled_Score(TwoWire *dev_i2c) : // define new I2C for specific application
	Disp_Wire(dev_i2c),
	Adafruit_SSD1306(128,64, dev_i2c,-1,I2C_SPEED)
{}

void Oled_Score::init(void)
{
	/* new begin prototype :
	* SSD1306_SWITCHCAPVCC : use internal step up
	* 0x3C : I2C address
	* -1 : no reset pin connected
	* true : force a Disp_Wire->begin() in the new SSD1306 begin()
	*/
  begin(SSD1306_SWITCHCAPVCC, 0x3C, -1,false);  // initialize with the I2C addr 0x3D (for the 128x64)
  clearDisplay();
  dim(false);
}

void Oled_Score::print(uint16_t value)
{
	if(value<1000)
	{
		clearDisplay();
		drawBitmap(0,YPOS_DISPLAY, number_bmp[(char)(value/100)], BMP_NB_WIDTH, BMP_NB_HEIGHT, WHITE);
		value-=(char)(value/100)*100;
		drawBitmap(44,YPOS_DISPLAY, number_bmp[(char)(value/10)], BMP_NB_WIDTH, BMP_NB_HEIGHT, WHITE);
		value-=((char)(value/10))*10;
		drawBitmap(86,YPOS_DISPLAY, number_bmp[value], BMP_NB_WIDTH, BMP_NB_HEIGHT, WHITE);
		display();
	}
}

