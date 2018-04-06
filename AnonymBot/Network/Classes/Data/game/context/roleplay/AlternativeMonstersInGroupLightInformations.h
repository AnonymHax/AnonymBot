#ifndef ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H
#define ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/MonsterInGroupLightInformations.h"

class AlternativeMonstersInGroupLightInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlternativeMonstersInGroupLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlternativeMonstersInGroupLightInformations(Reader *param1);
  AlternativeMonstersInGroupLightInformations();
  bool operator==(const AlternativeMonstersInGroupLightInformations &compared);

  int playerCount;
  QList<MonsterInGroupLightInformations> monsters;
};

#endif // ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS_H