#ifndef DOWNLOADSETSPEEDREQUESTMESSAGE_H
#define DOWNLOADSETSPEEDREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DownloadSetSpeedRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DownloadSetSpeedRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DownloadSetSpeedRequestMessage(Reader *param1);
  DownloadSetSpeedRequestMessage();

  uint downloadSpeed;
};

#endif // DOWNLOADSETSPEEDREQUESTMESSAGE_H