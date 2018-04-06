#ifndef DARECRITERIADATA_H
#define DARECRITERIADATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class DareCriteriaData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getMaxOccurence() const;
  uint getMaxParameters() const;
  int getMinParameterBound() const;
  int getMaxParameterBound() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_maxOccurence;
  uint m_maxParameters;
  int m_minParameterBound;
  int m_maxParameterBound;
};

#endif // DARECRITERIADATA_H