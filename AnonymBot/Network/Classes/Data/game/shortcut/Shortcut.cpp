#include "Shortcut.h"

void Shortcut::serialize(Writer *param1)
{
  this->serializeAs_Shortcut(param1);
}

void Shortcut::serializeAs_Shortcut(Writer *param1)
{
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - Shortcut -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  else
  {
    param1->writeByte(this->slot);
    return;
  }
}

void Shortcut::deserialize(Reader *param1)
{
  this->deserializeAs_Shortcut(param1);
}

void Shortcut::deserializeAs_Shortcut(Reader *param1)
{
  this->slot = param1->readByte();
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - Shortcut -"<<"Forbidden value (" << this->slot << ") on element of Shortcut.slot.";
  }
  else
  {
    return;
  }
}

Shortcut::Shortcut()
{
  m_types<<ClassEnum::SHORTCUT;
}

bool Shortcut::operator==(const Shortcut &compared)
{
  if(slot == compared.slot)
  return true;
  
  return false;
}

