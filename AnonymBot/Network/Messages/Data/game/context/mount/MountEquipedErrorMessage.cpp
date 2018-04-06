#include "MountEquipedErrorMessage.h"

void MountEquipedErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_MountEquipedErrorMessage(param1);
}

void MountEquipedErrorMessage::serializeAs_MountEquipedErrorMessage(Writer *param1)
{
  param1->writeByte(this->errorType);
}

void MountEquipedErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountEquipedErrorMessage(param1);
}

void MountEquipedErrorMessage::deserializeAs_MountEquipedErrorMessage(Reader *param1)
{
  this->errorType = param1->readByte();
  if(this->errorType < 0)
  {
    qDebug()<<"ERREUR - MountEquipedErrorMessage -"<<"Forbidden value (" << this->errorType << ") on element of MountEquipedErrorMessage.errorType.";
  }
  else
  {
    return;
  }
}

MountEquipedErrorMessage::MountEquipedErrorMessage()
{
  m_type = MessageEnum::MOUNTEQUIPEDERRORMESSAGE;
}

