#ifndef VERSION_H
#define VERSION_H

#include "Network/Classes/AbstractClass.h"

class Version : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_Version(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_Version(Reader *param1);
  Version();
  bool operator==(const Version &compared);

  uint major;
  uint minor;
  uint release;
  uint revision;
  uint patch;
  uint buildType;
};

#endif // VERSION_H