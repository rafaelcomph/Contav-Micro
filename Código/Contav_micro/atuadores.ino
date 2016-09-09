void Atuadores(double intensity) {
  //Serial.println(intensity);
  if (intensity != 0) {
    lastIntensity = intensity;
  }

  switch (funcao) {

    case 1:

      if (((velAtuador1[0] > 0 && lastIntensity > 0) || (velAtuador1[0] < 0 && lastIntensity < 0))) {
        paraFrente(&atuador1fwd, &atuador1bwd, velAtuador1[0]);
      }
      else if (((velAtuador1[0] < 0 && lastIntensity > 0) || (velAtuador1[0] > 0 && lastIntensity < 0))) {
        paraTras(&atuador1fwd, &atuador1bwd, velAtuador1[0]);
      }
      if (((velAtuador1[1] > 0 && lastIntensity > 0) || (velAtuador1[1] < 0 && lastIntensity < 0))) {
        paraFrente(&atuador2fwd, &atuador2bwd, velAtuador1[1]);
      }
      else if (((velAtuador1[1] < 0 && lastIntensity > 0) || (velAtuador1[1] > 0 && lastIntensity < 0))) {
        paraTras(&atuador2fwd, &atuador2bwd, velAtuador1[1]);
      }
      if ((velAtuador1[2] > 0 && lastIntensity > 0) || (velAtuador1[2] < 0 && lastIntensity < 0)) {
        paraFrente(&atuador3fwd, &atuador3bwd, velAtuador1[2]);
      }
      else if ((velAtuador1[2] < 0 && lastIntensity > 0) || (velAtuador1[2] > 0 && lastIntensity < 0)) {
        paraTras(&atuador3fwd, &atuador3bwd, velAtuador1[2]);
      }
      break;

    case 2:
      
      if ((velAtuador2[0] > 0 && lastIntensity > 0) || (velAtuador2[0] < 0 && lastIntensity < 0)) {
        paraFrente(&atuador1fwd, &atuador1bwd, velAtuador2[0]); 
      }
      else if ((velAtuador2[0] < 0 && lastIntensity > 0) || (velAtuador2[0] > 0 && lastIntensity < 0)) {
        paraTras(&atuador1fwd, &atuador1bwd, velAtuador2[0]);
      }
      if ((velAtuador2[1] > 0 && lastIntensity > 0) || (velAtuador2[1] < 0 && lastIntensity < 0)) {
        paraFrente(&atuador2fwd, &atuador2bwd, velAtuador2[1]); 
      }
      else if ((velAtuador2[1] < 0 && lastIntensity > 0) || (velAtuador2[1] > 0 && lastIntensity < 0)) {
        paraTras(&atuador2fwd, &atuador2bwd, velAtuador2[1]);
      }
      if ((velAtuador2[2] > 0 && lastIntensity > 0) || (velAtuador2[2] < 0 && lastIntensity < 0)) {
        paraFrente(&atuador3fwd, &atuador3bwd, velAtuador2[2]); 
      }
      else if ((velAtuador2[2] < 0 && lastIntensity > 0) || (velAtuador2[2] > 0 && lastIntensity < 0)) {
        paraTras(&atuador3fwd, &atuador3bwd, velAtuador2[2]);
      }
      break;

    case 3:
      
      if ((velAtuador3[0] > 0 && lastIntensity > 0) || (velAtuador3[0] < 0 && lastIntensity < 0)) {
        paraFrente(&atuador1fwd, &atuador1bwd, velAtuador3[0]); 
      }
      else if ((velAtuador3[0] < 0 && lastIntensity > 0) || (velAtuador3[0] > 0 && lastIntensity < 0)) {
        paraTras(&atuador1fwd, &atuador1bwd, velAtuador3[0]);
      }
      if ((velAtuador3[1] > 0 && lastIntensity > 0) || (velAtuador3[1] < 0 && lastIntensity < 0)) {
        paraFrente(&atuador2fwd, &atuador2bwd, velAtuador3[1]); 
      }
      else if ((velAtuador3[1] < 0 && lastIntensity > 0) || (velAtuador3[1] > 0 && lastIntensity < 0)) {
        paraTras(&atuador2fwd, &atuador2bwd, velAtuador3[1]);
      }
      if ((velAtuador3[2] > 0 && lastIntensity > 0) || (velAtuador3[2] < 0 && lastIntensity < 0)) {
        paraFrente(&atuador3fwd, &atuador3bwd, velAtuador3[2]); 
      }
      else if ((velAtuador3[2] < 0 && lastIntensity > 0) || (velAtuador3[2] > 0 && lastIntensity < 0)) {
        paraTras(&atuador3fwd, &atuador3bwd, velAtuador3[2]);
      }
      break;

    case 0:
      parou();
      break;
  }

}

void parou() {
  atuador1fwd = 0;
  atuador1bwd = 0;
  atuador2fwd = 0;
  atuador2bwd = 0;
  atuador3fwd = 0;
  atuador3bwd = 0;

}

void parou(int led) {
  atuador1fwd = 0;
  atuador1bwd = 0;
  atuador2fwd = 0;
  atuador2bwd = 0;
  atuador3fwd = 0;
  atuador3bwd = 0;
  digitalWrite(led, LOW);

}


void paraFrente(volatile uint16_t  *pinFwd, volatile uint16_t  *pinBwd, int velocidade){
  *pinFwd = byte(velocidade * aceleracao * lastIntensity / 10000);
  *pinBwd = 0;
}

void paraTras(volatile uint16_t  *pinFwd, volatile uint16_t  *pinBwd, int velocidade){
  *pinFwd = 0;
  *pinBwd = byte(abs(velocidade * aceleracao * lastIntensity / 10000));;
}

void paraFrente(volatile uint8_t  *pinFwd, volatile uint16_t  *pinBwd, int velocidade){
  *pinFwd = byte(velocidade * aceleracao * lastIntensity / 10000);
  *pinBwd = 0;
}

void paraTras(volatile uint8_t  *pinFwd, volatile uint16_t  *pinBwd, int velocidade){
  *pinFwd = 0;
  *pinBwd = byte(abs(velocidade * aceleracao * lastIntensity / 10000));;
}

/*

void paraFrente(int atuador, int velocidade){
  switch(atuador){ 
    case 1:
        atuador1fwd = velocidade * aceleracao * lastIntensity / 10000;
        atuador1bwd = 0;
        break;
    case 2:
        atuador2fwd = velocidade * aceleracao * lastIntensity / 10000;
        atuador2bwd = 0;
        break;
    case 3:
        atuador3fwd = velocidade * aceleracao * lastIntensity / 10000;
        atuador3bwd = 0;
        break;
  }
}

void paraTras(int atuador, int velocidade){
  switch(atuador){ 
    case 1:
        atuador1fwd = 0;
        atuador1bwd = abs(velocidade * aceleracao * lastIntensity / 10000);
        break;
    case 2:
        atuador2fwd = 0;
        atuador2bwd = abs(velocidade * aceleracao * lastIntensity / 10000);
        break;
    case 3:
        atuador3fwd = 0;
        atuador3bwd = abs(velocidade * aceleracao * lastIntensity / 10000);
        break;
  }
}
*/
