#pragma once

#include "Robot.h"

using namespace rev;

DalekDrive::DalekDrive(frc::XboxController *xbox) {
	m_leftStick    = new frc::Joystick(LEFT_STICK);
	m_rightStick   = new frc::Joystick(RIGHT_STICK);
	m_left[FRONT]  = new WPI_TalonSRX(leftFront);
	m_left[REAR]   = new WPI_TalonSRX(leftRear);
	m_right[FRONT] = new WPI_TalonSRX(rightFront);
	m_right[REAR]  = new WPI_TalonSRX(rightRear);
}

double
DalekDrive::squareInput(double v)
{
	if (v < 0.0) {
		return -(v * v);
	}
	return (v * v);
}

void
DalekDrive::TankDrive(double l, double r, bool squaredInputs)
{
	if(squaredInputs) {
		l = squareInput(l);
		r = squareInput(r);
	}
	m_left[FRONT]->Set(l);
	m_left[REAR]->Set(l);
	m_right[FRONT]->Set(r * -1.0);
	m_right[REAR]->Set(r * -1.0);
}

void
DalekDrive::TankDrive(Joystick* leftStick, Joystick* rightStick, bool squaredInputs)
{
	TankDrive(leftStick->GetY(), rightStick->GetY(), squaredInputs);
}

void
DalekDrive::TankDrive(Joystick& leftStick, Joystick& rightStick, bool squaredInputs)
{
	TankDrive(leftStick.GetY(), rightStick.GetY(), squaredInputs);
}

void
DalekDrive::Tick()
{
	TankDrive(m_leftStick, m_rightStick, false);
}