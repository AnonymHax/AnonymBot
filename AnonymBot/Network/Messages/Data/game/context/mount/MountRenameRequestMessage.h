#ifndef MOUNTRENAMEREQUESTMESSAGE_H
#define MOUNTRENAMEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountRenameRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountRenameRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountRenameRequestMessage(Reader *param1);
  MountRenameRequestMessage();

  QString name;
  int mountId;
};

#endif // MOUNTRENAMEREQUESTMESSAGE_H