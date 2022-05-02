// VEX V5 Rover Code
// Benjamin Ashbaugh & Liam Sweeney
#include "vex.h"
// using namespace vex;

//#region config_globals
vex::brain brain;
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
  public void step_forward() {
      motor_tl::spinTo(1, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
      motor_tr::spinTo(1, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
      motor_bl::spinTo(1, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
      motor_br::spinTo(1, vex::rotationUnits::rev, SPEEDPCT, vex::velocityUnits::pct, true);
    }
    
  public void loop () {
    while (true) {
        step_forward();
    }
  }
}

Rover rover();

int main(void) {
  rover::loop();
}
