#include "ObjectEffectDice.h"

void ObjectEffectDice::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectDice(param1);
}

void ObjectEffectDice::serializeAs_ObjectEffectDice(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  if(this->diceNum < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceNum << ") on element diceNum.";
  }
  else
  {
    param1->writeVarShort((int)this->diceNum);
    if(this->diceSide < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceSide << ") on element diceSide.";
    }
    else
    {
      param1->writeVarShort((int)this->diceSide);
      if(this->diceConst < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceConst << ") on element diceConst.";
      }
      else
      {
        param1->writeVarShort((int)this->diceConst);
        return;
      }
    }
  }
}

void ObjectEffectDice::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectDice(param1);
}

void ObjectEffectDice::deserializeAs_ObjectEffectDice(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->diceNum = param1->readVarUhShort();
  if(this->diceNum < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceNum << ") on element of ObjectEffectDice.diceNum.";
  }
  else
  {
    this->diceSide = param1->readVarUhShort();
    if(this->diceSide < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceSide << ") on element of ObjectEffectDice.diceSide.";
    }
    else
    {
      this->diceConst = param1->readVarUhShort();
      if(this->diceConst < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectDice -"<<"Forbidden value (" << this->diceConst << ") on element of ObjectEffectDice.diceConst.";
      }
      else
      {
        return;
      }
    }
  }
}

ObjectEffectDice::ObjectEffectDice()
{
  m_types<<ClassEnum::OBJECTEFFECTDICE;
}

bool ObjectEffectDice::operator==(const ObjectEffectDice &compared)
{
  if(diceNum == compared.diceNum)
  if(diceSide == compared.diceSide)
  if(diceConst == compared.diceConst)
  return true;
  
  return false;
}

