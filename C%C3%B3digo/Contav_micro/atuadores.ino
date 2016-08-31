void Atuadores(double intensity) {
  //Serial.println(intensity);


  if (intensity > 0) { //botão de cima acionado
    tempoBotao = millis();
    lastIntensity = intensity;
    switch (funcao) {
      case 1:
        if ((trava1up && velAtuador1[0]) || (trava2up && velAtuador1[1]) || (trava3up && velAtuador1[2])) {
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          //funcao = 0;
          digitalWrite(pinLED1, LOW);
          break;
        }
        digitalWrite(pinLED1, HIGH);
        if (velAtuador1[0] > 0) {
          atuador1fwd = velAtuador1[0] * aceleracao * intensity / 10000;
          atuador1bwd = 0;
          //Serial.println(velAtuador1[0] * aceleracao * intensity / 10000);

        }
        else {
          atuador1fwd = 0;
          atuador1bwd = abs(velAtuador1[0] * aceleracao * intensity / 10000);
        }
        if (velAtuador1[1] > 0) {
          atuador2fwd = velAtuador1[1] * aceleracao * intensity / 10000;
          atuador2bwd = 0;
        }
        else {
          atuador2fwd = 0;
          atuador2bwd = abs(velAtuador1[1] * aceleracao * intensity / 10000);
        }
        if (velAtuador1[2] > 0) {
          atuador3fwd = velAtuador1[2] * aceleracao * intensity / 10000;
          atuador3bwd = 0;
        }
        else {
          atuador3fwd = 0;
          atuador3bwd = abs(velAtuador1[2]) * aceleracao * intensity / 10000;
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
          //funcao = 0;
          digitalWrite(pinLED2, LOW);
          break;
        }
        digitalWrite(pinLED2, HIGH);
        if (velAtuador2[0] > 0) {
          atuador1fwd = velAtuador2[0] * aceleracao * intensity / 10000;
          atuador1bwd = 0;
        }
        else {
          atuador1fwd = 0;
          atuador1bwd = abs(velAtuador2[0] * aceleracao * intensity / 10000);
        }
        if (velAtuador2[1] > 0) {
          atuador2fwd = velAtuador2[1] * aceleracao * intensity / 10000;
          atuador2bwd = 0;
        }
        else {
          atuador2fwd = 0;
          atuador2bwd = abs(velAtuador2[1] * aceleracao * intensity / 10000);
        }
        if (velAtuador2[2] > 0) {
          atuador3fwd = velAtuador2[2] * aceleracao * intensity / 10000;
          atuador3bwd = 0;
        }
        else {
          atuador3fwd = 0;
          atuador3bwd = abs(velAtuador2[2] * aceleracao * intensity / 10000);
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
          //funcao = 0;
          digitalWrite(pinLED3, LOW);
          break;
        }
        digitalWrite(pinLED3, HIGH);
        if (velAtuador3[0] > 0) {
          atuador1fwd = velAtuador3[0] * aceleracao * intensity / 10000;
          atuador1bwd = 0;
        }
        else {
          atuador1fwd = 0;
          atuador1bwd = abs(velAtuador3[0] * aceleracao * intensity / 10000);
        }
        if (velAtuador3[1] > 0) {
          atuador2fwd = velAtuador3[1] * aceleracao * intensity / 10000;
          atuador2bwd = 0;
        }
        else {
          atuador2fwd = 0;
          atuador2bwd = abs(velAtuador3[1] * aceleracao * intensity / 10000);
        }
        if (velAtuador3[2] > 0) {
          atuador3fwd = velAtuador3[2] * aceleracao * intensity / 10000;
          atuador3bwd = 0;
        }
        else {
          atuador3fwd = 0;
          atuador3bwd = abs(velAtuador3[2] * aceleracao * intensity / 10000);
        }
        break;

      case 0:
        funcao = 1;
        digitalWrite(pinLED1, LOW);
        digitalWrite(pinLED2, LOW);
        digitalWrite(pinLED3, LOW);
        break;
    }
  }

  else if (intensity < 0) { // Pro botão de baixo
    tempoBotao = millis();
    lastIntensity = intensity;
    switch (funcao) {
      case 1:
        if ((trava1down && velAtuador1[0]) || (trava2down && velAtuador1[1]) || (trava3down && velAtuador1[2])) {
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          //funcao = 0;
          digitalWrite(pinLED1, LOW);
          break;
        }
        digitalWrite(pinLED1, HIGH);
        if (velAtuador1[0] > 0) {
          atuador1fwd = 0;
          atuador1bwd = velAtuador1[0] * aceleracao * intensity / 10000;
        }
        else {
          atuador1fwd = abs(velAtuador1[0] * aceleracao * intensity / 10000);
          atuador1bwd = 0;
        }
        if (velAtuador1[1] > 0) {
          atuador2fwd = 0;
          atuador2bwd = velAtuador1[1] * aceleracao * intensity / 10000;
        }
        else {
          atuador2fwd = abs(velAtuador1[1]) * aceleracao * intensity / 10000;
          atuador2bwd = 0;
        }
        if (velAtuador1[2] > 0) {
          atuador3fwd = 0;
          atuador3bwd = velAtuador1[2] * aceleracao * intensity / 10000;
        }
        else {
          atuador3fwd = abs(velAtuador1[2] * aceleracao * intensity / 10000);
          atuador3bwd = 0;
        }
        break;

      case 2:
        if ((trava1down && velAtuador2[0]) || (trava2down && velAtuador2[1]) || (trava3down && velAtuador2[2])) {
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          //funcao = 0;
          digitalWrite(pinLED2, LOW);
          break;
        }
        digitalWrite(pinLED2, HIGH);
        if (velAtuador2[0] > 0) {
          atuador1fwd = 0;
          atuador1bwd = velAtuador2[0] * aceleracao * intensity / 10000;
        }
        else {
          atuador1fwd = abs(velAtuador2[0] * aceleracao * intensity / 10000);
          atuador1bwd = 0;
        }
        if (velAtuador2[1] > 0) {
          atuador2fwd = 0;
          atuador2bwd = velAtuador2[1] * aceleracao * intensity / 10000;
        }
        else {
          atuador2fwd = abs(velAtuador2[1] * aceleracao * intensity / 10000);
          atuador2bwd = 0;
        }
        if (velAtuador2[2] > 0) {
          atuador3fwd = 0;
          atuador3bwd = velAtuador2[2] * aceleracao * intensity / 10000;
        }
        else {
          atuador3fwd = abs(velAtuador2[2] * aceleracao * intensity / 10000);
          atuador3bwd = 0;
        }
        break;

      case 3:
        if ((trava1down && velAtuador3[0]) || (trava2down && velAtuador3[1]) || (trava3down && velAtuador3[2])) {
          atuador1fwd = 0;
          atuador1bwd = 0;
          atuador2fwd = 0;
          atuador2bwd = 0;
          atuador3fwd = 0;
          atuador3bwd = 0;
          //funcao = 0;
          digitalWrite(pinLED3, LOW);
          break;
        }
        digitalWrite(pinLED3, HIGH);
        if (velAtuador3[0] > 0) {
          atuador1fwd = 0;
          atuador1bwd = velAtuador3[0] * aceleracao * intensity / 10000;
        }
        else {
          atuador1fwd = abs(velAtuador3[0] * aceleracao * intensity / 10000);
          atuador1bwd = 0;
        }
        if (velAtuador3[1] > 0) {
          atuador2fwd = 0;
          atuador2bwd = velAtuador3[1] * aceleracao * intensity / 10000;
        }
        else {
          atuador2fwd = abs(velAtuador3[1] * aceleracao * intensity / 10000);
          atuador2bwd = 0;
        }
        if (velAtuador3[2] > 0) {
          atuador3fwd = 0;
          atuador3bwd = velAtuador3[2] * aceleracao * intensity / 10000;
        }
        else {
          atuador3fwd = abs(velAtuador3[2] * aceleracao * intensity / 10000);
          atuador3bwd = 0;
        }
        break;

      case 0:
        funcao = 1;
        digitalWrite(pinLED1, LOW);
        digitalWrite(pinLED2, LOW);
        digitalWrite(pinLED3, LOW);
        break;
    }
  }
  else { // caso intensity == 0, ou seja, nenhum dos botões acionados
    switch (funcao) {

      case 1:
        if ((velAtuador1[0] > 0 && lastIntensity > 0) || (velAtuador1[0] < 0 && lastIntensity < 0)) {
          atuador1fwd = velAtuador1[0] * aceleracao * lastIntensity / 10000;
          atuador1bwd = 0;
          Serial.println(velAtuador1[0] * aceleracao * lastIntensity / 10000);

        }
        else if ((velAtuador1[0] < 0 && lastIntensity > 0) || (velAtuador1[0] > 0 && lastIntensity < 0)) {
          atuador1fwd = 0;
          atuador1bwd = abs(velAtuador1[0] * aceleracao * lastIntensity / 10000);
          Serial.println(velAtuador1[0] * aceleracao * lastIntensity / 10000);
        }
        if ((velAtuador1[1] > 0 && lastIntensity > 0) || (velAtuador1[1] < 0 && lastIntensity < 0)) {
          atuador2fwd = velAtuador1[1] * aceleracao * lastIntensity / 10000;
          atuador2bwd = 0;
        }
        else if ((velAtuador1[1] < 0 && lastIntensity > 0) || (velAtuador1[1] > 0 && lastIntensity < 0)) {
          atuador2fwd = 0;
          atuador2bwd = abs(velAtuador1[1] * aceleracao * lastIntensity / 10000);
        }
        if ((velAtuador1[2] > 0 && lastIntensity > 0) || (velAtuador1[2] < 0 && lastIntensity < 0)) {
          atuador3fwd = velAtuador1[2] * aceleracao * lastIntensity / 10000;
          atuador3bwd = 0;
        }
        else if ((velAtuador1[2] < 0 && lastIntensity > 0) || (velAtuador1[2] > 0 && lastIntensity < 0)){
          atuador3fwd = 0;
          atuador3bwd = abs(velAtuador1[2]) * aceleracao * lastIntensity / 10000;
        }
        break;

      case 2:
        if ((velAtuador2[0] > 0 && lastIntensity > 0) || (velAtuador2[0] < 0 && lastIntensity < 0)) {
          atuador1fwd = velAtuador2[0] * aceleracao * lastIntensity / 10000;
          atuador1bwd = 0;
          Serial.println(velAtuador2[0] * aceleracao * lastIntensity / 10000);

        }
        else if ((velAtuador2[0] < 0 && lastIntensity > 0) || (velAtuador2[0] > 0 && lastIntensity < 0)){
          atuador1fwd = 0;
          atuador1bwd = abs(velAtuador2[0] * aceleracao * lastIntensity / 10000);
          Serial.println(velAtuador2[0] * aceleracao * lastIntensity / 10000);
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
        if ((velAtuador3[0] > 0 && lastIntensity > 0) || (velAtuador3[0] < 0 && lastIntensity < 0)) {
          atuador1fwd = velAtuador3[0] * aceleracao * lastIntensity / 10000;
          atuador1bwd = 0;
          Serial.println(velAtuador3[0] * aceleracao * lastIntensity / 10000);

        }
        else if ((velAtuador3[0] < 0 && lastIntensity > 0) || (velAtuador3[0] > 0 && lastIntensity < 0)) {
          atuador1fwd = 0;
          atuador1bwd = abs(velAtuador3[0] * aceleracao * lastIntensity / 10000);
          Serial.println(velAtuador3[0] * aceleracao * lastIntensity / 10000);
        }
        if ((velAtuador3[1] > 0 && lastIntensity > 0) || (velAtuador3[1] < 0 && lastIntensity < 0)) {
          atuador2fwd = velAtuador3[1] * aceleracao * lastIntensity / 10000;
          atuador2bwd = 0;
        }
        else if ((velAtuador3[1] < 0 && lastIntensity > 0) || (velAtuador3[1] > 0 && lastIntensity < 0)){
          atuador2fwd = 0;
          atuador2bwd = abs(velAtuador3[1] * aceleracao * lastIntensity / 10000);
        }
        if ((velAtuador3[2] > 0 && lastIntensity > 0) || (velAtuador3[2] < 0 && lastIntensity < 0)) {
          atuador3fwd = velAtuador3[2] * aceleracao * lastIntensity / 10000;
          atuador3bwd = 0;
        }
        else if ((velAtuador3[2] < 0 && lastIntensity > 0) || (velAtuador3[2] > 0 && lastIntensity < 0)){
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
}
