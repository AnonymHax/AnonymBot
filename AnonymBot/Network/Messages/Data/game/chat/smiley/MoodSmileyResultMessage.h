#ifndef MOODSMILEYRESULTMESSAGE_H
#define MOODSMILEYRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MoodSmileyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MoodSmileyResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MoodSmileyResultMessage(Reader *param1);
  MoodSmileyResultMessage();

  uint resultCode;
  uint smileyId;
};

#endif // MOODSMILEYRESULTMESSAGE_H