#include "ChangeHavenBagRoomRequestMessage.h"

void ChangeHavenBagRoomRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ChangeHavenBagRoomRequestMessage(param1);
}

void ChangeHavenBagRoomRequestMessage::serializeAs_ChangeHavenBagRoomRequestMessage(Writer *param1)
{
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - ChangeHavenBagRoomRequestMessage -"<<"Forbidden value (" << this->roomId << ") on element roomId.";
  }
  else
  {
    param1->writeByte(this->roomId);
    return;
  }
}

void ChangeHavenBagRoomRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChangeHavenBagRoomRequestMessage(param1);
}

void ChangeHavenBagRoomRequestMessage::deserializeAs_ChangeHavenBagRoomRequestMessage(Reader *param1)
{
  this->roomId = param1->readByte();
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - ChangeHavenBagRoomRequestMessage -"<<"Forbidden value (" << this->roomId << ") on element of ChangeHavenBagRoomRequestMessage.roomId.";
  }
  else
  {
    return;
  }
}

ChangeHavenBagRoomRequestMessage::ChangeHavenBagRoomRequestMessage()
{
  m_type = MessageEnum::CHANGEHAVENBAGROOMREQUESTMESSAGE;
}

