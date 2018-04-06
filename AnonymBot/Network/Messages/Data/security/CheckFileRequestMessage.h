#ifndef CHECKFILEREQUESTMESSAGE_H
#define CHECKFILEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CheckFileRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CheckFileRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CheckFileRequestMessage(Reader *param1);
  CheckFileRequestMessage();

  QString filename;
  uint type;
};

#endif // CHECKFILEREQUESTMESSAGE_H