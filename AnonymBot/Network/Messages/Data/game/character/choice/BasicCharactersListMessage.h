#ifndef BASICCHARACTERSLISTMESSAGE_H
#define BASICCHARACTERSLISTMESSAGE_H

#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/ClassManager.h"

class BasicCharactersListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicCharactersListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicCharactersListMessage(Reader *param1);
  BasicCharactersListMessage();

  QList<QSharedPointer<CharacterBaseInformations>> characters;
};

#endif // BASICCHARACTERSLISTMESSAGE_H