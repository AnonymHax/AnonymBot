#include "LogOutput.h"

// logMessage

bool operator==(const LogMessage &left, const LogMessage &right)
{
    if (left.channel == right.channel)
        if (left.output == right.output)
            return true;

    return false;
}

bool operator!=(const LogMessage& left, const LogMessage& right)
{
    return !(left == right);
}

// logOutput

void LogOutput::setTarget(LogMessage *target, Channel channel)
{
    m_target = target;
    m_target->channel = channel;
}

LogOutput &LogOutput::operator<<(const QString &source)
{
    initInput();
    m_target->output += source;
    return *this;
}

LogOutput &LogOutput::operator<<(const char *source)
{
    initInput();
    m_target->output += Reader(source, strlen(source)).readUTFBytes();
    return *this;
}

LogOutput &LogOutput::operator<<(const int &source)
{
    initInput();
    m_target->output += QString::number(source);
    return *this;
}

LogOutput &LogOutput::operator<<(const uint &source)
{
    initInput();
    m_target->output += QString::number(source);
    return *this;
}

LogOutput &LogOutput::operator<<(const short &source)
{
    initInput();
    m_target->output += QString::number(source);
    return *this;
}

LogOutput &LogOutput::operator<<(const ushort &source)
{
    initInput();
    m_target->output += QString::number(source);
    return *this;
}

LogOutput &LogOutput::operator<<(const double &source)
{
    initInput();
    m_target->output += QString::number(source);
    return *this;
}

LogOutput &LogOutput::operator<<(const bool &source)
{
    initInput();
    if (source)
        m_target->output += "1";
    else
        m_target->output += "0";
    return *this;
}

bool LogOutput::operator=(const QString &source)
{
    m_target->output = source;
}

void LogOutput::initCall()
{
    m_target->timeStamp = QDateTime::currentDateTime().toTime_t();

    if (!m_target->output.isEmpty())
        m_target->output += '\n';
}

void LogOutput::initInput()
{
    m_target->output += ' ';
}
