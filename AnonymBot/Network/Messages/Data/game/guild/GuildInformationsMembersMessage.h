#ifndef GUILDINFORMATIONSMEMBERSMESSAGE_H
#define GUILDINFORMATIONSMEMBERSMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildMember.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildMember.h"

class GuildInformationsMembersMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInformationsMembersMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInformationsMembersMessage(Reader *param1);
  GuildInformationsMembersMessage();

  QList<QSharedPointer<GuildMember>> members;
};

#endif // GUILDINFORMATIONSMEMBERSMESSAGE_H