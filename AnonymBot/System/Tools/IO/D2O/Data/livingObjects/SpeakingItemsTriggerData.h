#ifndef SPEAKINGITEMSTRIGGERDATA_H
#define SPEAKINGITEMSTRIGGERDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SpeakingItemsTriggerData : public AbstractGameData
{
public:
  int getTriggersId() const;
  QList<int> getTextIds() const;
  QList<int> getStates() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_triggersId;
  QList<int> m_textIds;
  QList<int> m_states;
};

#endif // SPEAKINGITEMSTRIGGERDATA_H