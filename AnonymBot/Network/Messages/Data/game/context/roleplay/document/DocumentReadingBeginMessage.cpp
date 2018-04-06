#include "DocumentReadingBeginMessage.h"

void DocumentReadingBeginMessage::serialize(Writer *param1)
{
  this->serializeAs_DocumentReadingBeginMessage(param1);
}

void DocumentReadingBeginMessage::serializeAs_DocumentReadingBeginMessage(Writer *param1)
{
  if(this->documentId < 0)
  {
    qDebug()<<"ERREUR - DocumentReadingBeginMessage -"<<"Forbidden value (" << this->documentId << ") on element documentId.";
  }
  else
  {
    param1->writeVarShort((int)this->documentId);
    return;
  }
}

void DocumentReadingBeginMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DocumentReadingBeginMessage(param1);
}

void DocumentReadingBeginMessage::deserializeAs_DocumentReadingBeginMessage(Reader *param1)
{
  this->documentId = param1->readVarUhShort();
  if(this->documentId < 0)
  {
    qDebug()<<"ERREUR - DocumentReadingBeginMessage -"<<"Forbidden value (" << this->documentId << ") on element of DocumentReadingBeginMessage.documentId.";
  }
  else
  {
    return;
  }
}

DocumentReadingBeginMessage::DocumentReadingBeginMessage()
{
  m_type = MessageEnum::DOCUMENTREADINGBEGINMESSAGE;
}

