#ifndef ALLIANCELISTMESSAGE_H
#define ALLIANCELISTMESSAGE_H

#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"

class AllianceListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceListMessage(Reader *param1);
  AllianceListMessage();

  QList<QSharedPointer<AllianceFactSheetInformations>> alliances;
};

#endif // ALLIANCELISTMESSAGE_H