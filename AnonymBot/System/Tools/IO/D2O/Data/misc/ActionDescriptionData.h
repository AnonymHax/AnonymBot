#ifndef ACTIONDESCRIPTIONDATA_H
#define ACTIONDESCRIPTIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ActionDescriptionData : public AbstractGameData
{
public:
  uint getId() const;
  uint getTypeId() const;
  QString getName() const;
  uint getDescriptionId() const;
  bool getTrusted() const;
  bool getNeedInteraction() const;
  uint getMaxUsePerFrame() const;
  uint getMinimalUseInterval() const;
  bool getNeedConfirmation() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_typeId;
  QString m_name;
  uint m_descriptionId;
  bool m_trusted;
  bool m_needInteraction;
  uint m_maxUsePerFrame;
  uint m_minimalUseInterval;
  bool m_needConfirmation;
};

#endif // ACTIONDESCRIPTIONDATA_H