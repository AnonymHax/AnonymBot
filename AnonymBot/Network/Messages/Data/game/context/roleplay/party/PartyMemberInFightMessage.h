#ifndef PARTYMEMBERINFIGHTMESSAGE_H
#define PARTYMEMBERINFIGHTMESSAGE_H

#include "Network/Classes/Data/game/context/MapCoordinatesExtended.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"
#include "Network/Classes/Data/game/context/MapCoordinatesExtended.h"

class PartyMemberInFightMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyMemberInFightMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyMemberInFightMessage(Reader *param1);
  PartyMemberInFightMessage();

  uint reason;
  double memberId;
  uint memberAccountId;
  QString memberName;
  int fightId;
  QSharedPointer<MapCoordinatesExtended> fightMap;
  int timeBeforeFightStart;
};

#endif // PARTYMEMBERINFIGHTMESSAGE_H