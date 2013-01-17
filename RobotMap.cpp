// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANJaguar* RobotMap::driveTrainCANJaguar1 = NULL;
CANJaguar* RobotMap::driveTrainCANJaguar2 = NULL;
CANJaguar* RobotMap::driveTrainCANJaguar3 = NULL;
CANJaguar* RobotMap::driveTrainCANJaguar4 = NULL;
Gyro* RobotMap::driveTrainGyro = NULL;
SpeedController* RobotMap::shoulderMotor = NULL;
DigitalInput* RobotMap::shoulderLimitSwitch = NULL;
SpeedController* RobotMap::elbowMotor = NULL;
SpeedController* RobotMap::gripperTopRoller = NULL;
SpeedController* RobotMap::gripperBottomRoller = NULL;
SpeedController* RobotMap::minibotDeploymentMotor = NULL;
Relay* RobotMap::towerLightsRed = NULL;
Relay* RobotMap::towerLightsWhite = NULL;
Relay* RobotMap::towerLightsBlue = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	driveTrainCANJaguar1 = new CANJaguar(2);
	
	
	driveTrainCANJaguar2 = new CANJaguar(3);
	
	
	driveTrainCANJaguar3 = new CANJaguar(4);
	
	
	driveTrainCANJaguar4 = new CANJaguar(5);
	
	
	driveTrainGyro = new Gyro(1, 3);
	lw->AddSensor("Drive Train", "Gyro", driveTrainGyro);
	driveTrainGyro->SetSensitivity(0.007);
	shoulderMotor = new Victor(1, 1);
	lw->AddActuator("Shoulder", "Motor", (Victor*) shoulderMotor);
	
	shoulderLimitSwitch = new DigitalInput(1, 1);
	lw->AddSensor("Shoulder", "Limit Switch", shoulderLimitSwitch);
	
	elbowMotor = new Victor(1, 2);
	lw->AddActuator("Elbow", "Motor", (Victor*) elbowMotor);
	
	gripperTopRoller = new Victor(1, 3);
	lw->AddActuator("Gripper", "Top Roller", (Victor*) gripperTopRoller);
	
	gripperBottomRoller = new Victor(1, 4);
	lw->AddActuator("Gripper", "Bottom Roller", (Victor*) gripperBottomRoller);
	
	minibotDeploymentMotor = new Victor(1, 5);
	lw->AddActuator("Minibot Deployment", "Motor", (Victor*) minibotDeploymentMotor);
	
	towerLightsRed = new Relay(1, 1);
	lw->AddActuator("Tower Lights", "Red", towerLightsRed);
	
	towerLightsWhite = new Relay(1, 2);
	lw->AddActuator("Tower Lights", "White", towerLightsWhite);
	
	towerLightsBlue = new Relay(1, 3);
	lw->AddActuator("Tower Lights", "Blue", towerLightsBlue);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
