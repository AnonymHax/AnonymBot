#ifndef CONSOLECOMMANDSLISTMESSAGE_H
#define CONSOLECOMMANDSLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ConsoleCommandsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ConsoleCommandsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ConsoleCommandsListMessage(Reader *param1);
  ConsoleCommandsListMessage();

  QList<QString> aliases;
  QList<QString> args;
  QList<QString> descriptions;
};

#endif // CONSOLECOMMANDSLISTMESSAGE_H