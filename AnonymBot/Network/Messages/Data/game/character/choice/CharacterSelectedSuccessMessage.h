#ifndef CHARACTERSELECTEDSUCCESSMESSAGE_H
#define CHARACTERSELECTEDSUCCESSMESSAGE_H

#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"

class CharacterSelectedSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterSelectedSuccessMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterSelectedSuccessMessage(Reader *param1);
  CharacterSelectedSuccessMessage();

  QSharedPointer<CharacterBaseInformations> infos;
  bool isCollectingStats;
};

#endif // CHARACTERSELECTEDSUCCESSMESSAGE_H