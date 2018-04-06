#ifndef CINEMATICMESSAGE_H
#define CINEMATICMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CinematicMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CinematicMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CinematicMessage(Reader *param1);
  CinematicMessage();

  uint cinematicId;
};

#endif // CINEMATICMESSAGE_H