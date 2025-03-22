// Define motor control pins
int B1A = 4; // Motor 1 - Backward control (GPIO Digital Pin 10)
int B2A = 5; // Motor 1 - Forward control (GPIO Digital Pin 11)
int A1A = 6; // Motor 2 - Forward control (GPIO Digital Pin 12)
int A2B = 7; // Motor 2 - Backward control (GPIO Digital Pin 13)

char BT_Data; //Char value called Bluetooth Data
int Buzz = 9; // buzz for horn
int R_LED = 10; //turning RIGHT LED blink
int L_LED = 11; //turning LEFT LED blink


void setup() {
  Serial.begin(9600); //Start the serial for RX and TX at 9600 baud rate
  
  // Set motor control pins as outputs
  pinMode(B1A, OUTPUT); //Set pin 10 as an output
  pinMode(B2A, OUTPUT); //Set pin 11 as an output
  pinMode(A1A, OUTPUT); //Set pin 12 as an output
  pinMode(A2B, OUTPUT); //Set pin 13 as an output

  // Set additional component pins as outputs
  pinMode (Buzz, OUTPUT); //Pin 9 for horn
  pinMode (R_LED, OUTPUT); //turning RIGHT LED blink
  pinMode (L_LED, OUTPUT); //turning LEFT LED blink
}


// Function to move forward
void forward()
{
  digitalWrite(B1A, LOW); //Send a logical LOW pin 10
  digitalWrite(B2A, HIGH); //Send a logical HIGH pin 11
  digitalWrite(A1A, HIGH); //Send a logical HIGH pin 12
  digitalWrite(A2B, LOW); //Send a logical LOW pin 13
  digitalWrite(R_LED, LOW);  //turning Right LED not blink
  digitalWrite(L_LED, LOW); //turning LEFT LED not blink
}

// Function to stop all motors
void stop_all()
{
  digitalWrite(B1A, LOW); //Send a logical LOW pin 10
  digitalWrite(B2A, LOW); //Send a logical LOW pin 11
  digitalWrite(A1A, LOW); //Send a logical LOW pin 12
  digitalWrite(A2B, LOW); //Send a logical LOW pin 13
  digitalWrite(R_LED, LOW);  //turning Right LED not blink
  digitalWrite(L_LED, LOW); //turning LEFT LED not blink
}

// Function to move backward
void backward()
{
  digitalWrite(B1A, HIGH); //Send a logical LOW pin 10
  digitalWrite(B2A, LOW); //Send a logical HIGH pin 11
  digitalWrite(A1A, LOW); //Send a logical HIGH pin 12
  digitalWrite(A2B, HIGH); //Send a logical LOW pin 13
  digitalWrite(R_LED, LOW);  //turning Right LED not blink
  digitalWrite(L_LED, LOW); //turning LEFT LED not blink
}

// Function to turn left
void left()
{
  digitalWrite(B1A, HIGH); //Send a logical LOW pin 10
  digitalWrite(B2A, LOW); //Send a logical HIGH pin 11
  digitalWrite(A1A, HIGH); //Send a logical HIGH pin 12
  digitalWrite(A2B, LOW); //Send a logical LOW pin 13
  digitalWrite(L_LED, HIGH); //turning LEFT LED blink
  digitalWrite(R_LED, LOW);  //turning Right LED not blink
}

// Function to turn right
void right()
{
  digitalWrite(B1A, LOW); //Send a logical LOW pin 10
  digitalWrite(B2A, HIGH); //Send a logical HIGH pin 11
  digitalWrite(A1A, LOW); //Send a logical HIGH pin 12
  digitalWrite(A2B, HIGH); //Send a logical LOW pin 13
  digitalWrite(R_LED, HIGH);//turning RIGHT LED blink
  digitalWrite(R_LED, HIGH);//turning RIGHT LED blink
  delay (300);
  digitalWrite(R_LED, LOW);//turning RIGHT LED blink
  delay (300);
  digitalWrite(L_LED, LOW); //turning LEFT LED not blink
}

void loop() {
  if (Serial.available()) // Check if there are data on the serial port from Bluetooth
  {
    BT_Data = Serial.read(); // Read the data and store them in the global variable BT_Data

    // Perform actions based on received data
    switch (BT_Data)
    {
      case 'X':  // Move forward
        forward(); 
        break;
      case 'S': // Move backward
        backward();
        break;
      case 'A': // Turn left
        left(); 
        break;
      case 'D': // Turn right
        right();
        break;
      case 'H': // Turn ON horn
        digitalWrite(Buzz, HIGH); 
        break;
      case 'h': // Turn OFF horn
        digitalWrite(Buzz, LOW);
        break;
      default: // Stop all motors if no valid command received
        stop_all();
        
    }
  }
}
