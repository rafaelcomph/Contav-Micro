#include <arduino.h>
#include "switchDebounce.h"

#define pinLED1 MISO
#define pinLED2 SCK
#define pinLED3  A5

#define pinBotaoUp A3
#define pinBotaoDown A2
#define pinBotaoFuncao A4

#define pinInibidor1  12
#define pinInibidor2  8
#define pinInibidor3  4

#define pinAtuador1up  10
#define pinAtuador1down  9
#define pinAtuador2up  6
#define pinAtuador2down  5
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
boolean trava1up = false, trava1down = false;
boolean trava2up = false, trava2down = false;
boolean trava3up = false, trava3down = false;

int velAtuador1[3] = {127, 0, 0};
int velAtuador2[3] = {0, 127, 0};
int velAtuador3[3] = {0, 0, 127};

unsigned long tempoBotao = 0;
unsigned long tempoBlink = 0;
boolean ledBlink = false;
int funcao = 0;
boolean auto_tilt = false;
char c;

void loop() {
  
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
  
  if(millis()-tempoBotao > 3000) funcao = 0;
  
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
    if(millis() - tempoBlink > 100 ){
      tempoBlink = millis();
      ledBlink = !ledBlink;
      digitalWrite(pinLED1, ledBlink);
      digitalWrite(pinLED2, LOW);
      digitalWrite(pinLED3, LOW);
    }  
   funcao = 4; 
  }
  
  inibidores();
  
  
  if(!swdBotaoUp->state && swdBotaoDown->state){
    tempoBotao = millis();
    switch (funcao){
      case 1:
        if((trava1up && velAtuador1[0]) || (trava2up && velAtuador1[1]) || (trava3up && velAtuador1[2])){
          digitalWrite(pinAtuador1up, LOW);
          digitalWrite(pinAtuador1down, LOW);
          digitalWrite(pinAtuador2up, LOW);
          digitalWrite(pinAtuador2down, LOW);
          digitalWrite(pinAtuador3up, LOW);
          digitalWrite(pinAtuador3down, LOW);
          funcao = 0;
          break;
        }
        analogWrite(pinAtuador1up, velAtuador1[0]);
        digitalWrite(pinAtuador1down, LOW);
        analogWrite(pinAtuador2up, velAtuador1[1]);
        digitalWrite(pinAtuador2down, LOW);
        analogWrite(pinAtuador3up, velAtuador1[2]);
        digitalWrite(pinAtuador3down, LOW);
        break;
        
      case 2:
        if((trava1up && velAtuador2[0]) || (trava2up && velAtuador2[1]) || (trava3up && velAtuador2[2])){
          digitalWrite(pinAtuador1up, LOW);
          digitalWrite(pinAtuador1down, LOW);
          digitalWrite(pinAtuador2up, LOW);
          digitalWrite(pinAtuador2down, LOW);
          digitalWrite(pinAtuador3up, LOW);
          digitalWrite(pinAtuador3down, LOW);
          funcao = 0;
          break;
        }
        analogWrite(pinAtuador1up, velAtuador2[0]);
        digitalWrite(pinAtuador1down, LOW);
        analogWrite(pinAtuador2up, velAtuador2[1]);
        digitalWrite(pinAtuador2down, LOW);
        analogWrite(pinAtuador3up, velAtuador2[2]);
        digitalWrite(pinAtuador3down, LOW);
        break;
        
      case 3:
        if((trava1up && velAtuador3[0]) || (trava2up && velAtuador3[1]) || (trava3up && velAtuador3[2])){
          digitalWrite(pinAtuador1up, LOW);
          digitalWrite(pinAtuador1down, LOW);
          digitalWrite(pinAtuador2up, LOW);
          digitalWrite(pinAtuador2down, LOW);
          digitalWrite(pinAtuador3up, LOW);
          digitalWrite(pinAtuador3down, LOW);
          funcao = 0;
          break;
        }
        analogWrite(pinAtuador1up, velAtuador3[0]);
        digitalWrite(pinAtuador1down, LOW);
        analogWrite(pinAtuador2up, velAtuador3[1]);
        digitalWrite(pinAtuador2down, LOW);
        analogWrite(pinAtuador3up, velAtuador3[2]);
        digitalWrite(pinAtuador3down, LOW);
        break;
        
      case 0:
        funcao = 1;
        break;
    }
  } 
  
  if(!swdBotaoDown->state && swdBotaoUp->state){
    tempoBotao = millis();
    switch (funcao){
      case 1:
        if((trava1down && velAtuador1[0]) || (trava2down && velAtuador1[1]) || (trava3down && velAtuador1[2])){
          digitalWrite(pinAtuador1up, LOW);
          digitalWrite(pinAtuador1down, LOW);
          digitalWrite(pinAtuador2up, LOW);
          digitalWrite(pinAtuador2down, LOW);
          digitalWrite(pinAtuador3up, LOW);
          digitalWrite(pinAtuador3down, LOW);
          funcao = 0;
          break;
        }
        digitalWrite(pinAtuador1up, LOW);
        analogWrite(pinAtuador1down, velAtuador1[0]);
        digitalWrite(pinAtuador2up, LOW);
        analogWrite(pinAtuador2down, velAtuador1[1]);
        digitalWrite(pinAtuador3up, LOW);
        analogWrite(pinAtuador3down, velAtuador1[2]);
        break;
        
      case 2:
        if((trava1down && velAtuador2[0]) || (trava2down && velAtuador2[1]) || (trava3down && velAtuador2[2])){
          digitalWrite(pinAtuador1up, LOW);
          digitalWrite(pinAtuador1down, LOW);
          digitalWrite(pinAtuador2up, LOW);
          digitalWrite(pinAtuador2down, LOW);
          digitalWrite(pinAtuador3up, LOW);
          digitalWrite(pinAtuador3down, LOW);
          funcao = 0;
          break;
        }
        digitalWrite(pinAtuador1up, LOW);
        analogWrite(pinAtuador1down, velAtuador2[0]);
        digitalWrite(pinAtuador2up, LOW);
        analogWrite(pinAtuador2down, velAtuador2[1]);
        digitalWrite(pinAtuador3up, LOW);
        analogWrite(pinAtuador3down, velAtuador2[2]);
        break;
        
      case 3:
        if((trava1down && velAtuador3[0]) || (trava2down && velAtuador3[1]) || (trava3down && velAtuador3[2])){
          digitalWrite(pinAtuador1up, LOW);
          digitalWrite(pinAtuador1down, LOW);
          digitalWrite(pinAtuador2up, LOW);
          digitalWrite(pinAtuador2down, LOW);
          digitalWrite(pinAtuador3up, LOW);
          digitalWrite(pinAtuador3down, LOW);
          funcao = 0;
          break;
        }
        digitalWrite(pinAtuador1up, LOW);
        analogWrite(pinAtuador1down, velAtuador3[0]);
        digitalWrite(pinAtuador2up, LOW);
        analogWrite(pinAtuador2down, velAtuador3[1]);
        digitalWrite(pinAtuador3up, LOW);
        analogWrite(pinAtuador3down, velAtuador3[2]);
        break;
        
      case 0:
        funcao = 1;
        break;
    }
  }
 
 if((swdBotaoUp->state && swdBotaoDown->state) || (!swdBotaoUp->state && !swdBotaoDown->state)){
   digitalWrite(pinAtuador1up, LOW);
   digitalWrite(pinAtuador1down, LOW);
   digitalWrite(pinAtuador2up, LOW);
   digitalWrite(pinAtuador2down, LOW);
   digitalWrite(pinAtuador3up, LOW);
   digitalWrite(pinAtuador3down, LOW);
 }
  
}
