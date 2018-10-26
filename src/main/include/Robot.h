/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <Drive/DifferentialDrive.h>
#include <Joystick.h>
#include <SampleRobot.h>
#include <SmartDashboard/SendableChooser.h>
//#include <Spark.h>  deleted by del  
#include <ctre/Phoenix.h>  // added by del

/**
 * This is a demo program showing the use of the DifferentialDrive class. The
 * SampleRobot class is the base of a robot application that will automatically
 * call your Autonomous and OperatorControl methods at the right time as
 * controlled by the switches on the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use IterativeRobot or Command-Based
 * instead if you're new.
 */
class Robot : public frc::SampleRobot {
 public:
  Robot();

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
  // Robot drive system

  //frc::Spark m_leftMotor{1}; deleted by del
  //frc::Spark m_rightMotor{2};  deleted by del

  // motorcontrollers with CAN ID 1,2
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_leftMotor{0};  // added by del
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX m_rightMotor{1}; // added by del

  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};

  frc::Joystick m_stick{0};

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
};
