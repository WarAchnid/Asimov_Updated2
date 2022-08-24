#pragma once

#include "Robot.h"

class DalekDrive {
    public:
    DalekDrive(frc::XboxController *xbox);
    double squareInput(double v);
    void TankDrive(double l, double r, bool squaredInputs);
    void TankDrive(frc::Joystick& leftStick, frc::Joystick& rightStick, bool squaredInputs);
    void TankDrive(frc::Joystick* leftStick, frc::Joystick* rightStick, bool squaredInputs);
    void Tick();

    private:
    enum Motors {rightFront = 1, rightRear, leftFront, leftRear};
    enum Sides {FRONT, REAR};
    frc::Joystick *m_leftStick;
    frc::Joystick *m_rightStick;
    WPI_TalonSRX *m_left[3];
    WPI_TalonSRX *m_right[1];
};