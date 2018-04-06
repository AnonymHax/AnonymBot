#ifndef CHARACTEREXPERIENCEGAINMESSAGE_H
#define CHARACTEREXPERIENCEGAINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CharacterExperienceGainMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterExperienceGainMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterExperienceGainMessage(Reader *param1);
  CharacterExperienceGainMessage();

  double experienceCharacter;
  double experienceMount;
  double experienceGuild;
  double experienceIncarnation;
};

#endif // CHARACTEREXPERIENCEGAINMESSAGE_H