#include "MountInformationsForPaddock.h"

void MountInformationsForPaddock::serialize(Writer *param1)
{
  this->serializeAs_MountInformationsForPaddock(param1);
}

void MountInformationsForPaddock::serializeAs_MountInformationsForPaddock(Writer *param1)
{
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - MountInformationsForPaddock -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
  }
  else
  {
    param1->writeVarShort((int)this->modelId);
    param1->writeUTF(this->name);
    param1->writeUTF(this->ownerName);
    return;
  }
}

void MountInformationsForPaddock::deserialize(Reader *param1)
{
  this->deserializeAs_MountInformationsForPaddock(param1);
}

void MountInformationsForPaddock::deserializeAs_MountInformationsForPaddock(Reader *param1)
{
  this->modelId = param1->readVarUhShort();
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - MountInformationsForPaddock -"<<"Forbidden value (" << this->modelId << ") on element of MountInformationsForPaddock.modelId.";
  }
  else
  {
    this->name = param1->readUTF();
    this->ownerName = param1->readUTF();
    return;
  }
}

MountInformationsForPaddock::MountInformationsForPaddock()
{
  m_types<<ClassEnum::MOUNTINFORMATIONSFORPADDOCK;
}

bool MountInformationsForPaddock::operator==(const MountInformationsForPaddock &compared)
{
  if(modelId == compared.modelId)
  if(name == compared.name)
  if(ownerName == compared.ownerName)
  return true;
  
  return false;
}

