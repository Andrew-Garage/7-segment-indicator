#include "GyverTimers.h"
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define DP A2
#define D1 12
#define D2 11 
#define D3 10
#define D4 9
char digit[] = {D1,D2,D3,D4};
char num[] = {A,B,C,D,E,F,G};
int x = 0;
int show_sec = 0;
int show_min = 0;
int delay_time = 6;
bool dot = false;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);  
  digitalWrite(D3, HIGH);  
  digitalWrite(D4, HIGH);
  Serial.begin(9600);

  Timer1.setFrequencyFloat(1);
  Timer1.enableISR(CHANNEL_B);
}

ISR(TIMER1_B){
  show_sec++;
  dot = !dot;
}



void loop() {
  digitalWrite(digit[3], LOW);
  number(show_sec%10);
  digitalWrite(DP, LOW);
  delay(delay_time);
  digitalWrite(digit[3], HIGH);

  digitalWrite(digit[2], LOW);
  number((show_sec/10)%10);
  digitalWrite(DP, LOW);
  delay(delay_time);
  digitalWrite(digit[2], HIGH);

  digitalWrite(digit[1], LOW);
  number(show_min%10);
  if(dot == true)digitalWrite(DP, HIGH);
  delay(delay_time);
  digitalWrite(digit[1], HIGH);
  if(dot == true)digitalWrite(DP, LOW);

  digitalWrite(digit[0], LOW);
  number((show_min/10)%10);
  digitalWrite(DP, LOW);
  delay(delay_time);
  digitalWrite(digit[0], HIGH);
  x++;
  if(x >= 4){x = 0;}
  if(show_sec >= 60){
    show_min++;
    show_sec = 0;}
}

void number(int var){
  switch(var){
case 0:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  break;

case 1:
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  break;
  
case 2:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  break;

case 3:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  break;

case 4:
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;

case 5:
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;
  
case 6:
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;

case 7:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  break;

case 8:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;

case 9:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  break;
}

}

  void test(char x){
  digitalWrite(x, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, HIGH);}
