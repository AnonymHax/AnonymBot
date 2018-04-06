#ifndef CONTACTLOOKMESSAGE_H
#define CONTACTLOOKMESSAGE_H

#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class ContactLookMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ContactLookMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ContactLookMessage(Reader *param1);
  ContactLookMessage();

  uint requestId;
  QString playerName;
  double playerId;
  QSharedPointer<EntityLook> look;
};

#endif // CONTACTLOOKMESSAGE_H