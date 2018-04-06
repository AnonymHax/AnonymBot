#ifndef CHARACTERMINIMALALLIANCEINFORMATIONS_H
#define CHARACTERMINIMALALLIANCEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalGuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalGuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class CharacterMinimalAllianceInformations : public CharacterMinimalGuildInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterMinimalAllianceInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterMinimalAllianceInformations(Reader *param1);
  CharacterMinimalAllianceInformations();
  bool operator==(const CharacterMinimalAllianceInformations &compared);

  QSharedPointer<BasicAllianceInformations> alliance;
};

#endif // CHARACTERMINIMALALLIANCEINFORMATIONS_H