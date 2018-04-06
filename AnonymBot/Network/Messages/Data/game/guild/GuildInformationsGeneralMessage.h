#ifndef GUILDINFORMATIONSGENERALMESSAGE_H
#define GUILDINFORMATIONSGENERALMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildInformationsGeneralMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInformationsGeneralMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInformationsGeneralMessage(Reader *param1);
  GuildInformationsGeneralMessage();

  bool abandonnedPaddock;
  uint level;
  double expLevelFloor;
  double experience;
  double expNextLevelFloor;
  uint creationDate;
  uint nbTotalMembers;
  uint nbConnectedMembers;
};

#endif // GUILDINFORMATIONSGENERALMESSAGE_H