#include "AccessoryPreviewErrorMessage.h"

void AccessoryPreviewErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_AccessoryPreviewErrorMessage(param1);
}

void AccessoryPreviewErrorMessage::serializeAs_AccessoryPreviewErrorMessage(Writer *param1)
{
  param1->writeByte(this->error);
}

void AccessoryPreviewErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AccessoryPreviewErrorMessage(param1);
}

void AccessoryPreviewErrorMessage::deserializeAs_AccessoryPreviewErrorMessage(Reader *param1)
{
  this->error = param1->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - AccessoryPreviewErrorMessage -"<<"Forbidden value (" << this->error << ") on element of AccessoryPreviewErrorMessage.error.";
  }
  else
  {
    return;
  }
}

AccessoryPreviewErrorMessage::AccessoryPreviewErrorMessage()
{
  m_type = MessageEnum::ACCESSORYPREVIEWERRORMESSAGE;
}

