int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // Green on, two reds off
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {

    digitalWrite(3, LOW);

    //int i = 0;
    for (int i = 0; i < 3; i++) {
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      delay(250);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay(250);
    }



    // far red light on, green and middle red off (button press)
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(3000);  // quarter second wait

    // far red turns off, middle red turns on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(3000);
  }

}
