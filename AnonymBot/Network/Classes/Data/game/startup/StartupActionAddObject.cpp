#include "StartupActionAddObject.h"

void StartupActionAddObject::serialize(Writer *param1)
{
  this->serializeAs_StartupActionAddObject(param1);
}

void StartupActionAddObject::serializeAs_StartupActionAddObject(Writer *param1)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - StartupActionAddObject -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  else
  {
    param1->writeInt((int)this->uid);
    param1->writeUTF(this->title);
    param1->writeUTF(this->text);
    param1->writeUTF(this->descUrl);
    param1->writeUTF(this->pictureUrl);
    param1->writeShort((short)this->items.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->items.size())
    {
      qSharedPointerCast<ObjectItemInformationWithQuantity>(this->items[_loc2_])->serializeAs_ObjectItemInformationWithQuantity(param1);
      _loc2_++;
    }
    return;
  }
}

void StartupActionAddObject::deserialize(Reader *param1)
{
  this->deserializeAs_StartupActionAddObject(param1);
}

void StartupActionAddObject::deserializeAs_StartupActionAddObject(Reader *param1)
{
  QSharedPointer<ObjectItemInformationWithQuantity> _loc4_ ;
  this->uid = param1->readInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - StartupActionAddObject -"<<"Forbidden value (" << this->uid << ") on element of StartupActionAddObject.uid.";
  }
  else
  {
    this->title = param1->readUTF();
    this->text = param1->readUTF();
    this->descUrl = param1->readUTF();
    this->pictureUrl = param1->readUTF();
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = QSharedPointer<ObjectItemInformationWithQuantity>(new ObjectItemInformationWithQuantity() );
      _loc4_->deserialize(param1);
      this->items.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

StartupActionAddObject::StartupActionAddObject()
{
  m_types<<ClassEnum::STARTUPACTIONADDOBJECT;
}

bool StartupActionAddObject::operator==(const StartupActionAddObject &compared)
{
  if(uid == compared.uid)
  if(title == compared.title)
  if(text == compared.text)
  if(descUrl == compared.descUrl)
  if(pictureUrl == compared.pictureUrl)
  if(items == compared.items)
  return true;
  
  return false;
}

