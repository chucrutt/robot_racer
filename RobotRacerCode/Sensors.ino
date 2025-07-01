int v_s_min[6] = { 1023, 1023, 1023, 1023, 1023, 1023 };
int v_s_max[6] = { 0, 0, 0, 0, 0, 0 };
int H_max[2] = {1023, 1023};
int H_min[2] = {0, 0};
int Umbrals[2] = {512, 512};
volatile int s_p[6];
bool online;

int pos;
int l_pos;


void Sensors_init() {

pinMode(PIN_Sensor_ON, OUTPUT);


}


void calibracion() {
  digitalWrite(PIN_Sensor_ON, HIGH);

  int v_s[6];
  int latSen[2];

  for (int j = 0; j < 100; j++) {
    delay(30);
    v_s[0] = analogRead(A6);
    v_s[1] = analogRead(A5);
    v_s[2] = analogRead(A4);
    v_s[3] = analogRead(A3);
    v_s[4] = analogRead(A2);
    v_s[5] = analogRead(A1);
    latSen[0] = analogRead(A0); //left
    latSen[1] = analogRead(A7); //right

    for (int i = 0; i < 2; i++) {
      if (latSen[i] < H_min[i]) {
        H_min[i] = latSen[i];
      }
    }

    for (int i = 0; i < 2; i++) {
      if (latSen[i] > H_max[i]) {
        H_max[i] = latSen[i];
      }
    }

    for (int i = 0; i < 6; i++) {
      if (v_s[i] < v_s_min[i]) {
        v_s_min[i] = v_s[i];
      }
    }


    for (int i = 0; i < 6; i++) {
      if (v_s[i] > v_s_max[i]) {
        v_s_max[i] = v_s[i];
      }
    }
  }

  Umbrals[0] = (H_max[0]+H_min[0])*0,35;
  Umbrals[1] = (H_max[1]+H_min[1])*0,35;
  umbralL = 500;//Umbrals[0];
  umbralR = 500;//Umbrals[1];
  beep();
  beep();

  digitalWrite(PIN_Sensor_ON, LOW);
}

void readSensors() {

  digitalWrite(PIN_Sensor_ON, HIGH);

  volatile int s[6];



  s[0] = analogRead(A6);
  s[1] = analogRead(A5);
  s[2] = analogRead(A4);
  s[3] = analogRead(A3);
  s[4] = analogRead(A2);
  s[5] = analogRead(A1);

  for (int i = 0; i < 6; i++) {
    if (s[i] < v_s_min[i]) {
      s[i] = v_s_min[i];
    }

    if (s[i] > v_s_max[i]) {
      s[i] = v_s_max[i];
    }
    s_p[i] = map(s[i], v_s_min[i], v_s_max[i], 100, 0);
  }


  volatile int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];
  if (sum > 100) {
    online = 1;

  } else {
    online = 0;
    sum = 100;
  }

  digitalWrite(PIN_Sensor_ON, LOW);

}




int GetPos() {
  readSensors();
  int prom = -2.5 * s_p[0] - 1.5 * s_p[1] - 0.5 * s_p[2] + 0.5 * s_p[3] + 1.5 * s_p[4] + 2.5 * s_p[5];
  int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];

  if (online) {
    pos = int(100.0 * prom / sum);
  } else {
    if (l_pos < 0) {
      pos = -255;
    }
    if (l_pos >= 0) {
      pos = 255;
    }
  }
  l_pos = pos;
  return pos;
}
