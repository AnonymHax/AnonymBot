#ifndef ALIGNMENTTITLEDATA_H
#define ALIGNMENTTITLEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AlignmentTitleData : public AbstractGameData
{
public:
  int getSideId() const;
  QList<int> getNamesId() const;
  QList<int> getShortsId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_sideId;
  QList<int> m_namesId;
  QList<int> m_shortsId;
};

#endif // ALIGNMENTTITLEDATA_H