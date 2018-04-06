#ifndef MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE_H
#define MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountInformationInPaddockRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountInformationInPaddockRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountInformationInPaddockRequestMessage(Reader *param1);
  MountInformationInPaddockRequestMessage();

  int mapRideId;
};

#endif // MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE_H