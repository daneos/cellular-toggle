#include "cellulartoggle.h"


CellularToggle::CellularToggle(QObject *parent) : QObject(parent)
{
    this->radio = new Cellular::RadioAccess;
    getCellularState();
}

void CellularToggle::onToggleClicked(void)
{
    switch(this->state)
    {
        case STATE_2G:
            this->setDual();
            break;
        case STATE_3G:
        case STATE_DUAL:
            this->set2G();
            break;
    }
}

void CellularToggle::onToggleLongPressed(void)
{
    this->set3G();
}

void CellularToggle::set2G(void)
{
    this->state = STATE_2G;
    this->setMode();
}

void CellularToggle::set3G(void)
{
    this->state = STATE_3G;
    this->setMode();
}

void CellularToggle::setDual(void)
{
    this->state = STATE_DUAL;
    this->setMode();
}

void CellularToggle::setMode(void)
{
    this->radio->setMode(this->state);
    this->propagateChanges();
}

void CellularToggle::propagateChanges(void)
{
    emit this->stateChanged(this->state);
    emit this->iconChanged(toggleIcon());
}

void CellularToggle::getCellularState(void)
{
    this->state = this->radio->mode();
    this->propagateChanges();
}

void CellularToggle::onStateChanged(Cellular::RadioAccess::Mode state)
{
    this->state = state;
    this->propagateChanges();
}

QImage CellularToggle::toggleIcon(void)
{
    switch(this->state)
    {
        case STATE_2G:
            return QImage(ICON_2G);
            break;
        case STATE_3G:
            return QImage(ICON_3G);
            break;
        case STATE_DUAL:
            return QImage(ICON_DUAL);
            break;
        default:
        return QImage(ICON_ERROR);
    }
}

Q_EXPORT_PLUGIN2(cellulartoggle, CellularToggle)
