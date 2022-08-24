#pragma once

using namespace frc;

class Intake {
    public:
    Intake (frc::XboxController *xbox);
    void Tick();

    private:
    WPI_TalonSRX *m_intake;
    XboxController *m_xbox;

    void init(frc::XboxController *xbox);    
};