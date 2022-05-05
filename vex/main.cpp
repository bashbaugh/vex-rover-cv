// VEX V5 Rover Code
// Benjamin Ashbaugh & Liam Sweeney
#include "vex.h"
// using namespace vex;

//#region config_globals
vex::brain brain();
vex::controller controller();
vex::motor motor_tl(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor motor_tr(vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor motor_bl(vex::PORT3, vex::gearSetting::ratio18_1, false);
vex::motor motor_br(vex::PORT4, vex::gearSetting::ratio18_1, false);
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
    int rot = reverse ? -1 : 1
    motor_tl.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
    motor_tr.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
    motor_bl.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
    motor_br.spinTo(rot, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
  }
  
  void loop () {
    while (true) {
      step_forward();
    }

    if (controller.ButtonUp.pressing()) this->step(false)
    if (controller.ButtonDown.pressing()) this->step(true)
  } 
}

Rover rover();

int main(void) {
  rover.loop();
}
