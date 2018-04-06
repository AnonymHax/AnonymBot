#ifndef DATACONVERTER_H
#define DATACONVERTER_H

#include "Public.h"
#include "DataLocalizer.h"

class DataConverter : public AbstractSerializer
{
public:
    DataConverter( const QString &output, DataLocalizer *localizer);
    ~DataConverter();

    virtual void serialize();
    virtual void write();

private:
    SourceSerializer *m_source;
    DataLocalizer *m_localizer;
};

#endif // DATACONVERTER_H
