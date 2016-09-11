/*
   Developed by Aswinth Prajan J.
   PSG College of Technology.
   Feel free to comment incase of any doubts.
*/

char command;
String string;

//MOTOR 1
int ENA = 5; //connected to Arduino's port 5(output pwm)
int IN1 = 2; //connected to Arduino's port 2
int IN2 = 3; //connected to Arduino's port 3
//MOTOR 2
int ENB = 6; //connected to Arduino's port 6(output pwm)
int IN3 = 4; //connected to Arduino's port 4
int IN4 = 7; //connected to Arduino's port 7

void setup()
{
  Serial.begin(9600);

  pinMode(ENA, OUTPUT); //UPTPUT PINS
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW); //stop driving
}

void loop()
{
  if (Serial.available() > 0)
  {
    string = "";
  }

  while (Serial.available() > 0)
  {
    command = ((byte)Serial.read());

    if (command == ':')
    {
      break;
    }

    else
    {
      string += command;
    }

    delay(1);
  }

  if (string == "TR")
  {
    TurnRight(); //Call turn Right Function
  }

  if (string == "TL")
  {
    TurnLeft(); //Call turn Left Function
  }

  if (string == "MF")
  {
    toMove(); //Call turn Move Function
  }

  if (string == "TS")
  {
    toStop(); //Call turn Stop Function
  }

  if (string == "MB")
  {
    toMoveBack(); //Call move back Function
  }


  if ((string.toInt() >= 0) && (string.toInt() <= 255))
  {
    if (ledon == true)
    {

      Serial.println(string);
      delay(10);
    }
  }
}


void toMove()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //setting motorA's directon
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //setting motorB's directon
  analogWrite(ENA, 255); //start driving motorA
  analogWrite(ENB, 255); //start driving motorB
}
void toStop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW); //setting motorA's directon
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); //setting motorB's directon
  analogWrite(ENA, LOW); //stop driving motorA
  analogWrite(ENB, LOW); //stop driving motorB
}
void TurnRight()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //setting motorA's directon
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); //setting motorB's directon
  analogWrite(ENA, 255); //start driving motorA
  analogWrite(ENB, LOW); //stop driving motorB
}
void TurnLeft()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW); //setting motorA's directon
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //setting motorB's directon
  analogWrite(ENA, LOW); //start driving motorA
  analogWrite(ENB, 255); //stop driving motorB
}
void toMoveBack()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); //setting motorA's directon
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); //setting motorB's directon
  analogWrite(ENA, 255); //start driving motorA
  analogWrite(ENB, 255); //stop driving motorB
}



