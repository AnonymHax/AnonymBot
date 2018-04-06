#ifndef CHARACTERSELECTEDFORCEMESSAGE_H
#define CHARACTERSELECTEDFORCEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterSelectedForceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterSelectedForceMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterSelectedForceMessage(Reader *param1);
  CharacterSelectedForceMessage();

  int id;
};

#endif // CHARACTERSELECTEDFORCEMESSAGE_H