
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

#define   AIN       PB10  // D6
#define   BIN       PA8   // D7
#define   LED       PC7

int   ACounter = 0;
int   BCounter = 0;
int   timerCounter = 0;
bool  acquisition = false;
bool  newData = false;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("OK !");

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(AIN, INPUT_PULLUP);
  pinMode(BIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(AIN), countingAInt, RISING);
  attachInterrupt(digitalPinToInterrupt(BIN), countingBInt, RISING);

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
  digitalWrite(LED, LOW);
  newData = false;
}

void loop() {
  if(Serial.available()){
    Serial.println("Serial");
    char inChar = (char)Serial.read();
    if(inChar == 's'){
      Serial.println("Start");
      digitalWrite(LED, HIGH);

      ACounter = 0;
      BCounter = 0;
      acquisition = true;
      timerCounter = 10; // 10 times at 10 Hz = 1 second
    }
  }
  if(newData == true){
    newData = false;
    Serial.print("Value A = ");
    Serial.println(ACounter);
    Serial.print("Value B = ");
    Serial.println(BCounter);
    ACounter = 0;
    BCounter = 0;
  }
  delay(100);
}

void countingAInt(void){
  if(acquisition == true){
    ACounter += 1;
  }
}

void countingBInt(void){
  if(acquisition == true){
    BCounter += 1;
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
  if(acquisition == true){
    digitalWrite(LED, LOW);
    acquisition = false;
    newData = true;
  }
}
