#include "OLED_Score.h"

uint16_t value=0;
TwoWire Disp_Wire(SDA,SCL); // SDA , SDL

Oled_Score Afficheur(&Disp_Wire);

void setup(){                
	Afficheur.init();
}

void loop()
{
  //Serial.print(".");
	//CurrentTimeSeconds = millis()/1000;

	Afficheur.print(value++);
	value%=1000;
}
