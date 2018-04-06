#include "InteractiveElement.h"

void InteractiveElement::serialize(Writer *param1)
{
  this->serializeAs_InteractiveElement(param1);
}

void InteractiveElement::serializeAs_InteractiveElement(Writer *param1)
{
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElement -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  else
  {
    param1->writeInt((int)this->elementId);
    param1->writeInt((int)this->elementTypeId);
    param1->writeShort((short)this->enabledSkills.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->enabledSkills.size())
    {
      param1->writeShort((short)qSharedPointerCast<InteractiveElementSkill>(this->enabledSkills[_loc2_])->getTypes().last());
      qSharedPointerCast<InteractiveElementSkill>(this->enabledSkills[_loc2_])->serialize(param1);
      _loc2_++;
    }
    param1->writeShort((short)this->disabledSkills.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->disabledSkills.size())
    {
      param1->writeShort((short)qSharedPointerCast<InteractiveElementSkill>(this->disabledSkills[_loc3_])->getTypes().last());
      qSharedPointerCast<InteractiveElementSkill>(this->disabledSkills[_loc3_])->serialize(param1);
      _loc3_++;
    }
    param1->writeBool(this->onCurrentMap);
    return;
  }
}

void InteractiveElement::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveElement(param1);
}

void InteractiveElement::deserializeAs_InteractiveElement(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<InteractiveElementSkill> _loc7_ ;
  uint _loc8_ = 0;
  QSharedPointer<InteractiveElementSkill> _loc9_ ;
  this->elementId = param1->readInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElement -"<<"Forbidden value (" << this->elementId << ") on element of InteractiveElement.elementId.";
  }
  else
  {
    this->elementTypeId = param1->readInt();
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = param1->readUShort();
      _loc7_ = qSharedPointerCast<InteractiveElementSkill>(ClassManagerSingleton::get()->getClass(_loc6_));
      _loc7_->deserialize(param1);
      this->enabledSkills.append(_loc7_);
      _loc3_++;
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc8_ = param1->readUShort();
      _loc9_ = qSharedPointerCast<InteractiveElementSkill>(ClassManagerSingleton::get()->getClass(_loc8_));
      _loc9_->deserialize(param1);
      this->disabledSkills.append(_loc9_);
      _loc5_++;
    }
    this->onCurrentMap = param1->readBool();
    return;
  }
}

InteractiveElement::InteractiveElement()
{
  m_types<<ClassEnum::INTERACTIVEELEMENT;
}

bool InteractiveElement::operator==(const InteractiveElement &compared)
{
  if(elementId == compared.elementId)
  if(elementTypeId == compared.elementTypeId)
  if(enabledSkills == compared.enabledSkills)
  if(disabledSkills == compared.disabledSkills)
  if(onCurrentMap == compared.onCurrentMap)
  return true;
  
  return false;
}

