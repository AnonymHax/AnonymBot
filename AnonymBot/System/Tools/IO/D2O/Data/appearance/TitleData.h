#ifndef TITLEDATA_H
#define TITLEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class TitleData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameMaleId() const;
  uint getNameFemaleId() const;
  bool getVisible() const;
  int getCategoryId() const;
  QString getNameMale() const;
  QString getNameFemale() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameMaleId;
  uint m_nameFemaleId;
  bool m_visible;
  int m_categoryId;
};

#endif // TITLEDATA_H