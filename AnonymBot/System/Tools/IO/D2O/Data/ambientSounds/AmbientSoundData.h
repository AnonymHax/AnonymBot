#ifndef AMBIENTSOUNDDATA_H
#define AMBIENTSOUNDDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/ambientSounds/PlaylistSoundData.h"

class AmbientSoundData : public PlaylistSoundData
{
public:
  int getCriterionId() const;
  uint getSilenceMin() const;
  uint getSilenceMax() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_criterionId;
  uint m_silenceMin;
  uint m_silenceMax;
};

#endif // AMBIENTSOUNDDATA_H