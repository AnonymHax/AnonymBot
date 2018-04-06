#include "JobBookSubscription.h"

void JobBookSubscription::serialize(Writer *param1)
{
  this->serializeAs_JobBookSubscription(param1);
}

void JobBookSubscription::serializeAs_JobBookSubscription(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobBookSubscription -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    param1->writeBool(this->subscribed);
    return;
  }
}

void JobBookSubscription::deserialize(Reader *param1)
{
  this->deserializeAs_JobBookSubscription(param1);
}

void JobBookSubscription::deserializeAs_JobBookSubscription(Reader *param1)
{
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobBookSubscription -"<<"Forbidden value (" << this->jobId << ") on element of JobBookSubscription.jobId.";
  }
  else
  {
    this->subscribed = param1->readBool();
    return;
  }
}

JobBookSubscription::JobBookSubscription()
{
  m_types<<ClassEnum::JOBBOOKSUBSCRIPTION;
}

bool JobBookSubscription::operator==(const JobBookSubscription &compared)
{
  if(jobId == compared.jobId)
  if(subscribed == compared.subscribed)
  return true;
  
  return false;
}

