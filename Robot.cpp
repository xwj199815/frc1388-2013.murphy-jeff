// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.

#include "Robot.h"
#include "GitVersion.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveTrain* Robot::driveTrain = 0;
Shoulder* Robot::shoulder = 0;
Elbow* Robot::elbow = 0;
Gripper* Robot::gripper = 0;
MinibotDeployment* Robot::minibotDeployment = 0;
TowerLights* Robot::towerLights = 0;
OI* Robot::oi = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

//SmartScope* Robot::testScope = 0;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrain = new DriveTrain();
	shoulder = new Shoulder();
	elbow = new Elbow();
	gripper = new Gripper();
	minibotDeployment = new MinibotDeployment();
	towerLights = new TowerLights();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
//	testScope = new SmartScope("Test Scope", 100);
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	
	// Display on NetConsole:
	printf("\nSW version: %s\n\n", GIT_VERSION);
	
	// Display on SmartDashboard:
	string GitVersion = GIT_VERSION;
	if (strlen(GIT_TAG)) {
		GitVersion += " (";
		GitVersion += GIT_TAG;
		GitVersion += ")";
	}
	SmartDashboard::PutString("Software Version: ", GitVersion);
  }
	
void Robot::AutonomousInit() {
	// initally turn off tower lights
	RobotMap::towerLightsRed->Set(Relay::kOff);
	RobotMap::towerLightsWht->Set(Relay::kOff);
	RobotMap::towerLightsBlu->Set(Relay::kOff);

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
	
	// initally turn off tower lights
	RobotMap::towerLightsRed->Set(Relay::kOff);
	RobotMap::towerLightsWht->Set(Relay::kOff);
	RobotMap::towerLightsBlu->Set(Relay::kOff);
}
	
void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
