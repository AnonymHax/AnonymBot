#ifndef DAREERRORMESSAGE_H
#define DAREERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareErrorMessage(Reader *param1);
  DareErrorMessage();

  uint error;
};

#endif // DAREERRORMESSAGE_H