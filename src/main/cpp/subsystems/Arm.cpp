#include "subsystems/Arm.h"
#include "RobotData.h"
#include <frc/smartdashboard/SmartDashboard.h>

void Arm::RobotInit(){

    arm.RestoreFactoryDefaults();

    arm.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    arm.SetInverted(true);

    armEncoder.SetPosition(0);
}

void Arm::RobotPeriodic(const RobotData &robotData, ArmData &armData){
    if(!robotData.controlData.manualMode){
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
            if (armEncoder.GetPosition() > -15)
            {
                arm.Set(-0.1);
            } else
            {
                arm.Set(0);
                armRunning = false;
            }
        } else if (!armUp && armRunning)
        {
            if (armEncoder.GetPosition() < 0)
            {
                arm.Set(0.1);
            } else
            {
                arm.Set(0);
                armRunning = false;
            }
        } else
        {
            arm.Set(0);
        }
    } else {
        arm.Set(robotData.controlData.manualArm*.2);
    }
    // arm.Set(robotData.controllerData.sRYStick*0.1);
    // if (robotData.controllerData.sYBtn)
    // {
    //     armEncoder.SetPosition(0);
    // }
    frc::SmartDashboard::PutNumber("POS", armEncoder.GetPosition());
    frc::SmartDashboard::PutBoolean("up", armUp);
    frc::SmartDashboard::PutBoolean("run", armRunning);

    
}

void Arm::DisabledInit(){
    arm.Set(0);
}