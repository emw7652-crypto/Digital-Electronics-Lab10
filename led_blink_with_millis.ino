// Final Version
unsigned long lastStepTime = 0;
int stepLength = 1000;
int currentStep = 0;
int totalSteps = 4;
int ledPins[4] = {1, 2, 3, 4};
int potPin = A0;
int direction = 1;  
int switchPin = 7;
int randomSwitchPin = 8; 
// Setup Area
void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(randomSwitchPin, INPUT);

  for (int i = 0; i < totalSteps; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  digitalWrite(ledPins[currentStep], HIGH); 
}

void loop() {
 unsigned long currentTime = millis(); 
  int potValue = analogRead(potPin);
  stepLength = map(potValue, 0, 1023, 50, 1000);
  if (digitalRead(switchPin) == HIGH) {
  direction = -1; 
} else {
  direction = 1;  
}
if (currentTime - lastStepTime >= stepLength) {
  digitalWrite(ledPins[currentStep], LOW);
      if (digitalRead(randomSwitchPin) == HIGH) {
      currentStep = random(0, totalSteps);
    } 
    else {
  if (direction == 1) {
    nextStep();
  } else {
    previousStep();
  }}
  digitalWrite(ledPins[currentStep], HIGH);
  lastStepTime = currentTime;
}}

void nextStep() {
  currentStep = currentStep + 1;
  if (currentStep >= totalSteps) {
    currentStep = 0;
  }
}

void previousStep() {
    currentStep = currentStep - 1;
  if (currentStep < 0) {
    currentStep = totalSteps - 1;
  }
}
