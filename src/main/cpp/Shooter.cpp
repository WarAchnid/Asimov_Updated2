#include "Robot.h"

Shooter::Shooter (frc::XboxController *xbox)
{
    init(xbox);
}

void
Shooter::init (frc::XboxController *xbox)
{
    m_xbox = xbox;
    m_shooter = new WPI_TalonSRX(SHOOTER);
    if(m_shooter == NULL)
        std::bad_alloc();
}

//Shoot: 
//Unshoot: 
void
Shooter::Tick() {
    if (m_xbox->GetAButton()) {
        m_shooter->Set(0.65);
    }
    else if (m_xbox->GetBButton()) {
        m_shooter->Set(-0.65);
    }
    else {
        m_shooter->Set(0.0);
    }
}