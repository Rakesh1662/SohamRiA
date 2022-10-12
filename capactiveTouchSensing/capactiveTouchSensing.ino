#include <CapacitiveSensor.h>
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4); // 1M resistor between pins 2 & 4, pin 4 is sensor pin, add a wire and 
int cnt=0;
int in = 2; 
int out = 4;  
int state = HIGH;  
int r;           
int p = LOW;    
long time = 0;       
long debounce = 200;
byte buzzer = 9 ;
int delay_time = 500;
byte aCount ,bCount ,cCount  =0; 

void buzz(){
    digitalWrite(buzzer,HIGH);
    delay(delay_time);
    digitalWrite(buzzer,LOW);
    delay(20);
    digitalWrite(buzzer,HIGH);
    delay(delay_time);
    digitalWrite(buzzer,LOW);
    delay(20);
    digitalWrite(buzzer,HIGH);
    delay(delay_time);
    digitalWrite(buzzer,LOW);
}
void setup()
{
  pinMode(4, INPUT);
  /*    LED Outputs   */
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 
  pinMode(buzzer,OUTPUT);
}
void loop()                    
{
  r = digitalRead(4);
  if (r == HIGH && p == LOW && millis() - time > debounce) {
    cnt++;
  if (state == HIGH)
     state = LOW;
    else 
    time = millis();
  } 
  if(cnt == 1){
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    Serial.print(cnt);
    while(aCount < 1){
      buzz();
      aCount++;
    }
  }
  if(cnt == 2){
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    Serial.print(cnt);
    while(bCount < 1){
      buzz();
      bCount++;
    }
  }
  if(cnt == 3){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    Serial.print(cnt);
    while(cCount < 1){
      buzz();
      cCount++;
    }
  }
  if(cnt > 3){
      cnt = 0;
      aCount = 0 ;
      bCount = 0 ;
      cCount = 0 ;
  }
  p = r;
  Serial.print(r);
  Serial.print(cnt);
}
