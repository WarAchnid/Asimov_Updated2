#pragma once



using namespace frc;

class Shooter {
    public:
    Shooter(frc::XboxController *xbox);
    void Tick();

    private:
    WPI_TalonSRX *m_shooter;
    XboxController *m_xbox;

    void init(frc::XboxController *xbox);    
};