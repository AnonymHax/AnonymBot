#ifndef ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H
#define ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/npc/TaxCollectorDialogQuestionExtendedMessage.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class AllianceTaxCollectorDialogQuestionExtendedMessage : public TaxCollectorDialogQuestionExtendedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceTaxCollectorDialogQuestionExtendedMessage(Reader *param1);
  AllianceTaxCollectorDialogQuestionExtendedMessage();

  QSharedPointer<BasicNamedAllianceInformations> alliance;
};

#endif // ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H