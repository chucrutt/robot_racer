int fin = 0;

int umbralL = 750;
int umbralR = 750;
int geo[6] = {0,0,0,0,0,0};
int geo_val = -1;

int HL, HR = 0;

void Read_hits() {
  HL = analogRead(A7);
  HR = analogRead(A0);

  if (HL > umbralL) {
    HL = 0;
  } else {
    HL = 1;
  }

  if (HR > umbralR) {
    HR = 0;
  } else {
    HR = 1;
  }
}

void detectGeo() {

  Read_hits();

  if ((HL == 0) && (HR == 0)) {
    geo[0] = 0;
  }

  if ((HL == 1) && (HR == 0)) {
    geo[0] = 1;
  }

  if ((HL == 0) && (HR == 1)) {
    geo[0] = 2;
  }

  if ((HL == 1) && (HR == 1)) {
    geo[0] = 3;
  }
  for(int i = 0; i < 5; i++){
    if(geo[i] == geo[i+1]){
      val_geo = geo[i];
    } else {
      val_geo = -1;
      i = 5;
    }
  }
  if (millis()-C_call > eval_time && val_geo == 3) {
      C_call = millis();
      funcion_Cruce();
    }
  if (millis()-L_call > eval_time && val_geo == 1) {
    L_call = millis();
    funcion_HL();
  }
  if (millis()-R_call > eval_time && val_geo == 2) {
    R_call = millis();
    funcion_HR();
  }
  for (int i = 0; i < 5; i++){
    geo[i+1] = geo[i];
  }
}

void funcion_HL() {
  eval_turn = true;
  turn_factor = 0;
  eval_runTime = 0;
  eval_callTime = millis();
  tone(PINBUZZER, 5000, 50);
}

void funcion_HR() {

  tone(PINBUZZER, 1500, 50);
  fin++;

  switch (fin) {
    case 2:
      delay(50);
      base = 0;
      lap++;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[1];
      break;
    case 4:
      delay(50);
      base = 0;
      lap++;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[2];
      break;
    case 6:
      delay(50);
      base = 0;
      lap++;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[3];
      break;
    case 8:
      delay(50);
      base = 0;
      lap++;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[4];
      break;
    case 10:
      delay(50);
      base = 0;
      lap++;
      Motores(0, 0);
      tone(PINBUZZER, 5000, 20);
      delay(20);
      tone(PINBUZZER, 2000, 20);
      while(millis()>0){}
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}

void funcion_Cruce() {
  tone(PINBUZZER, 2500, 50);
}