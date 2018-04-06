#include "UpdateSelfAgressableStatusMessage.h"

void UpdateSelfAgressableStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_UpdateSelfAgressableStatusMessage(param1);
}

void UpdateSelfAgressableStatusMessage::serializeAs_UpdateSelfAgressableStatusMessage(Writer *param1)
{
  param1->writeByte(this->status);
  if(this->probationTime < 0)
  {
    qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->probationTime << ") on element probationTime.";
  }
  else
  {
    param1->writeInt((int)this->probationTime);
    return;
  }
}

void UpdateSelfAgressableStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_UpdateSelfAgressableStatusMessage(param1);
}

void UpdateSelfAgressableStatusMessage::deserializeAs_UpdateSelfAgressableStatusMessage(Reader *param1)
{
  this->status = param1->readByte();
  if(this->status < 0)
  {
    qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->status << ") on element of UpdateSelfAgressableStatusMessage.status.";
  }
  else
  {
    this->probationTime = param1->readInt();
    if(this->probationTime < 0)
    {
      qDebug()<<"ERREUR - UpdateSelfAgressableStatusMessage -"<<"Forbidden value (" << this->probationTime << ") on element of UpdateSelfAgressableStatusMessage.probationTime.";
    }
    else
    {
      return;
    }
  }
}

UpdateSelfAgressableStatusMessage::UpdateSelfAgressableStatusMessage()
{
  m_type = MessageEnum::UPDATESELFAGRESSABLESTATUSMESSAGE;
}

