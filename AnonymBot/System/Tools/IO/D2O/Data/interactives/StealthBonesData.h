#ifndef STEALTHBONESDATA_H
#define STEALTHBONESDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class StealthBonesData : public AbstractGameData
{
public:
  uint getId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
};

#endif // STEALTHBONESDATA_H