#ifndef JOBCRAFTERDIRECTORYENTRYJOBINFO_H
#define JOBCRAFTERDIRECTORYENTRYJOBINFO_H

#include "Network/Classes/AbstractClass.h"

class JobCrafterDirectoryEntryJobInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryEntryJobInfo(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryEntryJobInfo(Reader *param1);
  JobCrafterDirectoryEntryJobInfo();
  bool operator==(const JobCrafterDirectoryEntryJobInfo &compared);

  uint jobId;
  uint jobLevel;
  bool free;
  uint minLevel;
};

#endif // JOBCRAFTERDIRECTORYENTRYJOBINFO_H