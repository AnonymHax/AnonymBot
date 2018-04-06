#ifndef BASICGUILDINFORMATIONS_H
#define BASICGUILDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/social/AbstractSocialGroupInfos.h"
#include "Network/Classes/Data/game/social/AbstractSocialGroupInfos.h"

class BasicGuildInformations : public AbstractSocialGroupInfos
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicGuildInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicGuildInformations(Reader *param1);
  BasicGuildInformations();
  bool operator==(const BasicGuildInformations &compared);

  uint guildId;
  QString guildName;
  uint guildLevel;
};

#endif // BASICGUILDINFORMATIONS_H