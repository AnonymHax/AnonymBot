#include "ContentPart.h"

void ContentPart::serialize(Writer *param1)
{
  this->serializeAs_ContentPart(param1);
}

void ContentPart::serializeAs_ContentPart(Writer *param1)
{
  param1->writeUTF(this->id);
  param1->writeByte(this->state);
}

void ContentPart::deserialize(Reader *param1)
{
  this->deserializeAs_ContentPart(param1);
}

void ContentPart::deserializeAs_ContentPart(Reader *param1)
{
  this->id = param1->readUTF();
  this->state = param1->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - ContentPart -"<<"Forbidden value (" << this->state << ") on element of ContentPart.state.";
  }
  else
  {
    return;
  }
}

ContentPart::ContentPart()
{
  m_types<<ClassEnum::CONTENTPART;
}

bool ContentPart::operator==(const ContentPart &compared)
{
  if(id == compared.id)
  if(state == compared.state)
  return true;
  
  return false;
}

