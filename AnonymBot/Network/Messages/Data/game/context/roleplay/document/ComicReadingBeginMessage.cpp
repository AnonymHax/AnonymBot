#include "ComicReadingBeginMessage.h"

void ComicReadingBeginMessage::serialize(Writer *param1)
{
  this->serializeAs_ComicReadingBeginMessage(param1);
}

void ComicReadingBeginMessage::serializeAs_ComicReadingBeginMessage(Writer *param1)
{
  if(this->comicId < 0)
  {
    qDebug()<<"ERREUR - ComicReadingBeginMessage -"<<"Forbidden value (" << this->comicId << ") on element comicId.";
  }
  else
  {
    param1->writeVarShort((int)this->comicId);
    return;
  }
}

void ComicReadingBeginMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ComicReadingBeginMessage(param1);
}

void ComicReadingBeginMessage::deserializeAs_ComicReadingBeginMessage(Reader *param1)
{
  this->comicId = param1->readVarUhShort();
  if(this->comicId < 0)
  {
    qDebug()<<"ERREUR - ComicReadingBeginMessage -"<<"Forbidden value (" << this->comicId << ") on element of ComicReadingBeginMessage.comicId.";
  }
  else
  {
    return;
  }
}

ComicReadingBeginMessage::ComicReadingBeginMessage()
{
  m_type = MessageEnum::COMICREADINGBEGINMESSAGE;
}

