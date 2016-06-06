#include <arduino.h>
#include "switchDebounce.h"

#define atuador1fwd  OCR1B
#define atuador1bwd  OCR1A
#define atuador2fwd  OCR4D
#define atuador2bwd  OCR3A
#define atuador3fwd  OCR4A
#define atuador3bwd  OCR1C

#define pinLED1 MISO
#define pinLED2 SCK
#define pinLED3  A5

#define pinBotaoUp A3
#define pinBotaoDown A2
#define pinBotaoFuncao A4

#define pinInibidor1  12
#define pinInibidor2  8
#define pinInibidor3  4

#define pinAtuador1fwd  10
#define pinAtuador1bwd  9
#define pinAtuador2fwd  6
#define pinAtuador2bwd  5
#define pinAtuador3fwd  13 
#define pinAtuador3bwd  11

switchDebounce *swdBotaoUp, *swdBotaoDown,  *swdBotaoFuncao;
switchDebounce *swdInibidor1, *swdInibidor2,  *swdInibidor3;

void setup() {
  TCCR1A = 0xA9;
  TCCR3A = 0xA9;
  TCCR4A = 0x53;
  
  TCCR1B = 1;
  TCCR3B = 1; 
  TCCR4B = 1;
  
  TCCR4C = 0xAB;
   
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinAtuador1fwd, OUTPUT);
  pinMode(pinAtuador1bwd, OUTPUT);
  pinMode(pinAtuador2fwd, OUTPUT);
  pinMode(pinAtuador2bwd, OUTPUT);
  pinMode(pinAtuador3fwd, OUTPUT);
  pinMode(pinAtuador3bwd, OUTPUT);
  
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
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          funcao = 0;
          break;
        }
        atuador1fwd = velAtuador1[0];
        atuador1bwd = 0;
        atuador2fwd = velAtuador1[1];
        atuador2bwd = 0;
        atuador3fwd = velAtuador1[2];
        atuador2bwd = 0;
        break;
        
      case 2:
        if((trava1up && velAtuador2[0]) || (trava2up && velAtuador2[1]) || (trava3up && velAtuador2[2])){
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          funcao = 0;
          break;
        }
        atuador1fwd = velAtuador2[0];
        atuador1bwd = 0;
        atuador2fwd = velAtuador2[1];
        atuador2bwd = 0;
        atuador3fwd = velAtuador2[2];
        atuador2bwd = 0;
        break;
        
      case 3:
        if((trava1up && velAtuador3[0]) || (trava2up && velAtuador3[1]) || (trava3up && velAtuador3[2])){
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          funcao = 0;
          break;
        }
        atuador1fwd = velAtuador3[0];
        atuador1bwd = 0;
        atuador2fwd = velAtuador3[1];
        atuador2bwd = 0;
        atuador3fwd = velAtuador3[2];
        atuador2bwd = 0;
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
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          funcao = 0;
          break;
        }
        atuador1fwd = 0;
        atuador1bwd = velAtuador1[0];
        atuador2fwd = 0;
        atuador2bwd = velAtuador1[1];
        atuador3fwd = 0;
        atuador3bwd = velAtuador1[2];
        break;
        
      case 2:
        if((trava1down && velAtuador2[0]) || (trava2down && velAtuador2[1]) || (trava3down && velAtuador2[2])){
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          funcao = 0;
          break;
        }
        atuador1fwd = 0;
        atuador1bwd = velAtuador2[0];
        atuador2fwd = 0;
        atuador2bwd = velAtuador2[1];
        atuador3fwd = 0;
        atuador3bwd = velAtuador2[2];
        break;
        
      case 3:
        if((trava1down && velAtuador3[0]) || (trava2down && velAtuador3[1]) || (trava3down && velAtuador3[2])){
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          funcao = 0;
          break;
        }
        atuador1fwd = 0;
        atuador1bwd = velAtuador3[0];
        atuador2fwd = 0;
        atuador2bwd = velAtuador3[1];
        atuador3fwd = 0;
        atuador3bwd = velAtuador3[2];
        break;
        
      case 0:
        funcao = 1;
        break;
    }
  }
 
 if((swdBotaoUp->state && swdBotaoDown->state) || (!swdBotaoUp->state && !swdBotaoDown->state)){
   atuador1fwd = 0;
   atuador1bwd = 0;
   atuador2fwd = 0;
   atuador2bwd = 0;
   atuador3fwd = 0;
   atuador3bwd = 0;
 }
  
}
