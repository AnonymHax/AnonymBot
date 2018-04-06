#ifndef GAMEFIGHTFIGHTERLIGHTINFORMATIONS_H
#define GAMEFIGHTFIGHTERLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class GameFightFighterLightInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightFighterLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightFighterLightInformations(Reader *param1);
  GameFightFighterLightInformations();
  bool operator==(const GameFightFighterLightInformations &compared);

  double id;
  uint wave;
  uint level;
  int breed;
  bool sex;
  bool alive;
};

#endif // GAMEFIGHTFIGHTERLIGHTINFORMATIONS_H