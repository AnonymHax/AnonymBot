#ifndef JOBEXPERIENCE_H
#define JOBEXPERIENCE_H

#include "Network/Classes/AbstractClass.h"

class JobExperience : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobExperience(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobExperience(Reader *param1);
  JobExperience();
  bool operator==(const JobExperience &compared);

  uint jobId;
  uint jobLevel;
  double jobXP;
  double jobXpLevelFloor;
  double jobXpNextLevelFloor;
};

#endif // JOBEXPERIENCE_H