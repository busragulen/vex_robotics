#include "vex.h"
using namespace vex;

int main(){
    while(true){
        Brain.Screen.clearLine();
        VisionSensor.takeSnapshot(SIG_RED);

        if(VisionSensor.largestObject.exists){
            if(VisionSensor.largestObject.centerX > 100){
                RightMotor.spinFor(directionType::forward,700,rotationUnits::degrees);
            }
            if(VisionSensor.largestObject.centerX < 60){
                LeftMotor.spinFor(directionType::forward,700,rotationUnits::degrees);
            }
            if(VisionSensor.largestObject.centerX > 60 && VisionSensor.largestObject.centerX < 100){
                if(VisionSensor.largestObject.width < 125){
                    RightMotor.spin(reverse,20,pct);
                    LeftMotor.spin(forward,20,pct);            
                }
                else{
                    RightMotor.stop(brakeType::brake);
                    LeftMotor.stop(brakeType::brake);
                }
            }
        }
    }
}