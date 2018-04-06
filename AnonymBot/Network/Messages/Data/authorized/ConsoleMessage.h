#ifndef CONSOLEMESSAGE_H
#define CONSOLEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ConsoleMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ConsoleMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ConsoleMessage(Reader *param1);
  ConsoleMessage();

  uint type;
  QString content;
};

#endif // CONSOLEMESSAGE_H