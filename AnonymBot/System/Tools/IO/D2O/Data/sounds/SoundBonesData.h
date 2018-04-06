#ifndef SOUNDBONESDATA_H
#define SOUNDBONESDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/sounds/SoundAnimationData.h"

class SoundBonesData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QList<QString> getKeys() const;
  QList<QList<SoundAnimationData>> getValues() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QList<QString> m_keys;
  QList<QList<SoundAnimationData>> m_values;
};

#endif // SOUNDBONESDATA_H