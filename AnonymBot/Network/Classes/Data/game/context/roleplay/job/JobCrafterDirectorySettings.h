#ifndef JOBCRAFTERDIRECTORYSETTINGS_H
#define JOBCRAFTERDIRECTORYSETTINGS_H

#include "Network/Classes/AbstractClass.h"

class JobCrafterDirectorySettings : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectorySettings(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectorySettings(Reader *param1);
  JobCrafterDirectorySettings();
  bool operator==(const JobCrafterDirectorySettings &compared);

  uint jobId;
  uint minLevel;
  bool free;
};

#endif // JOBCRAFTERDIRECTORYSETTINGS_H