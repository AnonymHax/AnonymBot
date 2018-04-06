#ifndef ALLIANCEPRISMDIALOGQUESTIONMESSAGE_H
#define ALLIANCEPRISMDIALOGQUESTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AlliancePrismDialogQuestionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlliancePrismDialogQuestionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlliancePrismDialogQuestionMessage(Reader *param1);
  AlliancePrismDialogQuestionMessage();
};

#endif // ALLIANCEPRISMDIALOGQUESTIONMESSAGE_H