#ifndef LOGOUTPUT_H
#define LOGOUTPUT_H

#include "Public.h"
#include "System/Tools/IO/Reader.h"

enum Channel
{
    CHANNELALERT = -2,
    CHANNELDEBUG = -1,
    CHANNELGLOBAL = 0,
    CHANNELTEAM = 1,
    CHANNELGUILD = 2,
    CHANNELALLIANCE = 3,
    CHANNELPARTY = 4,
    CHANNELSALES = 5,
    CHANNELSEEK = 6,
    CHANNELNOOB = 7,
    CHANNELADMIN = 8,
    CHANNELADS = 14,
    CHANNELARENA = 13,
    CHANNELPRIVATE = 9,
    CHANNELINFO = 10,
    CHANNELFIGHTLOG = 11,
    CHANNELACTION = 12
};

struct LogMessage
{
    QString output;
    Channel channel;
    uint timeStamp = 0;
};


bool operator==(const LogMessage& left, const LogMessage& right);
bool operator!=(const LogMessage& left, const LogMessage& right);


class LogOutput
{
public:
    void setTarget(LogMessage *target, Channel channel);

    LogOutput &operator<<(const QString &source);
    LogOutput &operator<<(const char *source);
    LogOutput &operator<<(const int &source);
    LogOutput &operator<<(const uint &source);
    LogOutput &operator<<(const short &source);
    LogOutput &operator<<(const ushort &source);
    LogOutput &operator<<(const double &source);
    LogOutput &operator<<(const bool &source);
    LogOutput &operator<<(const std::ostream &source);

    bool operator=(const QString &source);

    void initCall();

private:
    void initInput();

    LogMessage *m_target;
};

#endif // LOGOUTPUT_H
