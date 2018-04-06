#ifndef BASICWHOISNOMATCHMESSAGE_H
#define BASICWHOISNOMATCHMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicWhoIsNoMatchMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicWhoIsNoMatchMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicWhoIsNoMatchMessage(Reader *param1);
  BasicWhoIsNoMatchMessage();

  QString search;
};

#endif // BASICWHOISNOMATCHMESSAGE_H