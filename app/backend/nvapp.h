#pragma once

#include "../settings/networkpreferences.h"

#include <QSettings>

class NvApp {
public:
    NvApp() {}
    explicit NvApp(QSettings &settings);

    bool operator==(const NvApp &other) const { return id == other.id && name == other.name && hdrSupported == other.hdrSupported && isAppCollectorGame == other.isAppCollectorGame && hidden == other.hidden; }

    bool operator!=(const NvApp &other) const { return !operator==(other); }

    bool isInitialized() { return id != 0 && !name.isEmpty(); }

    void serialize(QSettings &settings) const;

    int     id = 0;
    QString name;
    bool    hdrSupported       = false;
    bool    isAppCollectorGame = false;
    bool    hidden             = false;
};

Q_DECLARE_METATYPE(NvApp)
