#ifndef ORNAMENTSELECTEDMESSAGE_H
#define ORNAMENTSELECTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class OrnamentSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_OrnamentSelectedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_OrnamentSelectedMessage(Reader *param1);
  OrnamentSelectedMessage();

  uint ornamentId;
};

#endif // ORNAMENTSELECTEDMESSAGE_H