#ifndef ALLIANCEJOINEDMESSAGE_H
#define ALLIANCEJOINEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"

class AllianceJoinedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceJoinedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceJoinedMessage(Reader *param1);
  AllianceJoinedMessage();

  QSharedPointer<AllianceInformations> allianceInfo;
  bool enabled;
};

#endif // ALLIANCEJOINEDMESSAGE_H