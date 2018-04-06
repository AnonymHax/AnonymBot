#ifndef CENSOREDCONTENTDATA_H
#define CENSOREDCONTENTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CensoredContentData : public AbstractGameData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // CENSOREDCONTENTDATA_H