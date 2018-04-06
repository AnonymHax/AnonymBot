#ifndef HUMANOPTIONEMOTE_H
#define HUMANOPTIONEMOTE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"

class HumanOptionEmote : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionEmote(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionEmote(Reader *param1);
  HumanOptionEmote();
  bool operator==(const HumanOptionEmote &compared);

  uint emoteId;
  double emoteStartTime;
};

#endif // HUMANOPTIONEMOTE_H