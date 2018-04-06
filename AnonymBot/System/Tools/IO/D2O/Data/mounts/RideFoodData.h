#ifndef RIDEFOODDATA_H
#define RIDEFOODDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class RideFoodData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getGid() const;
  uint getTypeId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_gid;
  uint m_typeId;
};

#endif // RIDEFOODDATA_H