const int digitPins[] = {2, 3, 4, 5, 6, 7, 8};  // Pins for each segment
const int commonPin = 9;  // Common pin (cathode or anode)

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  pinMode(commonPin, OUTPUT);
}

void loop() {
  // Display numbers 0 to 9 on the 7-segment display
  for (int i = 0; i < 10; i++) {
    displayNumber(i);
    delay(1000);
  }
}

void displayNumber(int number) {
  const int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
  };

  for (int i = 0; i < 7; i++) {
    digitalWrite(digitPins[i], segments[number][i]);
  }

  digitalWrite(commonPin, HIGH);
  delay(5);
  digitalWrite(commonPin, LOW);
}

