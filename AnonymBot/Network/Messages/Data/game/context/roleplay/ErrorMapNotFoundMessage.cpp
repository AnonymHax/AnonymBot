#include "ErrorMapNotFoundMessage.h"

void ErrorMapNotFoundMessage::serialize(Writer *param1)
{
  this->serializeAs_ErrorMapNotFoundMessage(param1);
}

void ErrorMapNotFoundMessage::serializeAs_ErrorMapNotFoundMessage(Writer *param1)
{
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - ErrorMapNotFoundMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    return;
  }
}

void ErrorMapNotFoundMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ErrorMapNotFoundMessage(param1);
}

void ErrorMapNotFoundMessage::deserializeAs_ErrorMapNotFoundMessage(Reader *param1)
{
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - ErrorMapNotFoundMessage -"<<"Forbidden value (" << this->mapId << ") on element of ErrorMapNotFoundMessage.mapId.";
  }
  else
  {
    return;
  }
}

ErrorMapNotFoundMessage::ErrorMapNotFoundMessage()
{
  m_type = MessageEnum::ERRORMAPNOTFOUNDMESSAGE;
}

