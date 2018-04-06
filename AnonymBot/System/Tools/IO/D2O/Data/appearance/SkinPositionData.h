#ifndef SKINPOSITIONDATA_H
#define SKINPOSITIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SkinPositionData : public AbstractGameData
{
public:
  uint getId() const;
  QList<QString> getClip() const;
  QList<uint> getSkin() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  QList<QString> m_clip;
  QList<uint> m_skin;
};

#endif // SKINPOSITIONDATA_H