//http://www.smashingrobotics.com/arduino-simulators-lineup-start-developing-without-real-board/

double time = 200;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;

void setup() {
  pinMode(2, OUTPUT); // RED
  pinMode(3, OUTPUT); // YELLOW
  pinMode(4, OUTPUT); // GREEN
}

void loop() {
  blinky(LED1);
  blinky(LED2);
  blinky(LED3);
  blinky(LED2);
}

void blinky (int LED) {
  digitalWrite(LED, HIGH);
  delay(time);
  digitalWrite(LED, LOW);
}
