#pragma once

#include "Constants.h"

#include <frc/DriverStation.h>
#include <frc/PowerDistribution.h>
#include <frc/TimedRobot.h>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>

#include <ctre/Phoenix.h>

struct RobotData;

struct IntakeData{

};

class Intake
{
public:
    void RobotInit();
    void RobotPeriodic(const RobotData &robotData, IntakeData &IntakeData);
    void DisabledInit();
private:
    
    VictorSPX intake = VictorSPX{intakeDeviceID};
    
};