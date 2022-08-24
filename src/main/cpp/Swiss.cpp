#include "Robot.h"

Swiss::Swiss (frc::XboxController *xbox)
{
    init(xbox);
}

void
Swiss::init (frc::XboxController *xbox)
{
    m_xbox = xbox;
    m_swiss = new WPI_TalonSRX(SWISS);
    if(m_swiss == NULL)
        std::bad_alloc();
}

void
Swiss::Tick() {
    if (m_xbox->GetStartButton()) {
        m_swiss->Set(1.0);
    }
    else if (m_xbox->GetBackButton()) {
        m_swiss->Set(-1.0);
    }
    else {
        m_swiss->Set(0.0);
    }
}