#ifndef DOWNLOADCURRENTSPEEDMESSAGE_H
#define DOWNLOADCURRENTSPEEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DownloadCurrentSpeedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DownloadCurrentSpeedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DownloadCurrentSpeedMessage(Reader *param1);
  DownloadCurrentSpeedMessage();

  uint downloadSpeed;
};

#endif // DOWNLOADCURRENTSPEEDMESSAGE_H