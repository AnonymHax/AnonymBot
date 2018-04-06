#ifndef TITLECATEGORYDATA_H
#define TITLECATEGORYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class TitleCategoryData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
};

#endif // TITLECATEGORYDATA_H