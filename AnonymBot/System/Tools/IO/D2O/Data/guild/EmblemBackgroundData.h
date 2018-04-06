#ifndef EMBLEMBACKGROUNDDATA_H
#define EMBLEMBACKGROUNDDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class EmblemBackgroundData : public AbstractGameData
{
public:
  int getId() const;
  int getOrder() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_order;
};

#endif // EMBLEMBACKGROUNDDATA_H