#ifndef SHORTCUT_H
#define SHORTCUT_H

#include "Network/Classes/AbstractClass.h"

class Shortcut : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_Shortcut(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_Shortcut(Reader *param1);
  Shortcut();
  bool operator==(const Shortcut &compared);

  uint slot;
};

#endif // SHORTCUT_H