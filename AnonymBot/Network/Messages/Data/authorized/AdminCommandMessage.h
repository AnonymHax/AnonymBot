#ifndef ADMINCOMMANDMESSAGE_H
#define ADMINCOMMANDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AdminCommandMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AdminCommandMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AdminCommandMessage(Reader *param1);
  AdminCommandMessage();

  QString content;
};

#endif // ADMINCOMMANDMESSAGE_H