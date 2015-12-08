#include <arduino.h>
#include "switchDebounce.h"

#define pinLED1 14
#define pinLED2 16
#define pinLED3 15
#define pinBotaoUp A1
#define pinBotaoDown A2
#define pinBotaoFuncao A0

#define pinInibidor1  12
#define pinInibidor2  8
#define pinInibidor3  A4

#define pinAtuador1up  6
#define pinAtuador1down  5
#define pinAtuador2up  10
#define pinAtuador2down  9
#define pinAtuador3up  13 
#define pinAtuador3down  11

switchDebounce *swdBotaoUp, *swdBotaoDown,  *swdBotaoFuncao;
switchDebounce *swdInibidor1, *swdInibidor2,  *swdInibidor3;

void setup() {
  
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinAtuador1up, OUTPUT);
  pinMode(pinAtuador1down, OUTPUT);
  pinMode(pinAtuador2up, OUTPUT);
  pinMode(pinAtuador2down, OUTPUT);
  pinMode(pinAtuador3up, OUTPUT);
  pinMode(pinAtuador3down, OUTPUT);
  
  swdBotaoUp = new switchDebounce(pinBotaoUp);
  swdBotaoDown = new switchDebounce(pinBotaoDown);
  swdBotaoFuncao = new switchDebounce(pinBotaoFuncao);
  swdInibidor1 = new switchDebounce(pinInibidor1);
  swdInibidor2 = new switchDebounce(pinInibidor2);
  swdInibidor3 = new switchDebounce(pinInibidor3);
  
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
  
}


unsigned long tempoBotao = 0;
unsigned long tempoBlink = 0;
boolean ledBlink = false;
int funcao = 0;
boolean auto_tilt = false;


void loop() {
  Serial.begin(9600);
  swdBotaoFuncao->refresh(pinBotaoFuncao);
  swdBotaoUp->refresh(pinBotaoUp);
  swdBotaoDown->refresh(pinBotaoDown);
  swdInibidor1->refresh(pinInibidor1);
  swdInibidor2->refresh(pinInibidor2);
  swdInibidor3->refresh(pinInibidor3);
  
  if(!swdBotaoFuncao->state){    
    tempoBotao = millis();
    while(!swdBotaoFuncao->state){
      swdBotaoFuncao->refresh(pinBotaoFuncao);
      digitalWrite(pinLED1, LOW);
      digitalWrite(pinLED2, LOW);
      digitalWrite(pinLED3, LOW);
    }  
    funcao++;
    if(funcao > 3)  funcao = 0;
    if(millis()-tempoBotao > 2000) auto_tilt = !auto_tilt;
  }
  
  if(millis()-tempoBotao > 5000) funcao = 0;
  
  if(!auto_tilt){
    switch (funcao){
      case 1:
        digitalWrite(pinLED1, HIGH);
        digitalWrite(pinLED2, LOW);
        digitalWrite(pinLED3, LOW);
        break;
        
      case 2:
        digitalWrite(pinLED1, LOW);
        digitalWrite(pinLED2, HIGH);
        digitalWrite(pinLED3, LOW);
        break;
        
      case 3:
        digitalWrite(pinLED1, LOW);
        digitalWrite(pinLED2, LOW);
        digitalWrite(pinLED3, HIGH);
        break;
        
      case 0:
        digitalWrite(pinLED1, LOW);
        digitalWrite(pinLED2, LOW);
        digitalWrite(pinLED3, LOW);
        break;
    }
  }
  else{
    if(millis() - tempoBlink > 50 ){
      tempoBlink = millis();
      ledBlink = !ledBlink;
      digitalWrite(pinLED1, ledBlink);
      digitalWrite(pinLED2, LOW);
      digitalWrite(pinLED3, LOW);
    }  
   funcao = 4; 
  }
  
  if(!swdBotaoUp->state){
    tempoBotao = millis();
    switch (funcao){
      case 1:
        analogWrite(pinAtuador1up, 127);
        digitalWrite(pinAtuador1down, LOW);
        digitalWrite(pinAtuador2up, LOW);
        digitalWrite(pinAtuador2down, LOW);
        digitalWrite(pinAtuador3up, LOW);
        digitalWrite(pinAtuador3down, LOW);
        break;
        
      case 2:
        analogWrite(pinAtuador2up, 128);
        digitalWrite(pinAtuador2down, LOW);
        digitalWrite(pinAtuador1up, LOW);
        digitalWrite(pinAtuador1down, LOW);
        digitalWrite(pinAtuador3up, LOW);
        digitalWrite(pinAtuador3down, LOW);
        break;
        
      case 3:
        analogWrite(pinAtuador3up, 128);
        digitalWrite(pinAtuador3down, LOW);
        digitalWrite(pinAtuador1up, LOW);
        digitalWrite(pinAtuador1down, LOW);
        digitalWrite(pinAtuador2up, LOW);
        digitalWrite(pinAtuador2down, LOW);
        break;
        
      case 0:
        funcao = 1;
        break;
    }
  } 
  
  if(!swdBotaoDown->state){
    tempoBotao = millis();
    switch (funcao){
      case 1:
        digitalWrite(pinAtuador1up, LOW);
        analogWrite(pinAtuador1down, 128);
        digitalWrite(pinAtuador2up, LOW);
        digitalWrite(pinAtuador2down, LOW);
        digitalWrite(pinAtuador3up, LOW);
        digitalWrite(pinAtuador3down, LOW);
        break;
        
      case 2:
        digitalWrite(pinAtuador2up, LOW);
        analogWrite(pinAtuador2down, 128);
        digitalWrite(pinAtuador1up, LOW);
        digitalWrite(pinAtuador1down, LOW);
        digitalWrite(pinAtuador3up, LOW);
        digitalWrite(pinAtuador3down, LOW);
        break;
        
      case 3:
        digitalWrite(pinAtuador3up, LOW);
        analogWrite(pinAtuador3down, 128);
        digitalWrite(pinAtuador1up, LOW);
        digitalWrite(pinAtuador1down, LOW);
        digitalWrite(pinAtuador2up, LOW);
        digitalWrite(pinAtuador2down, LOW);
        break;
        
      case 0:
        funcao = 1;
        break;
    }
  }
 
 if(swdBotaoUp->state && swdBotaoDown->state){
   digitalWrite(pinAtuador1up, LOW);
   digitalWrite(pinAtuador1down, LOW);
   digitalWrite(pinAtuador2up, LOW);
   digitalWrite(pinAtuador2down, LOW);
   digitalWrite(pinAtuador3up, LOW);
   digitalWrite(pinAtuador3down, LOW);
 }
  
}
