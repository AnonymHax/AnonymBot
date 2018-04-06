#ifndef JOBDESCRIPTIONMESSAGE_H
#define JOBDESCRIPTIONMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobDescription.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobDescription.h"

class JobDescriptionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobDescriptionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobDescriptionMessage(Reader *param1);
  JobDescriptionMessage();

  QList<QSharedPointer<JobDescription>> jobsDescription;
};

#endif // JOBDESCRIPTIONMESSAGE_H