#ifndef ALLIANCEVERSATILEINFOLISTMESSAGE_H
#define ALLIANCEVERSATILEINFOLISTMESSAGE_H

#include "Network/Classes/Data/game/social/AllianceVersatileInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/social/AllianceVersatileInformations.h"

class AllianceVersatileInfoListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceVersatileInfoListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceVersatileInfoListMessage(Reader *param1);
  AllianceVersatileInfoListMessage();

  QList<AllianceVersatileInformations> alliances;
};

#endif // ALLIANCEVERSATILEINFOLISTMESSAGE_H