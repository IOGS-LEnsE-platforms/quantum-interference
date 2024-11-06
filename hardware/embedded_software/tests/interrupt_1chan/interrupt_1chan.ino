
/*
 *  Coincidence / Quantum Interference project
 **********************************************************************
 *  Test of the maximum rate on 1 interrupt input.
 *    Acquisition of a signal on AIN digital input during 1 second.
 *    Start of the acquisition by sending 's' on the Serial port (9600bds).
 *    Value of the counter transmit at the end of the acquisition.
 **********************************************************************
 *    LEnsE / Institut d'Optique / https://lense.institutoptique.fr/ 
 *    Author : Julien VILLEMEJANE / 06/nov/2024
 */

#define   AIN       PC7
#define   LED       PA5

int   ACounter = 0;
int   timerCounter = 0;
bool  acquisition = false;
bool  newData = false;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  pinMode(LED, OUTPUT);
  pinMode(AIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(AIN), countingInt, RISING);
  digitalWrite(LED, LOW);

  // // Setup TIMER !
#if defined(TIM1)
  TIM_TypeDef *Instance = TIM1;
#else
  TIM_TypeDef *Instance = TIM2;
#endif
  // Instantiate HardwareTimer object. Thanks to 'new' instanciation, HardwareTimer is not destructed when setup() function is finished.
  HardwareTimer *MyTim = new HardwareTimer(Instance);
  MyTim->setOverflow(10, HERTZ_FORMAT); // 10 Hz
  MyTim->attachInterrupt(samplingInt);
  MyTim->resume();
  // // Setup TIMER ! // END
}

void loop() {
  if(Serial.available()){
    char inChar = (char)Serial.read();
    if(inChar == 's'){
      digitalWrite(LED, HIGH);

      ACounter = 0;
      acquisition = true;
      timerCounter = 10; // 10 times at 10 Hz = 1 second
    }
  }
  if(newData == true){
    newData = false;
    Serial.println(ACounter);
    ACounter = 0;
  }
  delay(100);
}

void countingInt(void){
  if(acquisition == true){
    ACounter += 1;
  }
}

void samplingInt(void){
  if(timerCounter != 0){
    timerCounter -= 1;
  }
  else{
    stopTimer();
  }
}

void stopTimer(void){
  digitalWrite(LED, LOW);
  acquisition = false;
  newData = true;
}
