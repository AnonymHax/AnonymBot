#ifndef FINISHMOVESETREQUESTMESSAGE_H
#define FINISHMOVESETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class FinishMoveSetRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FinishMoveSetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FinishMoveSetRequestMessage(Reader *param1);
  FinishMoveSetRequestMessage();

  uint finishMoveId;
  bool finishMoveState;
};

#endif // FINISHMOVESETREQUESTMESSAGE_H