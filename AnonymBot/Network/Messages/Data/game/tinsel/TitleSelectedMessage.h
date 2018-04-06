#ifndef TITLESELECTEDMESSAGE_H
#define TITLESELECTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TitleSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TitleSelectedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TitleSelectedMessage(Reader *param1);
  TitleSelectedMessage();

  uint titleId;
};

#endif // TITLESELECTEDMESSAGE_H