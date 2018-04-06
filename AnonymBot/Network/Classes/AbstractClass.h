#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H

#include "Public.h"
#include "Network/Classes/ClassEnum.h"
#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/Writer.h"

class AbstractClass
{
public:
    virtual void serialize(Writer *writer) = 0;
    virtual void deserialize(Reader *reader) = 0;
    QList<ClassEnum> getTypes() const
    {return m_types;}
    virtual ~AbstractClass()
    {}

protected:
    QList<ClassEnum> m_types;
};

#endif // ABSTRACTCLASS_H