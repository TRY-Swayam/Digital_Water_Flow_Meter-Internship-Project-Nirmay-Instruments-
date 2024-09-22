

#include <FlowMeter.h>

#include "Wire.h"
#include "OakOLED.h"
OakOLED oled;
FlowMeter Meter1 = FlowMeter(2);
FlowMeter Meter2 = FlowMeter(3);



void Meter1ISR() {
    
    Meter1.count();
}


void Meter2ISR() {
  
    Meter2.count();
}

void setup() {
    oled.begin();

    Serial.begin(9600);

    attachInterrupt(INT0, Meter1ISR, RISING);
    attachInterrupt(INT1, Meter2ISR, RISING);

   
    Meter1.reset();
    Meter2.reset();
}

void loop() {
    oled.clearDisplay();
    oled.setTextSize(1); 
    oled.setTextColor(1);
    oled.setCursor(45, 15);
    oled.println("NIRMAY"); 
    oled.setCursor(32, 30);
    oled.println("INSTRUMENTS ");
    oled.setCursor(45, 45);
    oled.println("PVT LTD ");
    oled.display();
    delay(3000); // Display "abc" for 3 second

while(true){
      data();
  }
}
void data(){
  
    Meter1.tick(3000);
    Meter2.tick(3000);


oled.clearDisplay();
oled.setTextSize(1);
oled.setTextColor(1.5);
oled.setCursor(10, 10);
oled.println("Flow rate");
oled.setTextSize(2);
oled.setCursor(10, 28);
oled.println(Meter2.getCurrentFlowrate());
oled.setTextSize(2);
oled.setCursor(80, 28);
oled.println("l/m");
oled.setTextSize(1);
oled.setCursor(11, 57);
oled.println("Nirmay Instrumnets");

oled.display();
delay (3000);
}
