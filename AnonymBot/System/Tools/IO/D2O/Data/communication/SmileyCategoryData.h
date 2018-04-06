#ifndef SMILEYCATEGORYDATA_H
#define SMILEYCATEGORYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SmileyCategoryData : public AbstractGameData
{
public:
  int getId() const;
  uint getOrder() const;
  QString getGfxId() const;
  bool getIsFake() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_order;
  QString m_gfxId;
  bool m_isFake;
};

#endif // SMILEYCATEGORYDATA_H