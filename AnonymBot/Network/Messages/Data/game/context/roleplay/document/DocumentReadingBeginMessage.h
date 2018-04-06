#ifndef DOCUMENTREADINGBEGINMESSAGE_H
#define DOCUMENTREADINGBEGINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DocumentReadingBeginMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DocumentReadingBeginMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DocumentReadingBeginMessage(Reader *param1);
  DocumentReadingBeginMessage();

  uint documentId;
};

#endif // DOCUMENTREADINGBEGINMESSAGE_H