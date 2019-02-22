/*********************************************************************
	Essai d'afficheur OLED sur Nucleo

	Author : Jean-Marc Chiappa
	Date   : 4.03.2018
	Rev : 0
	
	*******************************************************************/

#ifndef Oled_score_h
#define Oled_score_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Number.h"

#define YPOS_DISPLAY 64-BMP_NB_HEIGHT
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

class Oled_Score
{
public:
	Oled_Score(TwoWire *dev_i2c = &Wire);
	void init(void);
	void display(uint16_t score);

private:
	uint8_t _sda=SDA;
	uint8_t _scl=SCL;
	TwoWire *Disp_Wire;
};

#endif // Oled_score_h