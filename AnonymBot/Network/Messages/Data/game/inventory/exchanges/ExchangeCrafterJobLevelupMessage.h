#ifndef EXCHANGECRAFTERJOBLEVELUPMESSAGE_H
#define EXCHANGECRAFTERJOBLEVELUPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeCrafterJobLevelupMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCrafterJobLevelupMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCrafterJobLevelupMessage(Reader *param1);
  ExchangeCrafterJobLevelupMessage();

  uint crafterJobLevel;
};

#endif // EXCHANGECRAFTERJOBLEVELUPMESSAGE_H