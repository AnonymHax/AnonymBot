#ifndef GAMEROLEPLAYNPCQUESTFLAG_H
#define GAMEROLEPLAYNPCQUESTFLAG_H

#include "Network/Classes/AbstractClass.h"

class GameRolePlayNpcQuestFlag : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayNpcQuestFlag(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayNpcQuestFlag(Reader *param1);
  GameRolePlayNpcQuestFlag();
  bool operator==(const GameRolePlayNpcQuestFlag &compared);

  QList<uint> questsToValidId;
  QList<uint> questsToStartId;
};

#endif // GAMEROLEPLAYNPCQUESTFLAG_H