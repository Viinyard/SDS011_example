// SDS011 dust sensor example
// -----------------------------
//
// By R. Zschiegner (rz@madavi.de).
// April 2016

#include <LiquidCrystal.h>
#include <SDS011.h>

#define RS 9
#define E 8
#define D4 5
#define D5 4
#define D6 3
#define D7 2

#define COLS_CRYST 16
#define ROWS_CRYST 2

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

float p10,p25;
int error;

SDS011 my_sds;

void setup() {
  lcd.begin(COLS_CRYST, ROWS_CRYST);
  lcd.print("Starting ...");
	my_sds.begin(10,11);
	Serial.begin(9600);
}

void loop() {
	error = my_sds.read(&p25,&p10);
	if (! error) {
    lcd.clear();
    
    //lcd.setCursor(0, 0);
    lcd.print("P2.5: "+String(p25));
    lcd.setCursor(0, 1);
    lcd.print("P10:  "+String(p10));
    
		Serial.println("P2.5: "+String(p25));
		Serial.println("P10:  "+String(p10));
	}
	delay(1000);
}
