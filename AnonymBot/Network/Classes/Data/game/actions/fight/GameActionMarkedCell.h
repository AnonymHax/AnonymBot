#ifndef GAMEACTIONMARKEDCELL_H
#define GAMEACTIONMARKEDCELL_H

#include "Network/Classes/AbstractClass.h"

class GameActionMarkedCell : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionMarkedCell(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionMarkedCell(Reader *param1);
  GameActionMarkedCell();
  bool operator==(const GameActionMarkedCell &compared);

  uint cellId;
  int zoneSize;
  int cellColor;
  int cellsType;
};

#endif // GAMEACTIONMARKEDCELL_H