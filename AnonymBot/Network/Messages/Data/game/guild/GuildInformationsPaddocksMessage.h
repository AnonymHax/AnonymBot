#ifndef GUILDINFORMATIONSPADDOCKSMESSAGE_H
#define GUILDINFORMATIONSPADDOCKSMESSAGE_H

#include "Network/Classes/Data/game/paddock/PaddockContentInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/paddock/PaddockContentInformations.h"

class GuildInformationsPaddocksMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInformationsPaddocksMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInformationsPaddocksMessage(Reader *param1);
  GuildInformationsPaddocksMessage();

  uint nbPaddockMax;
  QList<QSharedPointer<PaddockContentInformations>> paddocksInformations;
};

#endif // GUILDINFORMATIONSPADDOCKSMESSAGE_H