#ifndef CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H
#define CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterNameSuggestionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterNameSuggestionRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterNameSuggestionRequestMessage(Reader *param1);
  CharacterNameSuggestionRequestMessage();
};

#endif // CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H