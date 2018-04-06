#ifndef CHECKFILEMESSAGE_H
#define CHECKFILEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CheckFileMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CheckFileMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CheckFileMessage(Reader *param1);
  CheckFileMessage();

  QString filenameHash;
  uint type;
  QString value;
};

#endif // CHECKFILEMESSAGE_H