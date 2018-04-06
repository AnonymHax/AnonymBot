#ifndef MOUNTINFORMATIONREQUESTMESSAGE_H
#define MOUNTINFORMATIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountInformationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountInformationRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountInformationRequestMessage(Reader *param1);
  MountInformationRequestMessage();

  double id;
  double time;
};

#endif // MOUNTINFORMATIONREQUESTMESSAGE_H