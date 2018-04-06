#ifndef CHARACTERCREATIONREQUESTMESSAGE_H
#define CHARACTERCREATIONREQUESTMESSAGE_H

#include "Network/Enum/Data/PlayableBreedEnum.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Enum/Data/PlayableBreedEnum.h"

class CharacterCreationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterCreationRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterCreationRequestMessage(Reader *param1);
  CharacterCreationRequestMessage();

  QString name;
  int breed;
  bool sex;
  QList<int> colors;
  uint cosmeticId;
};

#endif // CHARACTERCREATIONREQUESTMESSAGE_H