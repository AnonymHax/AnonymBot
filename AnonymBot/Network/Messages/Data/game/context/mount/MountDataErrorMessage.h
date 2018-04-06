#ifndef MOUNTDATAERRORMESSAGE_H
#define MOUNTDATAERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountDataErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountDataErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountDataErrorMessage(Reader *param1);
  MountDataErrorMessage();

  uint reason;
};

#endif // MOUNTDATAERRORMESSAGE_H