#include "vex.h"
using namespace vex;


vex::brain              Brain;
vex::competition        Competition;
vex::motor              RightMotor = vex::motor(vex::PORT1);
vex::motor              LeftMotor = vex::motor(vex:PORT2);
vex::motor              ArmLiftMotor = vex::motor(vex::PORT3);

vex::motor              RightSpinMotor = vex::motor(vex::PORT4); 
vex::motor              LeftSpinMotor = vex::motor(vex::PORT5);

vex::controller         Controller1 = vex::controller(//if you want to specify that you can write : vex::PORT3);

void pre_auton(void){
    //all activities that occur before the competition starts

}

void autonomus(void){
    
}

void usercontrol(void){

    
    while(1){
        //tank mode drive program
        RightMotor.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
        LeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);

        //arm control
        if(Controller1.ButtonR1.pressing()){
            RightSpinMotor.spin(vex::directionType::fwd,ArmSpeedPercent,vex::velocityUnits::pct);
            LeftSpinMotor.spin(vex::directionType::fwd,ArmSpeedPercent,vex::velocityUnits::pct);
        }
        else if(Controller1.ButtonR2.pressing()){
            RightSpinMotor.spin(vex::directionType::rev,ArmSpeedPercent,vex::velocityUnits::pct);
            LeftSpinMotor.spin(vex::directionType::rev,ArmSpeedPercent,vex::velocityUnits::pct);
        }
        else{
            RightSpinMotor.stop(brakeType::brake);
            LeftSpinMotor.stop(brakeType::brake);
        }

        //setting bumper switch
        if(BumperA.pressing()){
            RightMotor.stop(brakeType::brake);
            LeftMotor.stop(brakeType::brake);
        }
        
    }
}

int main(){
    Competition.autonomus(autonomous);
    Competition.drivercontrol(usercontrol);

    pre_auton();

    while(1){
        vex::task::sleep(100);
    }
}