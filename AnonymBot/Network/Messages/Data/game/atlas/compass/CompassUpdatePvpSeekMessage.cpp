#include "CompassUpdatePvpSeekMessage.h"

void CompassUpdatePvpSeekMessage::serialize(Writer *param1)
{
  this->serializeAs_CompassUpdatePvpSeekMessage(param1);
}

void CompassUpdatePvpSeekMessage::serializeAs_CompassUpdatePvpSeekMessage(Writer *param1)
{
  CompassUpdateMessage::serializeAs_CompassUpdateMessage(param1);
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CompassUpdatePvpSeekMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  else
  {
    param1->writeVarLong((double)this->memberId);
    param1->writeUTF(this->memberName);
    return;
  }
}

void CompassUpdatePvpSeekMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CompassUpdatePvpSeekMessage(param1);
}

void CompassUpdatePvpSeekMessage::deserializeAs_CompassUpdatePvpSeekMessage(Reader *param1)
{
  CompassUpdateMessage::deserialize(param1);
  this->memberId = param1->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CompassUpdatePvpSeekMessage -"<<"Forbidden value (" << this->memberId << ") on element of CompassUpdatePvpSeekMessage.memberId.";
  }
  else
  {
    this->memberName = param1->readUTF();
    return;
  }
}

CompassUpdatePvpSeekMessage::CompassUpdatePvpSeekMessage()
{
  m_type = MessageEnum::COMPASSUPDATEPVPSEEKMESSAGE;
}

