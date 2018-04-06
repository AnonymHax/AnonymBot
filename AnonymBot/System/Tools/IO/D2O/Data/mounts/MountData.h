#ifndef MOUNTDATA_H
#define MOUNTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class MountData : public AbstractGameData
{
public:
  uint getId() const;
  uint getFamilyId() const;
  uint getNameId() const;
  QString getLook() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_familyId;
  uint m_nameId;
  QString m_look;
};

#endif // MOUNTDATA_H