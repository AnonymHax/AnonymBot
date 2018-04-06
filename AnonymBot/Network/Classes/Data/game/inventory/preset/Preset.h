#ifndef PRESET_H
#define PRESET_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/inventory/preset/PresetItem.h"

class Preset : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_Preset(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_Preset(Reader *param1);
  Preset();
  bool operator==(const Preset &compared);

  uint presetId;
  uint symbolId;
  bool mount;
  QList<PresetItem> objects;
};

#endif // PRESET_H