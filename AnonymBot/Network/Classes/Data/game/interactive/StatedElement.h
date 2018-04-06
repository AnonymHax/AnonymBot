#ifndef STATEDELEMENT_H
#define STATEDELEMENT_H

#include "Network/Classes/AbstractClass.h"

class StatedElement : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatedElement(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatedElement(Reader *param1);
  StatedElement();
  bool operator==(const StatedElement &compared);

  uint elementId;
  uint elementCellId;
  uint elementState;
  bool onCurrentMap;
};

#endif // STATEDELEMENT_H