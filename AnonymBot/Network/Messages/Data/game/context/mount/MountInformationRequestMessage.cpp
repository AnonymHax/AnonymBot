#include "MountInformationRequestMessage.h"

void MountInformationRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MountInformationRequestMessage(param1);
}

void MountInformationRequestMessage::serializeAs_MountInformationRequestMessage(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    if(this->time < -9.007199254740992E15 || this->time > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->time << ") on element time.";
    }
    else
    {
      param1->writeDouble(this->time);
      return;
    }
  }
}

void MountInformationRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountInformationRequestMessage(param1);
}

void MountInformationRequestMessage::deserializeAs_MountInformationRequestMessage(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->id << ") on element of MountInformationRequestMessage.id.";
  }
  else
  {
    this->time = param1->readDouble();
    if(this->time < -9.007199254740992E15 || this->time > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->time << ") on element of MountInformationRequestMessage.time.";
    }
    else
    {
      return;
    }
  }
}

MountInformationRequestMessage::MountInformationRequestMessage()
{
  m_type = MessageEnum::MOUNTINFORMATIONREQUESTMESSAGE;
}

