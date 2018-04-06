#ifndef CHALLENGEDATA_H
#define CHALLENGEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ChallengeData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  bool getDareAvailable() const;
  QList<uint> getIncompatibleChallenges() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  bool m_dareAvailable;
  QList<uint> m_incompatibleChallenges;
};

#endif // CHALLENGEDATA_H