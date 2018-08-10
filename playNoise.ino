
const int buttonPin = 2;
const int speakerPin = 10;
const int piezoPin = A0;

const int toneLengthMs = 100;
const int cFrequency = 220;
const int gFrequency = 392;

const int piezoKnockThreshold = 100;

int buttonState = 0;
int piezoReading = 0;

int highestPiezoReading = 0;

void setup() {
  
  pinMode(buttonPin, INPUT);
  pinMode(piezoPin, INPUT);
  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  bool didKnock = false;
  bool didPressButton= false;
  //knock sensor logic
  piezoReading = analogRead(piezoPin);
  if (piezoReading > piezoKnockThreshold) {
    if (piezoReading > highestPiezoReading) {
      highestPiezoReading = piezoReading;
    }
    Serial.println("knock");
    playTone(cFrequency, toneLengthMs);
    didKnock = true;
  } else {
    Serial.print(piezoReading);
    Serial.print(" of ");
    Serial.println(highestPiezoReading);
  }

  //buttonLogic
//  buttonState = digitalRead(buttonPin);
//  if (buttonState == HIGH) {
//    playTone(gFrequency, toneLengthMs);
//    highestPiezoReading = 0;
//    didPressButton = true;
//    Serial.println("BUTTON");
//  }
  
  if (didKnock || didPressButton) {
    delay(toneLengthMs);
  }
}

void playTone(int frequency, int duration) {
  tone(speakerPin, cFrequency, toneLengthMs);    
  
}

