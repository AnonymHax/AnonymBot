#ifndef SPELLBOMBDATA_H
#define SPELLBOMBDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SpellBombData : public AbstractGameData
{
public:
  int getId() const;
  int getChainReactionSpellId() const;
  int getExplodSpellId() const;
  int getWallId() const;
  int getInstantSpellId() const;
  int getComboCoeff() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_chainReactionSpellId;
  int m_explodSpellId;
  int m_wallId;
  int m_instantSpellId;
  int m_comboCoeff;
};

#endif // SPELLBOMBDATA_H