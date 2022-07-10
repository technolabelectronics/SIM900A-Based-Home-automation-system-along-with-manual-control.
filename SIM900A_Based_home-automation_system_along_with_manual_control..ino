// Include Software Serial library to communicate with GSM
// Variable to store text message
String textMessage;

// Create a variable to store Lamp state
String Relay1State = "HIGH";
String Relay2State = "HIGH";
String Relay3State = "HIGH";
String Relay4State = "HIGH";

const int relay1 = 2;  // relay1 connected to pin 12
const int relay2 = 3;  // relay2 connected to pin 11
const int relay3 = 9;  // relay3 connected to pin 12
const int relay4 = 10;  // relay4 connected to pin 11

#define switch1 5      // switch1 connected to pin 4
#define switch2 6      // switch1 connected to pin 5
#define switch3 7      // switch1 connected to pin 4
#define switch4 8      // switch1 connected to pin 5

int switch_ON_Flag1_previous_I = 0;
int switch_ON_Flag2_previous_I = 0;
int switch_ON_Flag3_previous_I = 0;
int switch_ON_Flag4_previous_I = 0;

void setup() {
  // Automatically turn on the shield
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(5000);
  
  // Set both realy as OUTPUT
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

  // By default both the relay is off
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  
  // Initializing serial commmunication 
  Serial.begin(19200);

  // Give time to your GSM shield log on to network
  delay(20000);
  //Serial.print("Serial ready...");

  // AT command to set Serial to SMS mode
  Serial.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  Serial.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop(){
  if(Serial.available()>0){
    textMessage = Serial.readString();
    //Serial.print(textMessage); 
    textMessage.toUpperCase();    
    delay(10);
  } 
  
  if(textMessage.indexOf("RELAY1ON")>=0){
    // Turn on relay1 and save current state
    digitalWrite(relay1, HIGH);
    Relay1State = "on"; 
    //Serial.println("Relay1 set to ON");
    textMessage = ""; 
  }
  if(textMessage.indexOf("RELAY1OFF")>=0){
    // Turn off relay1 and save current state
    digitalWrite(relay1, LOW);
    Relay1State = "off";
    //Serial.println("relay1 set to OFF");  
    textMessage = "";   
  }
  
  //////////////////////////////////////////////////////
  
   if(textMessage.indexOf("RELAY2ON")>=0){
    // Turn on relay2 and save current state
    digitalWrite(relay2, HIGH);
    Relay2State = "on"; 
    //Serial.println("Relay2 set to ON");
    textMessage = ""; 
  }
  if(textMessage.indexOf("RELAY2OFF")>=0){
    // Turn off relay2 and save current state
    digitalWrite(relay2, LOW);
    Relay2State = "off";
    //Serial.println("relay2 set to OFF");  
    textMessage = "";   
  }
  //////////////////////////////////////////////////////
    if(textMessage.indexOf("RELAY3ON")>=0){
    // Turn on relay3 and save current state
    digitalWrite(relay3, HIGH);
    Relay3State = "on"; 
    //Serial.println("Relay3 set to ON");
    textMessage = ""; 
  }
  if(textMessage.indexOf("RELAY3OFF")>=0){
    // Turn off relay3 and save current state
    digitalWrite(relay3, LOW);
    Relay3State = "off";
    //Serial.println("relay3 set to OFF");  
    textMessage = "";   
  }
 //////////////////////////////////////////////////////
    if(textMessage.indexOf("RELAY4ON")>=0){
    // Turn on relay4 and save current state
    digitalWrite(relay4, HIGH);
    Relay4State = "on"; 
    //Serial.println("Relay4 set to ON");
    textMessage = ""; 
  }
  if(textMessage.indexOf("RELAY4OFF")>=0){
    // Turn off relay4 and save current state
    digitalWrite(relay4, LOW);
    Relay4State = "off";
    //Serial.println("relay4 set to OFF");  
    textMessage = "";   
  }

  //////////////////////////////////////////////////////

   if (digitalRead(switch1) == LOW)
  {
    if (switch_ON_Flag1_previous_I == 0 )
    {
      digitalWrite(relay1, LOW);
     
     Relay1State = "off";
    //Serial.println("relay1 set to OFF");
      switch_ON_Flag1_previous_I = 1;
    }
  

  }
  if (digitalRead(switch1) == HIGH)
  {
    if (switch_ON_Flag1_previous_I == 1)
    {
      digitalWrite(relay1, HIGH);
   
     Relay1State = "on"; 
     //Serial.println("Relay1 set to ON");
      switch_ON_Flag1_previous_I = 0;
    }
   
  }


   if (digitalRead(switch2) == LOW)
  {
    if (switch_ON_Flag2_previous_I == 0 )
    {
      digitalWrite(relay2, LOW);
     
     Relay2State = "off";
    //Serial.println("relay2 set to OFF");
      switch_ON_Flag2_previous_I = 1;
    }
  

  }
  if (digitalRead(switch2) == HIGH)
  {
    if (switch_ON_Flag2_previous_I == 1)
    {
      digitalWrite(relay2, HIGH);
   
     Relay2State = "on"; 
     //Serial.println("Relay2 set to ON");
      switch_ON_Flag2_previous_I = 0;
    }
   
  }

  
   if (digitalRead(switch3) == LOW)
  {
    if (switch_ON_Flag3_previous_I == 0 )
    {
      digitalWrite(relay3, LOW);
     
     Relay3State = "off";
    //Serial.println("relay3 set to OFF");
      switch_ON_Flag3_previous_I = 1;
    }
  

  }
  if (digitalRead(switch3) == HIGH)
  {
    if (switch_ON_Flag3_previous_I == 1)
    {
      digitalWrite(relay3, HIGH);
   
     Relay3State = "on"; 
     Serial.println("Relay3 set to ON");
      switch_ON_Flag2_previous_I = 0;
    }
   
  }

  
   if (digitalRead(switch4) == LOW)
  {
    if (switch_ON_Flag4_previous_I == 0 )
    {
      digitalWrite(relay4, LOW);
     
     Relay4State = "off";
    //Serial.println("relay4 set to OFF");
      switch_ON_Flag4_previous_I = 1;
    }
  

  }
  if (digitalRead(switch4) == HIGH)
  {
    if (switch_ON_Flag4_previous_I == 1)
    {
      digitalWrite(relay4, HIGH);
   
     Relay4State = "on"; 
     //Serial.println("Relay4 set to ON");
      switch_ON_Flag4_previous_I = 0;
    }
   
  }

  /////////////////////////////////////////////////////
  
  if(textMessage.indexOf("RELAY1STATE")>=0){
    String message = "Relay1 is " + Relay1State;
    sendSMS(message);
    //Serial.println("Relay1 state resquest");
    textMessage = "";
  }
  
  if(textMessage.indexOf("RELAY2STATE")>=0){
    String message = "Relay2 is " + Relay2State;
    sendSMS(message);
    //Serial.println("Relay2 state resquest");
    textMessage = "";
  }
   if(textMessage.indexOf("RELAY3STATE")>=0){
    String message = "Relay3 is " + Relay3State;
    sendSMS(message);
    //Serial.println("Relay3 state resquest");
    textMessage = "";
  }
   if(textMessage.indexOf("RELAY4STATE")>=0){
    String message = "Relay4 is " + Relay3State;
    sendSMS(message);
    //Serial.println("Relay4 state resquest");
    textMessage = "";
  }
  }

// Function that sends SMS
void sendSMS(String message){
  // AT command to set Serial to SMS mode
  Serial.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  Serial.println("AT + CMGS = \"+91XXXXXXXXX\""); 
  delay(100);
  // Send the SMS
  Serial.println(message); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  Serial.println((char)26); 
  delay(100);
  Serial.println();
  // Give module time to send SMS
  delay(5000);  
}
