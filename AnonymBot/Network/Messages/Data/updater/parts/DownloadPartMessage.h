#ifndef DOWNLOADPARTMESSAGE_H
#define DOWNLOADPARTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DownloadPartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DownloadPartMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DownloadPartMessage(Reader *param1);
  DownloadPartMessage();

  QString id;
};

#endif // DOWNLOADPARTMESSAGE_H