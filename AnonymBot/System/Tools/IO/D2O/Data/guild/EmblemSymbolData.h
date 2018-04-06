#ifndef EMBLEMSYMBOLDATA_H
#define EMBLEMSYMBOLDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class EmblemSymbolData : public AbstractGameData
{
public:
  int getId() const;
  int getIconId() const;
  int getSkinId() const;
  int getOrder() const;
  int getCategoryId() const;
  bool getColorizable() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_iconId;
  int m_skinId;
  int m_order;
  int m_categoryId;
  bool m_colorizable;
};

#endif // EMBLEMSYMBOLDATA_H