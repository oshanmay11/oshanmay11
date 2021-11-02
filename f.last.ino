 
#include <Servo.h>  //include servo.h library
Servo myservo;
 char input;
 int pos = 0; 

 const int flamepin1=A1;
const int flamepin2=A2;
const int flamepin3=A3;

int flamesensvalue1=0;
int flamesensvalue2=0;
int flamesensvalue3=0;


void setup() {
  pinMode(6,OUTPUT);//wheel control   
  pinMode(5,OUTPUT);   
  pinMode(11,OUTPUT);   
  pinMode(3,OUTPUT); 
  pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);    


pinMode(flamepin1, INPUT);//sensors
pinMode(flamepin2, INPUT);
pinMode(flamepin3, INPUT);

pinMode(12,OUTPUT);//for relay
 
Serial.begin(9600);
myservo.attach(7); //saver motor pin =7

  myservo.write(90); 
 

}
 
void loop() {

int flamesensvalue1=analogRead(flamepin1);
int flamesensvalue2=analogRead(flamepin2);
int flamesensvalue3=analogRead(flamepin3);




Serial.println(flamesensvalue1);
Serial.println(flamesensvalue2);
Serial.println(flamesensvalue3);

boolean sensor1=one(flamesensvalue1);
boolean sensor2=second(flamesensvalue2);
boolean sensor3=third(flamesensvalue3);

boolean buzz1= buzz(flamesensvalue1,flamesensvalue2,flamesensvalue3);

if(buzz1){
    digitalWrite(9 ,LOW);
     digitalWrite(8 ,HIGH);
        }
 else{
    digitalWrite(9,HIGH);
        digitalWrite(8 ,LOW);
    }

 boolean pump= pumpcontrol(flamesensvalue1,flamesensvalue2,flamesensvalue3);

 if(pump||input=='6'){
  over();
    digitalWrite(12 ,HIGH);
 
    for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  
  myservo.write(90);
     
  
  }else{
 if(input=='7'){
  
    digitalWrite(12 ,LOW);
  }
  else{
    
        digitalWrite(12 ,LOW);
    }
    }


Serial.println("------------------------");

Serial.println(sensor1);
Serial.println(sensor2);
Serial.println(sensor3);
Serial.println("------------------------");
Serial.println(buzz1);



  
  if(Serial.available()){
  input= Serial.read();
  Serial.println(input);
  }

  if(input == '1'){
       front();
    }

  else if(input == '2'){
       back();
    }
  else  if(input == '3'){
      right();
    }
  else if(input == '4'){
      left();
    }

   else if(input == '5'){
      over(); 
    }
      delay(100);
  }
 


void front()
  {
  analogWrite(6,100);
  analogWrite(5,0);
  analogWrite(11,100);
  analogWrite(3,0);
  }
 void back()
  {
  analogWrite(6,0);
  analogWrite(5,100);
  analogWrite(11,0);
  analogWrite(3,150);
  } 

  void right()
  {
  analogWrite(6,0);
  analogWrite(5,0);
  analogWrite(11,150);
  analogWrite(3,0);
   }

   void left(){
  analogWrite(6,150);
  analogWrite(5,0);
  analogWrite(11,0);
  analogWrite(3,0);
   } 

    void over()
   {
  analogWrite(6,0);
  analogWrite(5,0);
  analogWrite(11,0);
  analogWrite(3,0);
   }

   boolean one(int i){
  
  if(i<100){
    return true;
    }else{
      return false;
      }
  
  }


  boolean second(int j){
    
    if(j<100){
      return true;
    }else{
      return false;
      }
    }

   boolean third(int g){
       if(g<100){
      return true;
    }else{
      return false;
      }
    
    }
boolean buzz(int first,int second,int third){
  
  if(first<700 || second<700|| third<700){
    return true;
   
  }
  else{
    return false;
    }
  }

 boolean pumpcontrol(int value1,int value2,int value3){
        if(value1<100 || value2<100|| value3<100){
         return true;
   
  }
  else{
    return false;
    }
  
  }

   
