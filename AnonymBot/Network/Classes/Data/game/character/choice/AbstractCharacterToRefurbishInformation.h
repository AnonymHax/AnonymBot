#ifndef ABSTRACTCHARACTERTOREFURBISHINFORMATION_H
#define ABSTRACTCHARACTERTOREFURBISHINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/AbstractCharacterInformation.h"
#include "Network/Classes/Data/game/character/AbstractCharacterInformation.h"
#include "Network/Classes/Data/game/character/AbstractCharacterInformation.h"

class AbstractCharacterToRefurbishInformation : public AbstractCharacterInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractCharacterToRefurbishInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractCharacterToRefurbishInformation(Reader *param1);
  AbstractCharacterToRefurbishInformation();
  bool operator==(const AbstractCharacterToRefurbishInformation &compared);

  QList<int> colors;
  uint cosmeticId;
};

#endif // ABSTRACTCHARACTERTOREFURBISHINFORMATION_H