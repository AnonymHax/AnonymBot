#ifndef IDOLSPRESET_H
#define IDOLSPRESET_H

#include "Network/Classes/AbstractClass.h"

class IdolsPreset : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPreset(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPreset(Reader *param1);
  IdolsPreset();
  bool operator==(const IdolsPreset &compared);

  uint presetId;
  uint symbolId;
  QList<uint> idolId;
};

#endif // IDOLSPRESET_H