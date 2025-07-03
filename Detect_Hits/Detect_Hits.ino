#define PINBUZZER 10
#define PINBOTON 2
#define PINLED 13
#define PIN_Sensor_ON 11

#define turn_umbral 500
#define eval_time 300


int velocidad[5] = {100, 105, 110, 115, 120};
int turnSpeed[5] = {60, 62, 64, 66, 68};
bool eval_turn = false;
int turn_factor = 0;
unsigned long eval_runTime = 0;
unsigned long eval_callTime = 0;
unsigned long L_call = 0;
unsigned long R_call = 0;
unsigned long C_call = 0;
int lap = 0;

int posicion_ideal = 0;

float Kprop = 4;
float Kderiv = 55;

int base = 0;
int error_pasado = 0;


void setup() {
  Peripherals_init();
  TB6612FNG_init();
  Sensors_init();

  digitalWrite(PINLED, LOW);
  delay(500);

  Motores(0, 0);


  delay(500);
  WaitBoton();
  calibracion();



  WaitBoton();

  base = velocidad[0];
  delay(1000);
}


void loop() {
  int p = GetPos();
  detectGeo();
  int error = p - posicion_ideal;
  int d_error = error - error_pasado;
  int correction_power = int(Kprop * error) + int(Kderiv * (d_error));

  if (correction_power > 255) {
    correction_power = 255;

  }

  else if (correction_power < -255) {
    correction_power = -255;
  }


  if(eval_turn){
    eval_runTime=millis()-eval_callTime;
    if (error>0){
      turn_factor +=1;
    }else if(error<0){
      turn_factor -=1;
    }
    if(abs(turn_factor) > turn_umbral){
      base = turnSpeed[lap];
      eval_turn = false;
    }else if(eval_runTime > eval_time){
      base = velocidad[lap];
      eval_turn = false;
    }
  }


  Motores(base + correction_power, base + -correction_power);
  error_pasado = error;
}
