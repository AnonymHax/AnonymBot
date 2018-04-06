#ifndef ALIGNMENTRANKJNTGIFTDATA_H
#define ALIGNMENTRANKJNTGIFTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AlignmentRankJntGiftData : public AbstractGameData
{
public:
  int getId() const;
  QList<int> getGifts() const;
  QList<int> getParameters() const;
  QList<int> getLevels() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QList<int> m_gifts;
  QList<int> m_parameters;
  QList<int> m_levels;
};

#endif // ALIGNMENTRANKJNTGIFTDATA_H