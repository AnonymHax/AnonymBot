#ifndef MOUNTRENAMEDMESSAGE_H
#define MOUNTRENAMEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountRenamedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountRenamedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountRenamedMessage(Reader *param1);
  MountRenamedMessage();

  int mountId;
  QString name;
};

#endif // MOUNTRENAMEDMESSAGE_H