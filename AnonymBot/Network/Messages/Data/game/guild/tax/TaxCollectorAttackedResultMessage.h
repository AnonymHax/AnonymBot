#ifndef TAXCOLLECTORATTACKEDRESULTMESSAGE_H
#define TAXCOLLECTORATTACKEDRESULTMESSAGE_H

#include "Network/Classes/Data/game/guild/tax/TaxCollectorBasicInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorBasicInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class TaxCollectorAttackedResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorAttackedResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorAttackedResultMessage(Reader *param1);
  TaxCollectorAttackedResultMessage();

  bool deadOrAlive;
  TaxCollectorBasicInformations basicInfos;
  QSharedPointer<BasicGuildInformations> guild;
};

#endif // TAXCOLLECTORATTACKEDRESULTMESSAGE_H