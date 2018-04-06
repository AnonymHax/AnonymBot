#ifndef ALLIANCEPARTIALLISTMESSAGE_H
#define ALLIANCEPARTIALLISTMESSAGE_H

#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/alliance/AllianceListMessage.h"
#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"

class AlliancePartialListMessage : public AllianceListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlliancePartialListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlliancePartialListMessage(Reader *param1);
  AlliancePartialListMessage();
};

#endif // ALLIANCEPARTIALLISTMESSAGE_H