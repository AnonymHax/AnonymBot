#ifndef PRESETITEM_H
#define PRESETITEM_H

#include "Network/Classes/AbstractClass.h"

class PresetItem : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PresetItem(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PresetItem(Reader *param1);
  PresetItem();
  bool operator==(const PresetItem &compared);

  uint position;
  uint objGid;
  uint objUid;
};

#endif // PRESETITEM_H