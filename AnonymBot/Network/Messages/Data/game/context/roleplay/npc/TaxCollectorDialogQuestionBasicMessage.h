#ifndef TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H
#define TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class TaxCollectorDialogQuestionBasicMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorDialogQuestionBasicMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorDialogQuestionBasicMessage(Reader *param1);
  TaxCollectorDialogQuestionBasicMessage();

  QSharedPointer<BasicGuildInformations> guildInfo;
};

#endif // TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE_H