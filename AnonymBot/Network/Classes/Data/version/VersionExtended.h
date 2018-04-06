#ifndef VERSIONEXTENDED_H
#define VERSIONEXTENDED_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/version/Version.h"

class VersionExtended : public Version
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_VersionExtended(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_VersionExtended(Reader *param1);
  VersionExtended();
  bool operator==(const VersionExtended &compared);

  uint install;
  uint technology;
};

#endif // VERSIONEXTENDED_H