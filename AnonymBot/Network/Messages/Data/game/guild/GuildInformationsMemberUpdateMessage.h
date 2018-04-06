#ifndef GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H
#define GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildMember.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildMember.h"

class GuildInformationsMemberUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInformationsMemberUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInformationsMemberUpdateMessage(Reader *param1);
  GuildInformationsMemberUpdateMessage();

  QSharedPointer<GuildMember> member;
};

#endif // GUILDINFORMATIONSMEMBERUPDATEMESSAGE_H