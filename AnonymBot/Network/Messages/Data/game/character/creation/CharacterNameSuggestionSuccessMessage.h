#ifndef CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_H
#define CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterNameSuggestionSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterNameSuggestionSuccessMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterNameSuggestionSuccessMessage(Reader *param1);
  CharacterNameSuggestionSuccessMessage();

  QString suggestion;
};

#endif // CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_H