
#include <Wire.h>
#include <Joystick.h>

// Define Analog Inputs
#define joyThrottle A0
#define joyY A1
#define joyX A2
#define joyRZ A3
#define joyRX A4

// Initialize the Axis as integers with a 0 default value
int throttleAxis_ = 0;
int xAxis_ = 0;
int yAxis_ = 0;
int rzAxis_ = 0;
int rxAxis_ = 0;

// Define Digital Buttons
#define joyButton1 6
#define joyButton2 7
#define joyButton3 8
#define joyButton4 9
#define joyButton5 14
#define joyButton6 15
#define joyButton7 16
#define joyButton8 17
#define joyButton9 18
#define joyButton10 19
#define joyButton11 20
#define joyButton12 21
#define joyButton13 22
#define joyButton14 23
#define joyButton15 24
#define joyButton16 25
#define joyButton17 26
#define joyButton18 27
#define joyButton19 28
#define joyButton20 29
#define joyButton21 30
#define joyButton22 31
#define joyButton23 32
#define joyButton24 33
#define joyButton25 34
#define joyButton26 35
#define joyButton27 36
#define joyButton28 37
#define joyButton29 38
#define joyButton30 39
#define joyButton31 40
#define joyButton32 41
#define joyButton33 42
#define joyButton34 43
#define joyButton35 44
#define joyButton36 45
#define joyButton37 46
#define joyButton38 47
#define joyButton39 48
#define joyButton40 49
#define joyButton41 50
#define joyButton42 51
#define joyButton43 52
#define joyButton44 53

// Define Rotary Encoders
#define joyButton45 2
#define joyButton46 3
#define joyButton47 4
#define joyButton48 5

// Initalize button states with default value of 0
int lastButton1State = 0;
int lastButton2State = 0;
int lastButton3State = 0;
int lastButton4State = 0;
int lastButton5State = 0;
int lastButton6State = 0;
int lastButton7State = 0;
int lastButton8State = 0;
int lastButton9State = 0;
int lastButton10State = 0;
int lastButton11State = 0;
int lastButton12State = 0;
int lastButton13State = 0;
int lastButton14State = 0;
int lastButton15State = 0;
int lastButton16State = 0;
int lastButton17State = 0;
int lastButton18State = 0;
int lastButton19State = 0;
int lastButton20State = 0;
int lastButton21State = 0;
int lastButton22State = 0;
int lastButton23State = 0;
int lastButton24State = 0;
int lastButton25State = 0;
int lastButton26State = 0;
int lastButton27State = 0;
int lastButton28State = 0;
int lastButton29State = 0;
int lastButton30State = 0;
int lastButton31State = 0;
int lastButton32State = 0;
int lastButton33State = 0;
int lastButton34State = 0;
int lastButton35State = 0;
int lastButton36State = 0;
int lastButton37State = 0;
int lastButton38State = 0;
int lastButton39State = 0;
int lastButton40State = 0;
int lastButton41State = 0;
int lastButton42State = 0;
int lastButton43State = 0;
int lastButton44State = 0;
int lastButton45State = 0;
int lastButton46State = 0;
int lastButton47State = 0;
int lastButton48State = 0;


// Initalize the Joystick Data Structure
//Defining the Joystick
//The Joystick is defined in the following setup:
//Joystick(Joystick HID ID, Joystick Type, Button Count, Hat Switch Count, Include X, Include Y, Include Z, Include Rx, Include Ry, Include Rz, Include Rudder, Include Throttle, Include Accelerator, Include Brake, Include Steering
//Joystick HID ID: A Hex value identifier for HID Device Recognition (default: 0x03). DO NOT USE 0x01 or 0x02
//Joystick type: Define the type of joystick from the types supported. Types: DEFAULT Joystick (0x04 or JOYSTICK_TYPE_JOYSTICK), Gamepad (0x05 or JOYSTICK_TYPE_GAMEPAD), Multi-Axis Controller (0x08 or JOYSTICK_TYPE_MULTI_AXIS)
//Button Count: Number of Buttons shown to HID system (default: 32)
//Hat Switch Count: Number of Hat Switches, max 2. (default:2)
//Include X Axis: Determines whether the X axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Y Axis: Determines whether the Y axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Z Axis: Determines whether the Z axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Rx Axis: Determines whether the X Rotational axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Ry Axis: Determines whether the Y Rotational axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Rz Axis: Determines whether the Z Rotational axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Rudder: Determines whether a Rudder axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Throttle: Determines whether a Throttle axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Accelerator: Determines whether an Accelerator axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Brake: Determines whether a Brake axis is avalible for used by the HID system, defined as a bool value (default:true)
//Include Steering: Determines whether a Steering axis is avalible for used by the HID system, defined as a bool value (default:true)

Joystick_ Joystick(0x15, JOYSTICK_TYPE_JOYSTICK, 48, 0, true, true, true, false, false, true, false, true, true, false, false);

const bool initAutoSendState = true;
const int smoothing = 255;


int setButtonState(int currentButtonState, int previousButtonState, int button){
  // Function to update button states and update the joystick
  int newButtonState;
  if (currentButtonState != previousButtonState){
    Joystick.setButton(button, currentButtonState);
    newButtonState = currentButtonState;
    return newButtonState;
  }
  else {
    newButtonState = previousButtonState;
    return newButtonState;
  }
}


void setup() {
  // Initialize Buttons as Pullup:
  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);
  pinMode(joyButton3, INPUT_PULLUP);
  pinMode(joyButton4, INPUT_PULLUP);
  pinMode(joyButton5, INPUT_PULLUP);
  pinMode(joyButton6, INPUT_PULLUP);
  pinMode(joyButton7, INPUT_PULLUP);
  pinMode(joyButton8, INPUT_PULLUP);
  pinMode(joyButton9, INPUT_PULLUP);
  pinMode(joyButton10, INPUT_PULLUP);
  pinMode(joyButton11, INPUT_PULLUP);
  pinMode(joyButton12, INPUT_PULLUP);
  pinMode(joyButton13, INPUT_PULLUP);
  pinMode(joyButton14, INPUT_PULLUP);
  pinMode(joyButton15, INPUT_PULLUP);
  pinMode(joyButton16, INPUT_PULLUP);
  pinMode(joyButton17, INPUT_PULLUP);
  pinMode(joyButton18, INPUT_PULLUP);
  pinMode(joyButton19, INPUT_PULLUP);
  pinMode(joyButton20, INPUT_PULLUP);
  pinMode(joyButton21, INPUT_PULLUP);
  pinMode(joyButton22, INPUT_PULLUP);
  pinMode(joyButton23, INPUT_PULLUP);
  pinMode(joyButton24, INPUT_PULLUP);
  pinMode(joyButton25, INPUT_PULLUP);
  pinMode(joyButton26, INPUT_PULLUP);
  pinMode(joyButton27, INPUT_PULLUP);
  pinMode(joyButton28, INPUT_PULLUP);
  pinMode(joyButton29, INPUT_PULLUP);
  pinMode(joyButton30, INPUT_PULLUP);
  pinMode(joyButton31, INPUT_PULLUP);
  pinMode(joyButton32, INPUT_PULLUP);
  pinMode(joyButton33, INPUT_PULLUP);
  pinMode(joyButton34, INPUT_PULLUP);
  pinMode(joyButton35, INPUT_PULLUP);
  pinMode(joyButton36, INPUT_PULLUP);
  pinMode(joyButton37, INPUT_PULLUP);
  pinMode(joyButton38, INPUT_PULLUP);
  pinMode(joyButton39, INPUT_PULLUP);
  pinMode(joyButton40, INPUT_PULLUP);
  pinMode(joyButton41, INPUT_PULLUP);
  pinMode(joyButton42, INPUT_PULLUP);
  pinMode(joyButton43, INPUT_PULLUP);
  pinMode(joyButton44, INPUT_PULLUP);
  // Rotary Encoders Init
  pinMode(joyButton45, INPUT_PULLUP);
  pinMode(joyButton46, INPUT_PULLUP);
  pinMode(joyButton47, INPUT_PULLUP);
  pinMode(joyButton48, INPUT_PULLUP);
 
  //Start Joystick - Needed to start the Joystick function libary
  Joystick.begin();
}


void loop() {
  // Handle Axis Reads (because they are easier)
 
  xAxis_ = analogRead(joyX);
  xAxis_ = map(xAxis_,0,1023,0,smoothing);   //Mapping the X Axis data from a 0-1023 to 0-255 range for a smoother action
  Joystick.setXAxis(xAxis_);

  yAxis_ = analogRead(joyY);
  yAxis_ = map(yAxis_, 0, 1023, 0, smoothing);
  Joystick.setYAxis(yAxis_);
 
  throttleAxis_ = analogRead(joyThrottle);
  throttleAxis_ = map(throttleAxis_, 0, 1023, 0, smoothing);
  Joystick.setThrottle(throttleAxis_);
 
  rzAxis_ = analogRead(joyRZ);
  rzAxis_ = map(rzAxis_, 0, 1023, 0, smoothing);
  Joystick.setRzAxis(rzAxis_);
 
  rxAxis_ = analogRead(joyRX);
  rxAxis_ = map(rxAxis_, 0, 1023, 0, smoothing);
  Joystick.setZAxis(rxAxis_);

  // Handle the buttons
  int currentButton1State = !digitalRead(joyButton1);
  lastButton1State = setButtonState(currentButton1State, lastButton1State, 0);

  int currentButton2State = !digitalRead(joyButton2);
  lastButton2State = setButtonState(currentButton2State, lastButton2State, 1);

  int currentButton3State = !digitalRead(joyButton3);
  lastButton3State = setButtonState(currentButton3State, lastButton3State, 2);

  int currentButton4State = !digitalRead(joyButton4);
  lastButton4State = setButtonState(currentButton4State, lastButton4State, 3);

  int currentButton5State = !digitalRead(joyButton5);
  lastButton5State = setButtonState(currentButton5State, lastButton5State, 4);

  int currentButton6State = !digitalRead(joyButton6);
  lastButton6State = setButtonState(currentButton6State, lastButton6State, 5);

  int currentButton7State = !digitalRead(joyButton7);
  lastButton7State = setButtonState(currentButton7State, lastButton7State, 6);

  int currentButton8State = !digitalRead(joyButton8);
  lastButton8State = setButtonState(currentButton8State, lastButton8State, 7);

  int currentButton9State = !digitalRead(joyButton9);
  lastButton9State = setButtonState(currentButton9State, lastButton9State, 8);

  int currentButton10State = !digitalRead(joyButton10);
  lastButton10State = setButtonState(currentButton10State, lastButton10State, 9);

  int currentButton11State = !digitalRead(joyButton11);
  lastButton11State = setButtonState(currentButton11State, lastButton11State, 10);

  int currentButton12State = !digitalRead(joyButton12);
  lastButton12State = setButtonState(currentButton12State, lastButton12State, 11);

  int currentButton13State = !digitalRead(joyButton13);
  lastButton13State = setButtonState(currentButton13State, lastButton13State, 12);

  int currentButton14State = !digitalRead(joyButton14);
  lastButton14State = setButtonState(currentButton14State, lastButton14State, 13);

  int currentButton15State = !digitalRead(joyButton15);
  lastButton15State = setButtonState(currentButton15State, lastButton15State, 14);

  int currentButton16State = !digitalRead(joyButton16);
  lastButton16State = setButtonState(currentButton16State, lastButton16State, 15);

  int currentButton17State = !digitalRead(joyButton17);
  lastButton17State = setButtonState(currentButton17State, lastButton17State, 16);

  int currentButton18State = !digitalRead(joyButton18);
  lastButton18State = setButtonState(currentButton18State, lastButton18State, 17);

  int currentButton19State = !digitalRead(joyButton19);
  lastButton19State = setButtonState(currentButton19State, lastButton19State, 18);

  int currentButton20State = !digitalRead(joyButton20);
  lastButton20State = setButtonState(currentButton20State, lastButton20State, 19);

  int currentButton21State = !digitalRead(joyButton21);
  lastButton21State = setButtonState(currentButton21State, lastButton21State, 20);

  int currentButton22State = !digitalRead(joyButton22);
  lastButton22State = setButtonState(currentButton22State, lastButton22State, 21);

  int currentButton23State = !digitalRead(joyButton23);
  lastButton23State = setButtonState(currentButton23State, lastButton23State, 22);

  int currentButton24State = !digitalRead(joyButton24);
  lastButton24State = setButtonState(currentButton24State, lastButton24State, 23);

  int currentButton25State = !digitalRead(joyButton25);
  lastButton25State = setButtonState(currentButton25State, lastButton25State, 24);

  int currentButton26State = !digitalRead(joyButton26);
  lastButton26State = setButtonState(currentButton26State, lastButton26State, 25);

  int currentButton27State = !digitalRead(joyButton27);
  lastButton27State = setButtonState(currentButton27State, lastButton27State, 26);

  int currentButton28State = !digitalRead(joyButton28);
  lastButton28State = setButtonState(currentButton28State, lastButton28State, 27);

  int currentButton29State = !digitalRead(joyButton29);
  lastButton29State = setButtonState(currentButton29State, lastButton29State, 28);

  int currentButton30State = !digitalRead(joyButton30);
  lastButton30State = setButtonState(currentButton30State, lastButton30State, 29);

  int currentButton31State = !digitalRead(joyButton31);
  lastButton31State = setButtonState(currentButton31State, lastButton31State, 30);

  int currentButton32State = !digitalRead(joyButton32);
  lastButton32State = setButtonState(currentButton32State, lastButton32State, 31);

  int currentButton33State = !digitalRead(joyButton33);
  lastButton33State = setButtonState(currentButton33State, lastButton33State, 32);

  int currentButton34State = !digitalRead(joyButton34);
  lastButton34State = setButtonState(currentButton34State, lastButton34State, 33);

  int currentButton35State = !digitalRead(joyButton35);
  lastButton35State = setButtonState(currentButton35State, lastButton35State, 34);

  int currentButton36State = !digitalRead(joyButton36);
  lastButton36State = setButtonState(currentButton36State, lastButton36State, 35);

  int currentButton37State = !digitalRead(joyButton37);
  lastButton37State = setButtonState(currentButton37State, lastButton37State, 36);

  int currentButton38State = !digitalRead(joyButton38);
  lastButton38State = setButtonState(currentButton38State, lastButton38State, 37);

  int currentButton39State = !digitalRead(joyButton39);
  lastButton39State = setButtonState(currentButton39State, lastButton39State, 38);

  int currentButton40State = !digitalRead(joyButton40);
  lastButton40State = setButtonState(currentButton40State, lastButton40State, 39);

  int currentButton41State = !digitalRead(joyButton41);
  lastButton41State = setButtonState(currentButton41State, lastButton41State, 40);

  int currentButton42State = !digitalRead(joyButton42);
  lastButton42State = setButtonState(currentButton42State, lastButton42State, 41);

  int currentButton43State = !digitalRead(joyButton43);
  lastButton43State = setButtonState(currentButton43State, lastButton43State, 42);

  int currentButton44State = !digitalRead(joyButton44);
  lastButton44State = setButtonState(currentButton44State, lastButton44State, 43);

  
  int currentButton45State = !digitalRead(joyButton45);
  if (currentButton45State != lastButton45State){ // If different a pulse has happened
    
    if (!digitalRead(joyButton46) != currentButton45State) { 
      Joystick.setButton(44, currentButton45State) // set button state for CW rotation
      } else {
        Joystick.setButton(45, currentButton45State) //set button state for CCW rotation
      }
  }
  lastButton4State = currentButton45State;
  
  int currentButton47State = !digitalRead(joyButton47);
  if (currentButton47State != lastButton47State){ // If different a pulse has happened
    
    if (!digitalRead(joyButton48) != currentButton47State) { 
      Joystick.setButton(46, currentButton47State) // set button state for CW rotation
      } else {
        Joystick.setButton(47, currentButton47State) //set button state for CCW rotation
      }
  }
  lastButton47State = currentButton47State;
//   int currentButton45State = !digitalRead(joyButton45);
//   lastButton45State = setButtonState(currentButton45State, lastButton45State, 44);

//   int currentButton46State = !digitalRead(joyButton46);
//   lastButton46State = setButtonState(currentButton46State, lastButton46State, 45);

//   int currentButton47State = !digitalRead(joyButton47);
//   lastButton47State = setButtonState(currentButton47State, lastButton47State, 46);

//   int currentButton48State = !digitalRead(joyButton48);
//   lastButton48State = setButtonState(currentButton48State, lastButton48State, 47);


  // Set a small delay for debouncing
  delay(20);
 

}
