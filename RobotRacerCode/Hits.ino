int fin = 0;

int l_geo, ll_geo, lll_geo;

int umbralL = 512;
int umbralR = 512;
int geo = 0;

int HL, HR = 0;

void Read_hits() {

  HL = analogRead(A7);
  HR = analogRead(A0);
 //Serial.print(String(HL)+"   "+String(HR)+'\n');

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
    geo = 0;
  }

  if ((HL == 1) && (HR == 0)) {
    geo = 1;
  }

  if ((HL == 0) && (HR == 1)) {
    geo = 2;
  }

  if ((HL == 1) && (HR == 1)) {
    geo = 3;
  }
 // Serial.print("                                  ");
 // Serial.println(geo);
  if (geo == 3 && time-C_call>=eval_time) {
      //Serial.println("  C");
      C_call = time;
      R_call = time;
      L_call = time;
      funcion_Cruce();
    }
  if (geo == 1 && time-L_call>=eval_time) {
   // Serial.println("L");
    L_call = time;
    funcion_HL();
  }
  if (geo == 2 && time-R_call>=eval_time) {
   // Serial.println(" R");
    R_call = time;
    funcion_HR();
  }

 
}

void funcion_HL() {
  eval_turn = true;
  turn_factor = 0;
  eval_runTime = 0;
  eval_callTime = time;
  tone(PINBUZZER, 5000, 50);
}

void funcion_HR() {

  tone(PINBUZZER, 1500, 50);
  fin++;

  switch (fin) {
    case 2:
      delay(50);
      base = 0;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[1];
      lap++;
      break;
    case 4:
      delay(50);
      base = 0;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[2];
      lap++;
      break;
    case 6:
      delay(50);
      base = 0;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[3];
      lap++;
      break;
    case 8:
      delay(50);
      base = 0;
      Motores(0, 0);
      WaitBoton();
      delay(3000);
      base = velocidad[4];
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