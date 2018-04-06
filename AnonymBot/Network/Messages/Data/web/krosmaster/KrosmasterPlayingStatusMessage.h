#ifndef KROSMASTERPLAYINGSTATUSMESSAGE_H
#define KROSMASTERPLAYINGSTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterPlayingStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterPlayingStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterPlayingStatusMessage(Reader *param1);
  KrosmasterPlayingStatusMessage();

  bool playing;
};

#endif // KROSMASTERPLAYINGSTATUSMESSAGE_H