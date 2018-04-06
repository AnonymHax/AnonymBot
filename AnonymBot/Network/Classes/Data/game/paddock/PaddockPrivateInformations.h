#ifndef PADDOCKPRIVATEINFORMATIONS_H
#define PADDOCKPRIVATEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockAbandonnedInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockAbandonnedInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class PaddockPrivateInformations : public PaddockAbandonnedInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockPrivateInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockPrivateInformations(Reader *param1);
  PaddockPrivateInformations();
  bool operator==(const PaddockPrivateInformations &compared);

  QSharedPointer<GuildInformations> guildInfo;
};

#endif // PADDOCKPRIVATEINFORMATIONS_H