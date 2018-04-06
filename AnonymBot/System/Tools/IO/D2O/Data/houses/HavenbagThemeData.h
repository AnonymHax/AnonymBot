#ifndef HAVENBAGTHEMEDATA_H
#define HAVENBAGTHEMEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class HavenbagThemeData : public AbstractGameData
{
public:
  int getId() const;
  int getNameId() const;
  int getMapId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_nameId;
  int m_mapId;
};

#endif // HAVENBAGTHEMEDATA_H