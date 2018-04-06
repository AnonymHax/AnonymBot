#ifndef CREATUREBONEOVERRIDEDATA_H
#define CREATUREBONEOVERRIDEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CreatureBoneOverrideData : public AbstractGameData
{
public:
  int getBoneId() const;
  int getCreatureBoneId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_boneId;
  int m_creatureBoneId;
};

#endif // CREATUREBONEOVERRIDEDATA_H