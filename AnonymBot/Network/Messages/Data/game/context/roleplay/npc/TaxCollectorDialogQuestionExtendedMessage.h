#ifndef TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H
#define TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/npc/TaxCollectorDialogQuestionBasicMessage.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class TaxCollectorDialogQuestionExtendedMessage : public TaxCollectorDialogQuestionBasicMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorDialogQuestionExtendedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorDialogQuestionExtendedMessage(Reader *param1);
  TaxCollectorDialogQuestionExtendedMessage();

  uint maxPods;
  uint prospecting;
  uint wisdom;
  uint taxCollectorsCount;
  int taxCollectorAttack;
  uint kamas;
  double experience;
  uint pods;
  uint itemsValue;
};

#endif // TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H