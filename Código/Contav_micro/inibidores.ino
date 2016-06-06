void inibidores(){ 
  if(swdBotaoUp->state && !swdInibidor1->state && swdBotaoDown->state && !trava1up && !trava1down){
    trava1up = HIGH;
    trava1down = HIGH;
  }
  if(!swdBotaoUp->state && !swdInibidor1->state && !trava1down){
    trava1up = HIGH;
  }
  if(!swdBotaoDown->state && !swdInibidor1->state && !trava1up){
    trava1down = HIGH;
  }  
  if(swdInibidor1->state){
    trava1up = LOW;
    trava1down = LOW;
  }
  
  if(swdBotaoUp->state && !swdInibidor2->state && swdBotaoDown->state && !trava2up && !trava2down){
    trava2up = HIGH;
    trava2down = HIGH;
  }
  if(!swdBotaoUp->state && !swdInibidor2->state && !trava2down){
    trava2up = HIGH;
  }
  if(!swdBotaoDown->state && !swdInibidor2->state && !trava2up){
    trava2down = HIGH;
  }  
  if(swdInibidor2->state){
    trava2up = LOW;
    trava2down = LOW;
  }
  
  if(swdBotaoUp->state && !swdInibidor3->state && swdBotaoDown->state && !trava3up && !trava3down){
    trava3up = HIGH;
    trava3down = HIGH;
  }
  if(!swdBotaoUp->state && !swdInibidor3->state && !trava3down){
    trava3up = HIGH;
  }
  if(!swdBotaoDown->state && !swdInibidor3->state && !trava3up){
    trava3down = HIGH;
  }  
  if(swdInibidor3->state){
    trava3up = LOW;
    trava3down = LOW;
  }
  
}

