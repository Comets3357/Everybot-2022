#include "subsystems/intake.h"
#include "RobotData.h"

void Intake::RobotInit(){

    

    intake.SetInverted(true);
}

void Intake::RobotPeriodic(const RobotData &robotData, IntakeData &intakeData){
    
    //deadzone NOT needed for drone controller
    if (robotData.controlData.intakeOut)
    {
        intake.Set(VictorSPXControlMode::PercentOutput, 1);
    } else if (robotData.controlData.intakeIn){
        intake.Set(VictorSPXControlMode::PercentOutput, -1);
    } else
    {
        intake.Set(VictorSPXControlMode::PercentOutput, 0);
    }
}

void Intake::DisabledInit(){
    intake.Set(VictorSPXControlMode::PercentOutput, 0);
}