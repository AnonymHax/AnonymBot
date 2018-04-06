#ifndef GAMEACTIONMARK_H
#define GAMEACTIONMARK_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMarkedCell.h"

class GameActionMark : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionMark(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionMark(Reader *param1);
  GameActionMark();
  bool operator==(const GameActionMark &compared);

  double markAuthorId;
  uint markTeamId;
  uint markSpellId;
  int markSpellLevel;
  int markId;
  int markType;
  int markimpactCell;
  QList<GameActionMarkedCell> cells;
  bool active;
};

#endif // GAMEACTIONMARK_H