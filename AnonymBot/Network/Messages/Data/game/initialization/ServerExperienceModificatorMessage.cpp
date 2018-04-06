#include "ServerExperienceModificatorMessage.h"

void ServerExperienceModificatorMessage::serialize(Writer *param1)
{
  this->serializeAs_ServerExperienceModificatorMessage(param1);
}

void ServerExperienceModificatorMessage::serializeAs_ServerExperienceModificatorMessage(Writer *param1)
{
  if(this->experiencePercent < 0)
  {
    qDebug()<<"ERREUR - ServerExperienceModificatorMessage -"<<"Forbidden value (" << this->experiencePercent << ") on element experiencePercent.";
  }
  else
  {
    param1->writeVarShort((int)this->experiencePercent);
    return;
  }
}

void ServerExperienceModificatorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ServerExperienceModificatorMessage(param1);
}

void ServerExperienceModificatorMessage::deserializeAs_ServerExperienceModificatorMessage(Reader *param1)
{
  this->experiencePercent = param1->readVarUhShort();
  if(this->experiencePercent < 0)
  {
    qDebug()<<"ERREUR - ServerExperienceModificatorMessage -"<<"Forbidden value (" << this->experiencePercent << ") on element of ServerExperienceModificatorMessage.experiencePercent.";
  }
  else
  {
    return;
  }
}

ServerExperienceModificatorMessage::ServerExperienceModificatorMessage()
{
  m_type = MessageEnum::SERVEREXPERIENCEMODIFICATORMESSAGE;
}

