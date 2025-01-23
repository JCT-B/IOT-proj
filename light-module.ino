// Pin assignments
const int ldrPin = A0;  // LDR sensor connected to analog pin A0
const int soundPin = 2; // Sound sensor connected to digital pin 2
const int ledSet1 = 3;  // LED set 1 connected to digital pin 3
const int ledSet2 = 4;  // LED set 2 connected to digital pin 4

// Threshold values
const int ldrThreshold = 500;  // Adjust based on the light level to trigger
const int clapDelay = 200;     // Debounce delay for claps (in milliseconds)

// Variables to track clap state
bool isLedSet2On = false;
unsigned long lastClapTime = 0;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(soundPin, INPUT);
  pinMode(ledSet1, OUTPUT);
  pinMode(ledSet2, OUTPUT);

  digitalWrite(ledSet1, LOW);
  digitalWrite(ledSet2, LOW);

  Serial.begin(9600); // For debugging
}

void loop() {
  // Read LDR sensor value
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Control LED set 1 based on LDR sensor
  if (ldrValue > ldrThreshold) {
    digitalWrite(ledSet1, LOW); // Turn off LED set 1 if light is detected
  } else {
    digitalWrite(ledSet1, HIGH); // Turn on LED set 1 if it is dark
  }

  // Check for sound sensor trigger (clap detection)
  if (digitalRead(soundPin) == HIGH) {
    unsigned long currentTime = millis();

    // Debounce the clap detection
    if (currentTime - lastClapTime > clapDelay) {
      lastClapTime = currentTime;

      // Toggle LED set 2
      isLedSet2On = !isLedSet2On;
      digitalWrite(ledSet2, isLedSet2On ? HIGH : LOW);
      Serial.print("Clap detected. LED set 2 is now ");
      Serial.println(isLedSet2On ? "ON" : "OFF");
    }
  }

  delay(50); // Small delay to stabilize readings
}
