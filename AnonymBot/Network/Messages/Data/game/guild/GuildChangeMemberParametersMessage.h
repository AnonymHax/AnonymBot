#ifndef GUILDCHANGEMEMBERPARAMETERSMESSAGE_H
#define GUILDCHANGEMEMBERPARAMETERSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildChangeMemberParametersMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildChangeMemberParametersMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildChangeMemberParametersMessage(Reader *param1);
  GuildChangeMemberParametersMessage();

  double memberId;
  uint rank;
  uint experienceGivenPercent;
  uint rights;
};

#endif // GUILDCHANGEMEMBERPARAMETERSMESSAGE_H