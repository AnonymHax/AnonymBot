#ifndef FINISHMOVELISTREQUESTMESSAGE_H
#define FINISHMOVELISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FinishMoveListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FinishMoveListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FinishMoveListRequestMessage(Reader *param1);
  FinishMoveListRequestMessage();
};

#endif // FINISHMOVELISTREQUESTMESSAGE_H