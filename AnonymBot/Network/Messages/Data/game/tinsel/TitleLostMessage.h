#ifndef TITLELOSTMESSAGE_H
#define TITLELOSTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TitleLostMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TitleLostMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TitleLostMessage(Reader *param1);
  TitleLostMessage();

  uint titleId;
};

#endif // TITLELOSTMESSAGE_H