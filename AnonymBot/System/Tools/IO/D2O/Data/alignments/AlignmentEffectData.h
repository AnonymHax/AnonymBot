#ifndef ALIGNMENTEFFECTDATA_H
#define ALIGNMENTEFFECTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AlignmentEffectData : public AbstractGameData
{
public:
  int getId() const;
  uint getCharacteristicId() const;
  uint getDescriptionId() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_characteristicId;
  uint m_descriptionId;
};

#endif // ALIGNMENTEFFECTDATA_H