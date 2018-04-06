#include "JobCrafterDirectoryEntryRequestMessage.h"

void JobCrafterDirectoryEntryRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryEntryRequestMessage(param1);
}

void JobCrafterDirectoryEntryRequestMessage::serializeAs_JobCrafterDirectoryEntryRequestMessage(Writer *param1)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void JobCrafterDirectoryEntryRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryEntryRequestMessage(param1);
}

void JobCrafterDirectoryEntryRequestMessage::deserializeAs_JobCrafterDirectoryEntryRequestMessage(Reader *param1)
{
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobCrafterDirectoryEntryRequestMessage.playerId.";
  }
  else
  {
    return;
  }
}

JobCrafterDirectoryEntryRequestMessage::JobCrafterDirectoryEntryRequestMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE;
}

