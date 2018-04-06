#include "HumanOptionTitle.h"

void HumanOptionTitle::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionTitle(param1);
}

void HumanOptionTitle::serializeAs_HumanOptionTitle(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionTitle -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  else
  {
    param1->writeVarShort((int)this->titleId);
    param1->writeUTF(this->titleParam);
    return;
  }
}

void HumanOptionTitle::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionTitle(param1);
}

void HumanOptionTitle::deserializeAs_HumanOptionTitle(Reader *param1)
{
  HumanOption::deserialize(param1);
  this->titleId = param1->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionTitle -"<<"Forbidden value (" << this->titleId << ") on element of HumanOptionTitle.titleId.";
  }
  else
  {
    this->titleParam = param1->readUTF();
    return;
  }
}

HumanOptionTitle::HumanOptionTitle()
{
  m_types<<ClassEnum::HUMANOPTIONTITLE;
}

bool HumanOptionTitle::operator==(const HumanOptionTitle &compared)
{
  if(titleId == compared.titleId)
  if(titleParam == compared.titleParam)
  return true;
  
  return false;
}

