#ifndef CELLULARTOGGLE_H
#define CELLULARTOGGLE_H

#include "system-ui-cellular-toggle_global.h"

#include "mtabstracttoggle.h"

#include <QIcon>
#include <QImage>
#include <QtPlugin>
#include <QDebug>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>
#include <QDBusInterface>
#include <cellular-qt/CellularQt/radioaccess.h>

#include <qmsystem2/qmdevicemode.h>
#include <mce/dbus-names.h>
#include <mce/mode-names.h>

// can't get Cellular::RadioAccess::Mode enum working, simple but ugly hack
#define STATE_2G        (Cellular::RadioAccess::Mode)1
#define STATE_3G        (Cellular::RadioAccess::Mode)2
#define STATE_DUAL      (Cellular::RadioAccess::Mode)0

#define ICON_2G         "icons/icon-cellular-2g.png"
#define ICON_3G         "icons/icon-cellular-3g.png"
#define ICON_DUAL       "icons/icon-cellular-dual.png"
#define ICON_ERROR      "icons/icon-cellular-error.png"

class SYSTEMUICELLULARTOGGLESHARED_EXPORT CellularToggle : public QObject, public MTAbstractToggle
{
    Q_OBJECT
    Q_INTERFACES(MTAbstractToggle)

public:
    CellularToggle(QObject *parent = NULL);
    ~CellularToggle(void)           { delete this->radio; }

    bool isToggle(void)             { return false; }
    QString toggleName(void)        { return "Cellular Mode Toggle"; }
    QString toggleDeveloper(void)   { return "daneos"; }
    QUrl toggleSupportUrl(void)     { return QUrl("http://github.com/daneos/"); }
    QImage toggleIcon(void);
    QString toggleIconId(void)      { return QString(); }
    bool isActive(void)             { return true; }

public slots:
    void onToggleClicked(void);
    void onToggleLongPressed(void);

signals:
    void stateChanged(Cellular::RadioAccess::Mode state);
    void iconChanged(QImage icon);
    void iconChanged(QString iconId);
    void isWorkingStateChanged(bool working);
    void hideStatusMenu(void);

private:
    Cellular::RadioAccess *radio;
    Cellular::RadioAccess::Mode state;

private:
    void set2G(void);
    void set3G(void);
    void setDual(void);

    void setMode(void);
    void propagateChanges(void);

private slots:
    void getCellularState(void);
    void onStateChanged(Cellular::RadioAccess::Mode state);
};

#endif // CELLULARTOGGLE_H
