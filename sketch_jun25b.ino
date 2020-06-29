// Run sudo chmod a+rw /dev/ttyACM0 before running this script if you're using Linux
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

int count = 0;
const int button = 8;
int pressed;
int buttonState = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup(){
  pinMode(button, INPUT);
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 5);
  display.println("Button Counter");
  display.display();
}

void loop(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  buttonState = digitalRead(button);
  
  if (buttonState != 0){
    display.setCursor(0, 30);
    display.println("LED on");
  }

  else{
    display.setCursor(0, 30);
    display.println("LED off");
  }
  display.display();
}
