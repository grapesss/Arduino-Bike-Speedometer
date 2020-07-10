// My bike wheel circumference is 86 inches

#define reed A0

int reedval;
int circuitState = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  reedVal = analogRead(reed);
  int count = 0;
  unsigned long firstMillis = millis;
  while(millis - firstMillis >= 1000) {
    if (reedVal == 1023){ // Number might be different, this was last tested with the reed switch getting 5V,
      count += 1; // but now, since it has 3.3V, the number might be different
    }
  }
  Serial.println(count);
}
