#ifndef POINTOFINTERESTCATEGORYDATA_H
#define POINTOFINTERESTCATEGORYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class PointOfInterestCategoryData : public AbstractGameData
{
public:
  uint getId() const;
  uint getActionLabelId() const;
  QString getActionLabel() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_actionLabelId;
};

#endif // POINTOFINTERESTCATEGORYDATA_H