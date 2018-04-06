#ifndef GETPARTINFOMESSAGE_H
#define GETPARTINFOMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GetPartInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GetPartInfoMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GetPartInfoMessage(Reader *param1);
  GetPartInfoMessage();

  QString id;
};

#endif // GETPARTINFOMESSAGE_H