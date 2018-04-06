#ifndef GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE_H
#define GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaFightPropositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaFightPropositionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaFightPropositionMessage(Reader *param1);
  GameRolePlayArenaFightPropositionMessage();

  uint fightId;
  QList<double> alliesId;
  uint duration;
};

#endif // GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE_H