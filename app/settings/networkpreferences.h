#ifndef NETWORKPREFERENCES_H
#    define NETWORKPREFERENCES_H

#    include <QObject>

class NetworkPreferences : public QObject {
    Q_OBJECT
public:
    NetworkPreferences(QObject *parent = nullptr);

    Q_INVOKABLE void save();
    void             reload();

    Q_PROPERTY(bool isUsingCustomPorts MEMBER isUsingCustomPorts NOTIFY usingCustomPortChanged)
    Q_PROPERTY(unsigned short portBoth0 MEMBER portBoth0 NOTIFY customPortChanged)
    Q_PROPERTY(unsigned short portTcp0 MEMBER portTcp0 NOTIFY customPortChanged)
    Q_PROPERTY(unsigned short portTcp1 MEMBER portTcp1 NOTIFY customPortChanged)
    Q_PROPERTY(unsigned short portUdp0 MEMBER portUdp0 NOTIFY customPortChanged)
    Q_PROPERTY(unsigned short portUdp1 MEMBER portUdp1 NOTIFY customPortChanged)
    Q_PROPERTY(unsigned short portUdp2 MEMBER portUdp2 NOTIFY customPortChanged)

    bool           isUsingCustomPorts;
    unsigned short portBoth0, portTcp0, portTcp1, portUdp0, portUdp1, portUdp2;

signals:
    void usingCustomPortChanged();
    void customPortChanged();
};

#endif    // NETWORKPREFERENCES_H

/*
Edits:
    "app/backend/nvapp.h"(3): Include header file "settings/networkpreferences.h"

    "app/backend/nvcomputer.cpp"(142, 143, 144, 146): apply custom ports to variable "WOL_PORTS"
    "app/backend/nvcomputer.cpp"(214): Using "networkPreferences.portTcp0"
    "app/backend/nvcomputer.h"(22): Private instantiation "networkPreferences" of class "NetworkPreferences"

    "app/backend/nvhttp.cpp"(24): Using "networkPreferences.portTcp1"
    "app/backend/nvhttp.cpp"(25): Using "networkPreferences.portTcp0"
    "app/backend/nvhttp.h"(101): Private instantiation "networkPreferences" of class "NetworkPreferences"

    "app/streaming/session.cpp"(806, 807, 808, 809, 810, 811): apply custom ports to variable "hostInfo"
    "app/streaming/session.h"(101): Private instantiation "networkPreferences" of class "NetworkPreferences"

    "moonlight-common-c/src/AudioStream.c"(74): Using "ServerInfo.portUdp2"

    "moonlight-common-c/src/Connection.c"(190): init external variable "ServerInfo"
    "moonlight-common-c/src/Connection.c"(252): Using "ServerInfo->portTcp0"

    "moonlight-common-c/src/ControlStream.c"(759, 782): Using "ServerInfo.portUdp1"

    "moonlight-common-c/src/Limelight.h"(400, 403, 406, 409, 412, 415): Add custom ports variables to struct "_SERVER_INFORMATION"
    "moonlight-common-c/src/Limelight-internal.h"(19): External instantiation "ServerInfo" of struct "_SERVER_INFORMATION"

    "moonlight-common-c/src/RtspConnection.c"(201, 548, 573, 590): Using "ServerInfo.portBoth0"

    "moonlight-common-c/src/SdpGenerator.c"(123): Using "ServerInfo.portBoth0"
    "moonlight-common-c/src/SdpGenerator.c"(384): Using "ServerInfo.portUdp0"

    "moonlight-common-c/src/VideoStream.c"(50): Using "ServerInfo.portUdp0"
*/

/*
Edited Functions:
    Custom Port On 48010(portBoth0):
        - NvComputer::wake
        - LiGetPortFlagsFromStage // TODO: change macros, add parameters.
        - LiGetPortFromPortFlagIndex // TODO: change macros, add parameters.
        - "Limelight.h" // TODO: change macros, add parameters
        - transactRtspMessageTcp -> transactRtspMessage ->
            - requestOptions
            - requestDescribe
            - setupStream
            - playStream
            - sendVideoAnnounce
        - performRtspHandshake -> LiStartConnection -> startConnectionAsync
        - addGen4Options -> getAttributesList -> getSdpPayloadForStreamConfig -> sendVideoAnnounce
    Custom Port On 47984(portTcp0):
        - fetchServerInfo -> LiTestClientConnectivity // TODO: change macros, add parameters.
        - NvComputer::isReachableOverVpn
        - NvHTTP::NvHTTP
        - LiStartConnection -> startConnectionAsync
        - LiGetPortFlagsFromStage // TODO: change macros, add parameters.
        - LiGetPortFromPortFlagIndex // TODO: change macros, add parameters.
        - "Limelight.h" // TODO: change macros, add parameters
    Custom Port On 47989(portTcp1):
        - fetchServerInfo -> LiTestClientConnectivity // TODO: change macros, add parameters.
        - NvHTTP::NvHTTP
        - LiGetPortFlagsFromStage // TODO: change macros, add parameters.
        - LiGetPortFromPortFlagIndex // TODO: change macros, add parameters.
        - "Limelight.h" // TODO: change macros, add parameters
    Custom Port On 47998(portUdp0):
        - NvComputer::wake
        - LiGetPortFlagsFromStage // TODO: change macros, add parameters.
        - LiGetPortFromPortFlagIndex // TODO: change macros, add parameters.
        - "Limelight.h" // TODO: change macros, add parameters
        - fillSdpTail -> getSdpPayloadForStreamConfig -> sendVideoAnnounce -> performRtspHandshake -> LiStartConnection -> startConnectionAsync
        - "VideoStream.c"RTP_PORT -> UdpPingThreadProc -> PltCreateThread -> startVideoStream -> LiStartConnection -> startConnectionAsync
    Custom Port On 47999(portUdp1):
        - NvComputer::wake
        - LiGetPortFlagsFromStage // TODO: change macros, add parameters.
        - LiGetPortFromPortFlagIndex // TODO: change macros, add parameters.
        - startControlStream -> LiStartConnection -> startConnectionAsync
        - "Limelight.h" // TODO: change macros, add parameters
    Custom Port On 48000(portUdp2):
        - NvComputer::wake
        - "AudioStream.c"RTP_PORT -> UdpPingThreadProc -> PltCreateThread -> startAudioStream -> LiStartConnection -> startConnectionAsync
        - LiGetPortFlagsFromTerminationErrorCode // TODO: change macros, add parameters.
        - LiGetPortFromPortFlagIndex // TODO: change macros, add parameters.
        - "Limelight.h" // TODO: change macros, add parameters
*/
