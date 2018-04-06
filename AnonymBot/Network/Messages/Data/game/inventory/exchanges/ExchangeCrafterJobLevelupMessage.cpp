#include "ExchangeCrafterJobLevelupMessage.h"

void ExchangeCrafterJobLevelupMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCrafterJobLevelupMessage(param1);
}

void ExchangeCrafterJobLevelupMessage::serializeAs_ExchangeCrafterJobLevelupMessage(Writer *param1)
{
  if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
  {
    qDebug()<<"ERREUR - ExchangeCrafterJobLevelupMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element crafterJobLevel.";
  }
  else
  {
    param1->writeByte(this->crafterJobLevel);
    return;
  }
}

void ExchangeCrafterJobLevelupMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCrafterJobLevelupMessage(param1);
}

void ExchangeCrafterJobLevelupMessage::deserializeAs_ExchangeCrafterJobLevelupMessage(Reader *param1)
{
  this->crafterJobLevel = param1->readUByte();
  if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
  {
    qDebug()<<"ERREUR - ExchangeCrafterJobLevelupMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element of ExchangeCrafterJobLevelupMessage.crafterJobLevel.";
  }
  else
  {
    return;
  }
}

ExchangeCrafterJobLevelupMessage::ExchangeCrafterJobLevelupMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTERJOBLEVELUPMESSAGE;
}

