#ifndef KOHUPDATEMESSAGE_H
#define KOHUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"

class KohUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KohUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KohUpdateMessage(Reader *param1);
  KohUpdateMessage();

  QList<QSharedPointer<AllianceInformations>> alliances;
  QList<uint> allianceNbMembers;
  QList<uint> allianceRoundWeigth;
  QList<uint> allianceMatchScore;
  QSharedPointer<BasicAllianceInformations> allianceMapWinner;
  uint allianceMapWinnerScore;
  uint allianceMapMyAllianceScore;
  double nextTickTime;
};

#endif // KOHUPDATEMESSAGE_H