#ifndef ABSTRACTPARSER_H
#define ABSTRACTPARSER_H

#include "AbstractSerializer.h"

class AbstractParser
{
public:
    AbstractParser(const QString &input);
    virtual ~AbstractParser();

    virtual void parse() = 0;

protected:
    QString m_input;
};

#endif // ABSTRACTPARSER_H
