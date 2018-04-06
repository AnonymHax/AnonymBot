#ifndef PLAYERSTATUSUPDATEERRORMESSAGE_H
#define PLAYERSTATUSUPDATEERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PlayerStatusUpdateErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PlayerStatusUpdateErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PlayerStatusUpdateErrorMessage(Reader *param1);
  PlayerStatusUpdateErrorMessage();
};

#endif // PLAYERSTATUSUPDATEERRORMESSAGE_H