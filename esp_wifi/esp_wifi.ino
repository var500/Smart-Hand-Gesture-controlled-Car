
/* This example is written for Nodemcu Modules */
  #define ENA   14          // Enable/speed motors Right        GPIO14(D5)
  #define ENB   12          // Enable/speed motors Left         GPIO12(D6)
  #define IN_1  15          // L298N in1 motors Rightx          GPIO15(D8)
  #define IN_2  13          // L298N in2 motors Right           GPIO13(D7)
  #define IN_3  2           // L298N in3 motors Left            GPIO2(D4)
  #define IN_4  0           // L298N in4 motors Left            GPIO0(D3)
  
  #include "ESP_Wahaj.h" // importing our library
  String command;             //String to store app command state.
  int speedCar = 500;         // 400 - 1023.
  int speed_Coeff = 3;
  int pwm = 255;
  String path = "nothing";
  
void setup(){
  Serial.begin(9600);
  start("<WIFI SSID>","<WIFI Password>");  // Wifi details connect to
  
   pinMode(ENA, OUTPUT);
   pinMode(ENB, OUTPUT);  
   pinMode(IN_1, OUTPUT);
   pinMode(IN_2, OUTPUT);
   pinMode(IN_3, OUTPUT);
   pinMode(IN_4, OUTPUT);
    
}

void goAhead(){ 
      
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goBack(){
   
      
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goRight(){ 
     
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goLeft(){
     
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }


void stopRobot(){  
   
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
 }

void loop(){
  //waitUntilNewReq();  //Waits until a new request from python come

  if(CheckNewReq() == 1)
  {
    //Serial.println("new request");
    if (getPath()=="/forward"){
    returnThisStr("forward command");
    }
    else if (getPath()=="/backward"){
    returnThisStr("backward command");
    }
    else if(getPath()=="/right"){   //this happens for browsers only.
      returnThisStr("right command");
    }
    else if (getPath()=="/left"){
    returnThisStr("left command");
    }
    else if(getPath()=="/stop"){   //this happens for browsers only.
      returnThisStr("Stop Robot");
    }

    else        //here we receive data. You can receive pwm255 and the decode it to 255 and also get more variables like this
    {
      path = getPath();
      //Serial.println(path);   //String
      //returnThisStr("nothing");
      path.remove(0,1);    //Remove slash /
      delay(500);
      //Serial.println(path);
      if(path=="Forward"){
        goAhead();
      }
      else if(path=="Backward"){
        goBack();
      }
      else if(path ==  "Right"){
        goRight();
      }
      else if(path == "Left"){
        goLeft();
      }
      else if(path == "Stop"){
        stopRobot();
      }
      else
      {
        //Serial.println("Waiting");
      }
      pwm = path.toInt();    //convert to int you can use toFloat()
      //Serial.println(pwm);
    }
    
  }
  
}
