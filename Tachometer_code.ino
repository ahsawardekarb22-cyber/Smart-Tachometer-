// .............Smart Tachometer For All.............. // 
//              """"""""""""""""""""""""               // 
 
// 16 X 2 LCD.............. 
#include <LCD_I2C.h> 
LCD_I2C lcd(0x27, 16, 2); 
 
// TM1637................ 
#include "TM1637.h" 
#define CLK 3 // pin 3 
#define DIO 2 // pin 2 
TM1637 tm1637(CLK,DIO); 
 
// INPUT switches Table selection....... 
int T1 = 4;  // motor on table 1 
int T2 = 5;  // motor on table 2 
int T3 = 6;  // motor on table 3 
int pause = 7; // freeze readings 
 
int ir = 10; // IR sensor input 
 
// Indicators......... 
#define Stby  A0;  
#define Run  A1;  
 
// Transmitter selectors......... 
#define Tx1 11; 
 
 
#define Tx2 12; 
#define Tx3 13; 
 
// Varaibles for RPM measurement 
int state=0; 
int rev=0; 
unsigned long z=0; 
int rpm=0; 
 
void setup()  
{ 
 lcd.begin();  
 lcd.backlight(); 
 tm1637.init(); 
 tm1637.set(5); 
 delay(1500); 
 pinMode(T1,INPUT); 
 pinMode(T2,INPUT); 
 pinMode(T3,INPUT); 
 pinMode(next,INPUT); 
 pinMode(ir,INPUT); 
 pinMode(Stby,OUTPUT); 
 pinMode(Run,OUTPUT); 
 pinMode(ir,INPUT); 
 pinMode(pause,INPUT_PULLUP); 
  
 for (int i=0;i<3;i++) 
 { 
   lcd.setCursor(0,0); 
   lcd.print("Loading data."); 
 
 
   delay(500); 
   lcd.print("Loading data.."); 
   delay(500); 
   lcd.print("Loading data..."); 
   delay(500); 
 } 
 lcd.clear(); 
 for (int j=0;j<1;j++) 
 { 
  lcd.setCursor(0,0); 
  lcd.print("Select Table No."); 
  lcd.setCursor(0,1); 
  lcd.print("to measure speed"); 
  if (digitalRead(T1==HIGH) 
  { 
    Table_1(); 
    delay(1000); 
  } 
  else if (digitalRead(T2==HIGH) 
  { 
    Table_2(); 
    delay(1000); 
  } 
  else if (digitalRead(T3==HIGH) 
  { 
    Table_3(); 
    delay(1000); 
  } 
  else  
  { 
 
 
    j = 0; 
  } 
 } 
} 
 
// Interrupt Service Routine........ 
void Table_1() 
{ 
  digitalWrite(Tx1,HIGH); 
  digitalWrite(Tx2,LOW); 
  digitalWrite(Tx3,LOW); 
} 
void Table_2() 
{ 
  digitalWrite(Tx2,HIGH); 
  digitalWrite(Tx1,LOW); 
  digitalWrite(Tx3,LOW); 
} 
void Table_3() 
{ 
  digitalWrite(Tx3,HIGH); 
  digitalWrite(Tx2,LOW); 
  digitalWrite(Tx1,LOW); 
} 
 
void loop() 
{ 
    
if(digitalRead(ir)==LOW && state==0) 
{ 
 
 
    rev=rev+1; 
    state=1; 
} 
if(digitalRead(ir)==HIGH) 
{ 
  state=0;  
} 
if((millis()-z)>=1000 && digitalRead(pause)==LOW) 
{ 
  z=millis(); 
  rpm=rev*60; 
     
 lcd.clear(); 
 lcd.setCursor(0,0); 
 lcd.print("__TACHOMETER__"); 
 lcd.setCursor(0,1); 
 lcd.print(rpm); 
 lcd.print(" RPM "); 
 lcd.print(rev); 
 lcd.print(" Hz"); 
 
rev=0; 
} 
} 