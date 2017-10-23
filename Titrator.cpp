
#include "Titrator.h"


void setup()
{
    Serial.begin(115200);
    u8g2.begin();

    ph = 0.0f;
    old_ph = 0.0f;
    ml = 0;
    old_ml = 0;
    oldmillis = millis();
}
void render_first() {
  u8g2.firstPage();
  do {
    u8g2.drawXBM( 0, 0, u8g_logo_width, u8g_logo_height, u8g_logo_bits);
  } while ( u8g2.nextPage() );

}
void render() {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_helvR10_tf);
    u8g2.drawRFrame(0, 0, 128, 19, 4);
    u8g2.setCursor(8,15);
    u8g2.print(message);
    u8g2.drawRFrame(0, 20, 128, 44, 4);

    //first line
    u8g2.setCursor(14, 38);
    u8g2.print(ml);
    u8g2.print(SPACE);
    //u8g2.setCursor(45, 38);
    u8g2.print(ML_TEXT);
    u8g2.print(SPACE);
    u8g2.print(SPACE);
    u8g2.print(vinegar_size);
    u8g2.print(ML_TEXT);

    //dtostrf(vinegar_size, 6, 2, vinegar_size_text);
    //u8g2.drawStr(65, 38, vinegar_size_text);
    //u8g2.drawStr(108, 38, ML_TEXT);

    //second line
    dtostrf(ph, 6, 2, ph_text);
    u8g2.drawStr(0, 56, ph_text);
    u8g2.drawStr(45, 56, PH_TEXT);

    dtostrf(percentage, 6, 2, percentage_text);
    u8g2.drawStr(65, 56, percentage_text);
    u8g2.drawStr(108, 56, P_TEXT);

  } while ( u8g2.nextPage() );
}

void loop()
{
	  milliseconds = millis();
	  if ((milliseconds - oldmillis) < 5000) {
	    render_first();
	  } else {

	    render();
	  }
}
