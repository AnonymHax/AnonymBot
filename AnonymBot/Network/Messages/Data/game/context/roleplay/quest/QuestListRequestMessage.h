#ifndef QUESTLISTREQUESTMESSAGE_H
#define QUESTLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestListRequestMessage(Reader *param1);
  QuestListRequestMessage();
};

#endif // QUESTLISTREQUESTMESSAGE_H