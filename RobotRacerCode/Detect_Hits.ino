#define PINBUZZER 10
#define PINBOTON 2
#define PINLED 13
#define PIN_Sensor_ON 11

#define turn_umbral 10
#define eval_time 200


int velocidad[5] = {94, 80, 100, 120, 150};
int turnSpeed[5] = {94, 94, 94, 94, 94};
bool eval_turn = false;
int turn_factor = 0;
int eval_runTime = 0;
int eval_callTime = 0;
int lap = 0;

int posicion_ideal = 0;

float Kprop = 1.0;
float Kderiv = 11;

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
    turn_factor += -2*int(bitRead(error,15))+1;
    if(abs(turn_factor) > turn_umbral){
      base = turnSpeed[lap];
      eval_turn = false;
    }else if(eval_runTime > eval_time){
      base = velocidad[lap];
    }
  }


  Motores(base + correction_power, base + -correction_power);
  error_pasado = error;
}
