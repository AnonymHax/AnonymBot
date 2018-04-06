#ifndef TITLESELECTREQUESTMESSAGE_H
#define TITLESELECTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TitleSelectRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TitleSelectRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TitleSelectRequestMessage(Reader *param1);
  TitleSelectRequestMessage();

  uint titleId;
};

#endif // TITLESELECTREQUESTMESSAGE_H