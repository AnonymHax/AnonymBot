#ifndef MOODSMILEYREQUESTMESSAGE_H
#define MOODSMILEYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MoodSmileyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MoodSmileyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MoodSmileyRequestMessage(Reader *param1);
  MoodSmileyRequestMessage();

  uint smileyId;
};

#endif // MOODSMILEYREQUESTMESSAGE_H