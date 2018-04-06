#ifndef ATLASPOINTINFORMATIONSMESSAGE_H
#define ATLASPOINTINFORMATIONSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/AtlasPointsInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/AtlasPointsInformations.h"

class AtlasPointInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AtlasPointInformationsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AtlasPointInformationsMessage(Reader *param1);
  AtlasPointInformationsMessage();

  QSharedPointer<AtlasPointsInformations> type;
};

#endif // ATLASPOINTINFORMATIONSMESSAGE_H