#ifndef CHARACTERCAPABILITIESMESSAGE_H
#define CHARACTERCAPABILITIESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterCapabilitiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterCapabilitiesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterCapabilitiesMessage(Reader *param1);
  CharacterCapabilitiesMessage();

  uint guildEmblemSymbolCategories;
};

#endif // CHARACTERCAPABILITIESMESSAGE_H