#ifndef EMOTELISTMESSAGE_H
#define EMOTELISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EmoteListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmoteListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmoteListMessage(Reader *param1);
  EmoteListMessage();

  QList<uint> emoteIds;
};

#endif // EMOTELISTMESSAGE_H