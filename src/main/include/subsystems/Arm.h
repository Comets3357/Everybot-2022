#pragma once

#include "Constants.h"

#include <frc/DriverStation.h>
#include <frc/PowerDistribution.h>
#include <frc/TimedRobot.h>
#include <rev/CANSparkMax.h>
#include <rev/CANEncoder.h>

struct RobotData;

struct ArmData{

};

class Arm
{
public:
    void RobotInit();
    void RobotPeriodic(const RobotData &robotData, ArmData &armData);
    void DisabledInit();
private:

    bool armUp = false;
    bool armRunning = false;

    rev::CANSparkMax arm{armDeviceID, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxRelativeEncoder armEncoder = arm.GetEncoder();
};