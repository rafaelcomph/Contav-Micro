void Atuadores(double intensity) {
  //Serial.println(intensity);
  if (intensity != 0) {
    lastIntensity = intensity;
  }

  switch (funcao) {

    case 1:
      if (((trava1up && velAtuador1[0]) || (trava2up && velAtuador1[1]) || (trava3up && velAtuador1[2])) && intensity >=0)  {
        atuador1fwd = 0;
        atuador1bwd = 0;
        atuador2fwd = 0;
        atuador2bwd = 0;
        atuador3fwd = 0;
        atuador3bwd = 0;
        digitalWrite(pinLED1, LOW);
        break;
      }
      if (((velAtuador1[0] > 0 && lastIntensity > 0) || (velAtuador1[0] < 0 && lastIntensity < 0))) {
        atuador1fwd = velAtuador1[0] * aceleracao * lastIntensity / 10000;
        atuador1bwd = 0;
        Serial.print("1: FRENTE");
      }
      else if (((velAtuador1[0] < 0 && lastIntensity > 0) || (velAtuador1[0] > 0 && lastIntensity < 0))) {
        atuador1fwd = 0;
        atuador1bwd = abs(velAtuador1[0] * aceleracao * lastIntensity / 10000);
        Serial.print("1: TRAS");
      }
      if (((velAtuador1[1] > 0 && lastIntensity > 0) || (velAtuador1[1] < 0 && lastIntensity < 0))) {
        atuador2fwd = velAtuador1[1] * aceleracao * lastIntensity / 10000;
        atuador2bwd = 0;
        Serial.print("/ 2: FRENTE");
      }
      else if (((velAtuador1[1] < 0 && lastIntensity > 0) || (velAtuador1[1] > 0 && lastIntensity < 0))) {
        atuador2fwd = 0;
        atuador2bwd = abs(velAtuador1[1] * aceleracao * lastIntensity / 10000);

        Serial.print("/ 2: TRAS");
      }
      if ((velAtuador1[2] > 0 && lastIntensity > 0) || (velAtuador1[2] < 0 && lastIntensity < 0)) {
        atuador3fwd = velAtuador1[2] * aceleracao * lastIntensity / 10000;
        atuador3bwd = 0;

        Serial.println("/ 3: FRENTE");
      }
      else if ((velAtuador1[2] < 0 && lastIntensity > 0) || (velAtuador1[2] > 0 && lastIntensity < 0)) {
        atuador3fwd = 0;
        atuador3bwd = abs(velAtuador1[2]) * aceleracao * lastIntensity / 10000;

        Serial.println("/ 3: TRAS");
      }
      break;

    case 2:
      if ((trava1up && velAtuador2[0]) || (trava2up && velAtuador2[1]) || (trava3up && velAtuador2[2])) {
        atuador1fwd = 0;
        atuador1bwd = 0;
        atuador2fwd = 0;
        atuador2bwd = 0;
        atuador3fwd = 0;
        atuador3bwd = 0;
        digitalWrite(pinLED2, LOW);
        break;
      }
      if ((velAtuador2[0] > 0 && lastIntensity > 0) || (velAtuador2[0] < 0 && lastIntensity < 0)) {
        atuador1fwd = velAtuador2[0] * aceleracao * lastIntensity / 10000;
        atuador1bwd = 0;
      }
      else if ((velAtuador2[0] < 0 && lastIntensity > 0) || (velAtuador2[0] > 0 && lastIntensity < 0)) {
        atuador1fwd = 0;
        atuador1bwd = abs(velAtuador2[0] * aceleracao * lastIntensity / 10000);
      }
      if ((velAtuador2[1] > 0 && lastIntensity > 0) || (velAtuador2[1] < 0 && lastIntensity < 0)) {
        atuador2fwd = velAtuador2[1] * aceleracao * lastIntensity / 10000;
        atuador2bwd = 0;
      }
      else if ((velAtuador2[1] < 0 && lastIntensity > 0) || (velAtuador2[1] > 0 && lastIntensity < 0)) {
        atuador2fwd = 0;
        atuador2bwd = abs(velAtuador2[1] * aceleracao * lastIntensity / 10000);
      }
      if ((velAtuador2[2] > 0 && lastIntensity > 0) || (velAtuador2[2] < 0 && lastIntensity < 0)) {
        atuador3fwd = velAtuador2[2] * aceleracao * lastIntensity / 10000;
        atuador3bwd = 0;
      }
      else if ((velAtuador2[2] < 0 && lastIntensity > 0) || (velAtuador2[2] > 0 && lastIntensity < 0)) {
        atuador3fwd = 0;
        atuador3bwd = abs(velAtuador2[2]) * aceleracao * lastIntensity / 10000;
      }
      break;

    case 3:
      if ((trava1up && velAtuador3[0]) || (trava2up && velAtuador3[1]) || (trava3up && velAtuador3[2])) {
        atuador1fwd = 0;
        atuador1bwd = 0;
        atuador2fwd = 0;
        atuador2bwd = 0;
        atuador3fwd = 0;
        atuador3bwd = 0;
        digitalWrite(pinLED3, LOW);
        break;
      }
      if ((velAtuador3[0] > 0 && lastIntensity > 0) || (velAtuador3[0] < 0 && lastIntensity < 0)) {
        atuador1fwd = velAtuador3[0] * aceleracao * lastIntensity / 10000;
        atuador1bwd = 0;
      }
      else if ((velAtuador3[0] < 0 && lastIntensity > 0) || (velAtuador3[0] > 0 && lastIntensity < 0)) {
        atuador1fwd = 0;
        atuador1bwd = abs(velAtuador3[0] * aceleracao * lastIntensity / 10000);
      }
      if ((velAtuador3[1] > 0 && lastIntensity > 0) || (velAtuador3[1] < 0 && lastIntensity < 0)) {
        atuador2fwd = velAtuador3[1] * aceleracao * lastIntensity / 10000;
        atuador2bwd = 0;
      }
      else if ((velAtuador3[1] < 0 && lastIntensity > 0) || (velAtuador3[1] > 0 && lastIntensity < 0)) {
        atuador2fwd = 0;
        atuador2bwd = abs(velAtuador3[1] * aceleracao * lastIntensity / 10000);
      }
      if ((velAtuador3[2] > 0 && lastIntensity > 0) || (velAtuador3[2] < 0 && lastIntensity < 0)) {
        atuador3fwd = velAtuador3[2] * aceleracao * lastIntensity / 10000;
        atuador3bwd = 0;
      }
      else if ((velAtuador3[2] < 0 && lastIntensity > 0) || (velAtuador3[2] > 0 && lastIntensity < 0)) {
        atuador3fwd = 0;
        atuador3bwd = abs(velAtuador3[2]) * aceleracao * lastIntensity / 10000;
      }
      break;

    case 0:
      atuador1fwd = 0;
      atuador1bwd = 0;
      atuador2fwd = 0;
      atuador2bwd = 0;
      atuador3fwd = 0;
      atuador3bwd = 0;
      break;
  }

}
