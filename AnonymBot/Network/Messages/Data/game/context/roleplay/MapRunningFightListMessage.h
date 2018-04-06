#ifndef MAPRUNNINGFIGHTLISTMESSAGE_H
#define MAPRUNNINGFIGHTLISTMESSAGE_H

#include "Network/Classes/Data/game/context/fight/FightExternalInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/FightExternalInformations.h"

class MapRunningFightListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapRunningFightListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapRunningFightListMessage(Reader *param1);
  MapRunningFightListMessage();

  QList<FightExternalInformations> fights;
};

#endif // MAPRUNNINGFIGHTLISTMESSAGE_H