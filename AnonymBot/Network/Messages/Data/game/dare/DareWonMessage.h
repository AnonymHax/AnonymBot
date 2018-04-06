#ifndef DAREWONMESSAGE_H
#define DAREWONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareWonMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareWonMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareWonMessage(Reader *param1);
  DareWonMessage();

  double dareId;
};

#endif // DAREWONMESSAGE_H