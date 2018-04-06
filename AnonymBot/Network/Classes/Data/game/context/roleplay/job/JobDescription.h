#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescription.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescription.h"
#include "Network/Classes/ClassManager.h"

class JobDescription : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobDescription(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobDescription(Reader *param1);
  JobDescription();
  bool operator==(const JobDescription &compared);

  uint jobId;
  QList<QSharedPointer<SkillActionDescription>> skills;
};

#endif // JOBDESCRIPTION_H