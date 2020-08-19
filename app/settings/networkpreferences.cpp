#include "networkpreferences.h"

#include <QDebug>
#include <QSettings>

NetworkPreferences::NetworkPreferences(QObject *parent) : QObject(parent) {
    reload();
}

void NetworkPreferences::save() {
    QSettings settings;

    settings.setValue("isUsingCustomPorts", isUsingCustomPorts);

    settings.setValue("customPorts_both_0", portBoth0);
    settings.setValue("customPorts_tcp_0", portTcp0);
    settings.setValue("customPorts_tcp_1", portTcp1);
    settings.setValue("customPorts_udp_0", portUdp0);
    settings.setValue("customPorts_udp_1", portUdp1);
    settings.setValue("customPorts_udp_2", portUdp2);
}

void NetworkPreferences::reload() {
    QSettings qSettings;

    isUsingCustomPorts = qSettings.value("isUsingCustomPorts", false).toBool();

    portBoth0 = isUsingCustomPorts ? qSettings.value("customPorts_both_0", 48010).toUInt() : 48010;
    portTcp0  = isUsingCustomPorts ? qSettings.value("customPorts_tcp_0", 47984).toUInt() : 47984;
    portTcp1  = isUsingCustomPorts ? qSettings.value("customPorts_tcp_1", 47989).toUInt() : 47989;
    portUdp0  = isUsingCustomPorts ? qSettings.value("customPorts_udp_0", 47998).toUInt() : 47998;
    portUdp1  = isUsingCustomPorts ? qSettings.value("customPorts_udp_1", 47999).toUInt() : 47999;
    portUdp2  = isUsingCustomPorts ? qSettings.value("customPorts_udp_2", 48000).toUInt() : 48000;

    qDebug() << "Reloading custom ports...";
}
