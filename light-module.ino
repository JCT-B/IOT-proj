// Pin Definitions
const int ldrPin = 8;       // LDR module digital pin
const int ledldrPin = 9;    // LED controlled by LDR
const int soundPin = 7;     // Sound sensor digital pin
const int soundA = A0;      // Sound sensor analog pin (optional)
const int ledSoundPin = 10; // LED controlled by sound sensor

// Variables
bool soundLightState = false; // To track LED state for sound sensor
int soundThreshold = 90;     // Threshold for sound detection (adjust as needed)

void setup() {
  // Pin Modes
  pinMode(ldrPin, INPUT);
  pinMode(ledldrPin, OUTPUT);
  pinMode(soundPin, INPUT);
  pinMode(soundA, INPUT);
  pinMode(ledSoundPin, OUTPUT);
  
  // Initialize LEDs to off
  digitalWrite(ledldrPin, LOW);
  digitalWrite(ledSoundPin, LOW);

  // Serial Monitor for Debugging
  Serial.begin(9600);
}

void loop() {
  // LDR Sensor Control
  int ldrValue = digitalRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue == HIGH) {
    digitalWrite(ledldrPin, HIGH); // Turn on LED if it's dark
  } else {
    digitalWrite(ledldrPin, LOW); // Turn off LED if it's bright
  }

  // Sound Sensor Control
  int soundValue = analogRead(soundA); // Read analog sound intensity
  Serial.print("Sound Value: ");
  Serial.println(soundValue);

  if (soundValue > soundThreshold) {
    // Toggle LED state when sound threshold is exceeded
    soundLightState = !soundLightState;
    digitalWrite(ledSoundPin, soundLightState ? HIGH : LOW);
    delay(300); // Debounce to prevent multiple triggers for a single sound
  }

  delay(100); // General loop delay
}
