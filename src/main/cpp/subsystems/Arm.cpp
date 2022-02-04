#include "subsystems/Arm.h"
#include "RobotData.h"

void Arm::RobotInit(){

    arm.RestoreFactoryDefaults();

    arm.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    arm.SetInverted(true);
}

void Arm::RobotPeriodic(const RobotData &robotData, ArmData &armData){

    //deadzone NOT needed for drone controller
    if (robotData.controlData.arm <= -0.08 || robotData.controlData.arm >= 0.08)
    {
        arm.Set(robotData.controlData.arm*0.1);
    } else {
        arm.Set(0);
    }

    if (robotData.controlData.arm)
    {
        armUp = !armUp;
        armRunning = true;
    }

    if (armUp && armRunning)
    {
        if (armEncoder.GetPosition() > -100)
        {
            arm.Set(-0.1);
        } else
        {
            arm.Set(0);
        }
    } else if (!armUp && armRunning)
    {
        if (armEncoder.GetPosition() < 0)
        {
            arm.Set(0.1);
        } else
        {
            arm.Set(0);
        }
    } else
    {
        arm.Set(0);
    }
}

void Arm::DisabledInit(){
    arm.Set(0);
}