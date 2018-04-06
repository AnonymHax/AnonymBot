#include "StatedElement.h"

void StatedElement::serialize(Writer *param1)
{
  this->serializeAs_StatedElement(param1);
}

void StatedElement::serializeAs_StatedElement(Writer *param1)
{
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  else
  {
    param1->writeInt((int)this->elementId);
    if(this->elementCellId < 0 || this->elementCellId > 559)
    {
      qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementCellId << ") on element elementCellId.";
    }
    else
    {
      param1->writeVarShort((int)this->elementCellId);
      if(this->elementState < 0)
      {
        qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementState << ") on element elementState.";
      }
      else
      {
        param1->writeVarInt((int)this->elementState);
        param1->writeBool(this->onCurrentMap);
        return;
      }
    }
  }
}

void StatedElement::deserialize(Reader *param1)
{
  this->deserializeAs_StatedElement(param1);
}

void StatedElement::deserializeAs_StatedElement(Reader *param1)
{
  this->elementId = param1->readInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementId << ") on element of StatedElement.elementId.";
  }
  else
  {
    this->elementCellId = param1->readVarUhShort();
    if(this->elementCellId < 0 || this->elementCellId > 559)
    {
      qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementCellId << ") on element of StatedElement.elementCellId.";
    }
    else
    {
      this->elementState = param1->readVarUhInt();
      if(this->elementState < 0)
      {
        qDebug()<<"ERREUR - StatedElement -"<<"Forbidden value (" << this->elementState << ") on element of StatedElement.elementState.";
      }
      else
      {
        this->onCurrentMap = param1->readBool();
        return;
      }
    }
  }
}

StatedElement::StatedElement()
{
  m_types<<ClassEnum::STATEDELEMENT;
}

bool StatedElement::operator==(const StatedElement &compared)
{
  if(elementId == compared.elementId)
  if(elementCellId == compared.elementCellId)
  if(elementState == compared.elementState)
  if(onCurrentMap == compared.onCurrentMap)
  return true;
  
  return false;
}

