#ifndef STARTUPACTIONSALLATTRIBUTIONMESSAGE_H
#define STARTUPACTIONSALLATTRIBUTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StartupActionsAllAttributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StartupActionsAllAttributionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StartupActionsAllAttributionMessage(Reader *param1);
  StartupActionsAllAttributionMessage();

  double characterId;
};

#endif // STARTUPACTIONSALLATTRIBUTIONMESSAGE_H