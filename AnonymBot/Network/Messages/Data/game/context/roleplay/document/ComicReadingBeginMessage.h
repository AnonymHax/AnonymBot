#ifndef COMICREADINGBEGINMESSAGE_H
#define COMICREADINGBEGINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ComicReadingBeginMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ComicReadingBeginMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ComicReadingBeginMessage(Reader *param1);
  ComicReadingBeginMessage();

  uint comicId;
};

#endif // COMICREADINGBEGINMESSAGE_H