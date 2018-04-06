#ifndef ADMINQUIETCOMMANDMESSAGE_H
#define ADMINQUIETCOMMANDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/authorized/AdminCommandMessage.h"

class AdminQuietCommandMessage : public AdminCommandMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AdminQuietCommandMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AdminQuietCommandMessage(Reader *param1);
  AdminQuietCommandMessage();
};

#endif // ADMINQUIETCOMMANDMESSAGE_H