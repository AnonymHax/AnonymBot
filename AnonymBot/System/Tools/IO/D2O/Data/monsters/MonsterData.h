#ifndef MONSTERDATA_H
#define MONSTERDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterGradeData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterDropData.h"

class MonsterData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getGfxId() const;
  int getRace() const;
  QList<MonsterGradeData> getGrades() const;
  QString getLook() const;
  bool getUseSummonSlot() const;
  bool getUseBombSlot() const;
  bool getCanPlay() const;
  bool getCanTackle() const;
  bool getIsBoss() const;
  QList<MonsterDropData> getDrops() const;
  QList<uint> getSubareas() const;
  QList<uint> getSpells() const;
  int getFavoriteSubareaId() const;
  bool getIsMiniBoss() const;
  bool getIsQuestMonster() const;
  uint getCorrespondingMiniBossId() const;
  double getSpeedAdjust() const;
  int getCreatureBoneId() const;
  bool getCanBePushed() const;
  bool getFastAnimsFun() const;
  bool getCanSwitchPos() const;
  QList<uint> getIncompatibleIdols() const;
  bool getAllIdolsDisabled() const;
  bool getDareAvailable() const;
  QList<uint> getIncompatibleChallenges() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_gfxId;
  int m_race;
  QList<MonsterGradeData> m_grades;
  QString m_look;
  bool m_useSummonSlot;
  bool m_useBombSlot;
  bool m_canPlay;
  bool m_canTackle;
  bool m_isBoss;
  QList<MonsterDropData> m_drops;
  QList<uint> m_subareas;
  QList<uint> m_spells;
  int m_favoriteSubareaId;
  bool m_isMiniBoss;
  bool m_isQuestMonster;
  uint m_correspondingMiniBossId;
  double m_speedAdjust;
  int m_creatureBoneId;
  bool m_canBePushed;
  bool m_fastAnimsFun;
  bool m_canSwitchPos;
  QList<uint> m_incompatibleIdols;
  bool m_allIdolsDisabled;
  bool m_dareAvailable;
  QList<uint> m_incompatibleChallenges;
};

#endif // MONSTERDATA_H