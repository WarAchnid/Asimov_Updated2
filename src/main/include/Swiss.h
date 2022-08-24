#pragma once



using namespace frc;

class Swiss {
    public:
    Swiss(frc::XboxController *xbox);
    void Tick();

    private:
    WPI_TalonSRX *m_swiss;
    XboxController *m_xbox;

    void init(frc::XboxController *xbox);    
};