#ifndef CHARACTERNAMESUGGESTIONFAILUREMESSAGE_H
#define CHARACTERNAMESUGGESTIONFAILUREMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterNameSuggestionFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterNameSuggestionFailureMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterNameSuggestionFailureMessage(Reader *param1);
  CharacterNameSuggestionFailureMessage();

  uint reason;
};

#endif // CHARACTERNAMESUGGESTIONFAILUREMESSAGE_H