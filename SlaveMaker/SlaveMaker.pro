#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T00:16:06
#
#-------------------------------------------------

CONFIG +=c++11

QMAKE_MAC_SDK = macosx10.11
QMAKE_CXXFLAGS_DEBUG -= -O
QMAKE_CXXFLAGS_RELEASE += -O3

QT += network core sql

TARGET = SlaveMaker


HEADERS += \
    IO/Reader.h \
    IO/Writer.h \
    Network/DofusMessages/AbstractDofusMessage.h \
    Network/DofusMessages/CheckIntegrityMessage.h \
    Network/DofusMessages/DofusBuffer.h \
    Network/DofusMessages/DofusMessageEnum.h \
    Network/DofusMessages/DofusServer.h \
    Network/DofusMessages/RawDataMessage.h \
    Network/ServerMessages/AbstractServerMessage.h \
    Network/ServerMessages/ServerBuffer.h \
    Network/ServerMessages/ServerMessageEnum.h \
    Controller.h \
    Public.h \
    Network/ServerMessages/RawResolveRequestMessage.h \
    Network/ServerMessages/RawResolveMessage.h \
    Network/ServerMessages/RawResolveFailureMessage.h \
    Network/ServerMessages/ConnectionRequestMessage.h \
    Network/ServerMessages/ConnectionFailureMessage.h \
    Network/ServerMessages/ConnectionSuccessMessage.h \
    Network/ServerMessages/ForceDisconnectionMessage.h \
    Network/ServerMessages/SecureServer.h \
    Network/ServerMessages/ClientUpdateMessage.h \
    Network/ServerMessages/ServerUpdateMessage.h \
    Network/DofusMessages/BasicLatencyStatsRequestMessage.h

SOURCES += \
    IO/Reader.cpp \
    IO/Writer.cpp \
    Network/DofusMessages/CheckIntegrityMessage.cpp \
    Network/DofusMessages/DofusBuffer.cpp \
    Network/DofusMessages/DofusServer.cpp \
    Network/DofusMessages/RawDataMessage.cpp \
    Network/ServerMessages/ServerBuffer.cpp \
    Controller.cpp \
    main.cpp \
    Public.cpp \
    Network/ServerMessages/RawResolveRequestMessage.cpp \
    Network/ServerMessages/RawResolveMessage.cpp \
    Network/ServerMessages/RawResolveFailureMessage.cpp \
    Network/ServerMessages/ConnectionRequestMessage.cpp \
    Network/ServerMessages/ConnectionFailureMessage.cpp \
    Network/ServerMessages/ConnectionSuccessMessage.cpp \
    Network/ServerMessages/ForceDisconnectionMessage.cpp \
    Network/ServerMessages/SecureServer.cpp \
    Network/ServerMessages/ClientUpdateMessage.cpp \
    Network/ServerMessages/ServerUpdateMessage.cpp \
    Network/DofusMessages/BasicLatencyStatsRequestMessage.cpp

RESOURCES += \
    Resources.qrc


