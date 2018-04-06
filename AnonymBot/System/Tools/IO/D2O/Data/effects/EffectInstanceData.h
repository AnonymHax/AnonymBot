#ifndef EFFECTINSTANCEDATA_H
#define EFFECTINSTANCEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class EffectInstanceData : public AbstractGameData
{
public:
  uint getEffectUid() const;
  uint getEffectId() const;
  int getTargetId() const;
  QString getTargetMask() const;
  int getDuration() const;
  int getDelay() const;
  int getRandom() const;
  int getGroup() const;
  int getModificator() const;
  bool getTrigger() const;
  QString getTriggers() const;
  bool getVisibleInTooltip() const;
  bool getVisibleInBuffUi() const;
  bool getVisibleInFightLog() const;
  uint getZoneShape() const;
  int getEffectElement() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_effectUid;
  uint m_effectId;
  int m_targetId;
  QString m_targetMask;
  int m_duration;
  int m_delay;
  int m_random;
  int m_group;
  int m_modificator;
  bool m_trigger;
  QString m_triggers;
  bool m_visibleInTooltip;
  bool m_visibleInBuffUi;
  bool m_visibleInFightLog;
  uint m_zoneShape;
  int m_effectElement;
};

#endif // EFFECTINSTANCEDATA_H