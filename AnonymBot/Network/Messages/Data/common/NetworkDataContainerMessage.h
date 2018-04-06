#ifndef NETWORKDATACONTAINERMESSAGE_H
#define NETWORKDATACONTAINERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NetworkDataContainerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NetworkDataContainerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NetworkDataContainerMessage(Reader *param1);
  NetworkDataContainerMessage();

  QByteArray content;
};

#endif // NETWORKDATACONTAINERMESSAGE_H