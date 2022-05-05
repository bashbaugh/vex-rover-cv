// VEX V5 Rover Code
// Benjamin Ashbaugh & Liam Sweeney
#include "vex.h"
// using namespace vex;

//#region config_globals
vex::brain Brain;
vex::motor motor_fl(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor motor_fr(vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor motor_rl(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor motor_rr(vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor motor_claw(vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor motor_pitch(vex::PORT19, vex::gearSetting::ratio18_1, false);
vex::motor motor_extend(vex::PORT20, vex::gearSetting::ratio18_1, false);
//#endregion config_globals

const int SPEEDPCT = 80;

// class serialinterface {
//     constructor () { }
    
//     sendMsg () {
//         brain::serial::write()
//     }
// }

class Rover {
  public:
  void step(bool reverse = false) {
    int rot = reverse ? -1 : 1;
    motor_fl.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
    motor_fr.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
    motor_rl.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
    motor_rr.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
  }
  
  void loop () {
    while (true) {
      if (controller.ButtonUp.pressing()) this->step(false);
      if (controller.ButtonDown.pressing()) this->step(true);
    }
  }
};

Rover rover;

int main(void) {
  rover.loop();
}
