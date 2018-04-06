#ifndef CHARACTERSLISTREQUESTMESSAGE_H
#define CHARACTERSLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharactersListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharactersListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharactersListRequestMessage(Reader *param1);
  CharactersListRequestMessage();
};

#endif // CHARACTERSLISTREQUESTMESSAGE_H