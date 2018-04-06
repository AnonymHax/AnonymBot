#ifndef GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE_H
#define GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameDataPlayFarmObjectAnimationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameDataPlayFarmObjectAnimationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameDataPlayFarmObjectAnimationMessage(Reader *param1);
  GameDataPlayFarmObjectAnimationMessage();

  QList<uint> cellId;
};

#endif // GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE_H