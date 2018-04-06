#ifndef TYPEACTIONDATA_H
#define TYPEACTIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class TypeActionData : public AbstractGameData
{
public:
  int getId() const;
  QString getElementName() const;
  int getElementId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QString m_elementName;
  int m_elementId;
};

#endif // TYPEACTIONDATA_H