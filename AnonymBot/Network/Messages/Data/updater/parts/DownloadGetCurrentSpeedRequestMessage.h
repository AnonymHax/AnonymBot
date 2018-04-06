#ifndef DOWNLOADGETCURRENTSPEEDREQUESTMESSAGE_H
#define DOWNLOADGETCURRENTSPEEDREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DownloadGetCurrentSpeedRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DownloadGetCurrentSpeedRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DownloadGetCurrentSpeedRequestMessage(Reader *param1);
  DownloadGetCurrentSpeedRequestMessage();
};

#endif // DOWNLOADGETCURRENTSPEEDREQUESTMESSAGE_H