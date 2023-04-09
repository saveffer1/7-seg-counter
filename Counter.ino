const int bt1 = 6; //count to x
const int bt2 = 7; //count to y

const int ck = 8,res = 9,res2 = 10; //PIN clock pulse, reset QB, reset QA

int count2 = 39; //y

int sleep = 60; //delay of count

int count = 99; //x

const int ledPin =  2;
bool isLedOn = false;   

int currentButtonState1 = LOW;
int previousButtonState1 = LOW; 

int currentButtonState2 = LOW;
int previousButtonState2 = LOW; 


void setup() {

  pinMode(ledPin,OUTPUT);
  pinMode(bt1,INPUT);
  pinMode(bt2,INPUT);
  pinMode(ck,OUTPUT);
  pinMode(res,OUTPUT);
  pinMode(res2,OUTPUT);
  
}

void loop() {

  currentButtonState1 = digitalRead(bt1);
  currentButtonState2 = digitalRead(bt2);

  if ((currentButtonState1 != previousButtonState1) && previousButtonState1 == HIGH){

          sfcreated(count,sleep,ck);
          reset(res,res2,sleep);
          
        if(ck > 99 || ck <0){
          for(int c9 = 0;c9 < 99; c9++){
                digitalWrite(ck,HIGH);
                delay(sleep);
                digitalWrite(ck,LOW);
                delay(sleep);
                reset(res,res2,sleep);
                 }
          }

    }
    
  if((currentButtonState2 != previousButtonState2) && previousButtonState2 == HIGH){

          sfcreated(count2,sleep,ck);
          reset(res,res2,sleep);
          
        if(ck > 99 || ck <0){
          for(int c9 = 0;c9 < 99; c9++){
                digitalWrite(ck,HIGH);
                delay(sleep);
                digitalWrite(ck,LOW);
                delay(sleep);
                reset(res,res2,sleep);
                 }
          }

    }
    
  previousButtonState1 = currentButtonState1;
  previousButtonState2 = currentButtonState2;

}

void sfcreated(int ck,int del,int pinck){
    for(int x = 0;x < ck; x++){
      digitalWrite(pinck,HIGH);
      delay(del);
      digitalWrite(pinck,LOW);
      delay(del);
      }
}

void reset(int r1,int r2,int dell){
    delay(dell);
    digitalWrite(r1,HIGH);
    digitalWrite(r2,HIGH);
    
    delay(dell);
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
}
  
