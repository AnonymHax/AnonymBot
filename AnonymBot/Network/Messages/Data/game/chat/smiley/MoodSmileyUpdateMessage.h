#ifndef MOODSMILEYUPDATEMESSAGE_H
#define MOODSMILEYUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MoodSmileyUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MoodSmileyUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MoodSmileyUpdateMessage(Reader *param1);
  MoodSmileyUpdateMessage();

  uint accountId;
  double playerId;
  uint smileyId;
};

#endif // MOODSMILEYUPDATEMESSAGE_H