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
    //go fwd
    LeftMotor.spin(directionType::forward,60,velocityUnits::pct);
    RightMotor.spin(directionType::reverse,60,velocityUnits::pct);
    task::sleep(1500);
    LeftMotor.stop(brakeType::brake);
    RightMotor.stop(brakeType::brake);
    //turn right
    RightMotor.spinFor(directionType::fwd,700,rotationUnits::degrees);
    //go fwd
    LeftMotor.spin(directionType::forward,60,velocityUnits::pct);
    RightMotor.spin(directionType::reverse,60,velocityUnits::pct);
    task::sleep(1500);
    LeftMotor.stop(brakeType::brake);
    RightMotor.stop(brakeType::brake);
    //start liftMotor
    ArmLiftMotor.spin(forward,60,pct);
    task::sleep(1000);
    //hold it
    ArmLiftMotor.stop(brakeType::hold);
    //go rev
    LeftMotor.spin(directionType::reverse,60,velocityUnits::pct);
    RightMotor.spin(directionType::forward,60,velocityUnits::pct);
    task::sleep(1500);
    LeftMotor.stop(brakeType::brake);
    RightMotor.stop(brakeType::brake);
}

void usercontrol(void){

    
    while(1){
        //tank mode drive program
        RightMotor.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
        LeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
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