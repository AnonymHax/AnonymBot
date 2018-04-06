#include "DisplayNumericalValuePaddockMessage.h"

void DisplayNumericalValuePaddockMessage::serialize(Writer *param1)
{
  this->serializeAs_DisplayNumericalValuePaddockMessage(param1);
}

void DisplayNumericalValuePaddockMessage::serializeAs_DisplayNumericalValuePaddockMessage(Writer *param1)
{
  param1->writeInt((int)this->rideId);
  param1->writeInt((int)this->value);
  param1->writeByte(this->type);
}

void DisplayNumericalValuePaddockMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DisplayNumericalValuePaddockMessage(param1);
}

void DisplayNumericalValuePaddockMessage::deserializeAs_DisplayNumericalValuePaddockMessage(Reader *param1)
{
  this->rideId = param1->readInt();
  this->value = param1->readInt();
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - DisplayNumericalValuePaddockMessage -"<<"Forbidden value (" << this->type << ") on element of DisplayNumericalValuePaddockMessage.type.";
  }
  else
  {
    return;
  }
}

DisplayNumericalValuePaddockMessage::DisplayNumericalValuePaddockMessage()
{
  m_type = MessageEnum::DISPLAYNUMERICALVALUEPADDOCKMESSAGE;
}

