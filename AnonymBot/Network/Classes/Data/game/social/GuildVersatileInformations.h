#ifndef GUILDVERSATILEINFORMATIONS_H
#define GUILDVERSATILEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class GuildVersatileInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildVersatileInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildVersatileInformations(Reader *param1);
  GuildVersatileInformations();
  bool operator==(const GuildVersatileInformations &compared);

  uint guildId;
  double leaderId;
  uint guildLevel;
  uint nbMembers;
};

#endif // GUILDVERSATILEINFORMATIONS_H