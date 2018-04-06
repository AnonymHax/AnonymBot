#ifndef STARTUPACTIONSOBJETATTRIBUTIONMESSAGE_H
#define STARTUPACTIONSOBJETATTRIBUTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StartupActionsObjetAttributionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StartupActionsObjetAttributionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StartupActionsObjetAttributionMessage(Reader *param1);
  StartupActionsObjetAttributionMessage();

  uint actionId;
  double characterId;
};

#endif // STARTUPACTIONSOBJETATTRIBUTIONMESSAGE_H