#ifndef CHARACTERDELETIONREQUESTMESSAGE_H
#define CHARACTERDELETIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterDeletionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterDeletionRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterDeletionRequestMessage(Reader *param1);
  CharacterDeletionRequestMessage();

  double characterId;
  QString secretAnswerHash;
};

#endif // CHARACTERDELETIONREQUESTMESSAGE_H