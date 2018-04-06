#include "PopupWarningMessage.h"

void PopupWarningMessage::serialize(Writer *param1)
{
  this->serializeAs_PopupWarningMessage(param1);
}

void PopupWarningMessage::serializeAs_PopupWarningMessage(Writer *param1)
{
  if(this->lockDuration < 0 || this->lockDuration > 255)
  {
    qDebug()<<"ERREUR - PopupWarningMessage -"<<"Forbidden value (" << this->lockDuration << ") on element lockDuration.";
  }
  else
  {
    param1->writeByte(this->lockDuration);
    param1->writeUTF(this->author);
    param1->writeUTF(this->content);
    return;
  }
}

void PopupWarningMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PopupWarningMessage(param1);
}

void PopupWarningMessage::deserializeAs_PopupWarningMessage(Reader *param1)
{
  this->lockDuration = param1->readUByte();
  if(this->lockDuration < 0 || this->lockDuration > 255)
  {
    qDebug()<<"ERREUR - PopupWarningMessage -"<<"Forbidden value (" << this->lockDuration << ") on element of PopupWarningMessage.lockDuration.";
  }
  else
  {
    this->author = param1->readUTF();
    this->content = param1->readUTF();
    return;
  }
}

PopupWarningMessage::PopupWarningMessage()
{
  m_type = MessageEnum::POPUPWARNINGMESSAGE;
}

