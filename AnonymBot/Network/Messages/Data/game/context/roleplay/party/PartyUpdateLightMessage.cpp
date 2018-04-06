#include "PartyUpdateLightMessage.h"

void PartyUpdateLightMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyUpdateLightMessage(param1);
}

void PartyUpdateLightMessage::serializeAs_PartyUpdateLightMessage(Writer *param1)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(param1);
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarLong((double)this->id);
    if(this->lifePoints < 0)
    {
      qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
    }
    else
    {
      param1->writeVarInt((int)this->lifePoints);
      if(this->maxLifePoints < 0)
      {
        qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
      }
      else
      {
        param1->writeVarInt((int)this->maxLifePoints);
        if(this->prospecting < 0)
        {
          qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
        }
        else
        {
          param1->writeVarShort((int)this->prospecting);
          if(this->regenRate < 0 || this->regenRate > 255)
          {
            qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
          }
          else
          {
            param1->writeByte(this->regenRate);
            return;
          }
        }
      }
    }
  }
}

void PartyUpdateLightMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyUpdateLightMessage(param1);
}

void PartyUpdateLightMessage::deserializeAs_PartyUpdateLightMessage(Reader *param1)
{
  AbstractPartyEventMessage::deserialize(param1);
  this->id = param1->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->id << ") on element of PartyUpdateLightMessage.id.";
  }
  else
  {
    this->lifePoints = param1->readVarUhInt();
    if(this->lifePoints < 0)
    {
      qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->lifePoints << ") on element of PartyUpdateLightMessage.lifePoints.";
    }
    else
    {
      this->maxLifePoints = param1->readVarUhInt();
      if(this->maxLifePoints < 0)
      {
        qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element of PartyUpdateLightMessage.maxLifePoints.";
      }
      else
      {
        this->prospecting = param1->readVarUhShort();
        if(this->prospecting < 0)
        {
          qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->prospecting << ") on element of PartyUpdateLightMessage.prospecting.";
        }
        else
        {
          this->regenRate = param1->readUByte();
          if(this->regenRate < 0 || this->regenRate > 255)
          {
            qDebug()<<"ERREUR - PartyUpdateLightMessage -"<<"Forbidden value (" << this->regenRate << ") on element of PartyUpdateLightMessage.regenRate.";
          }
          else
          {
            return;
          }
        }
      }
    }
  }
}

PartyUpdateLightMessage::PartyUpdateLightMessage()
{
  m_type = MessageEnum::PARTYUPDATELIGHTMESSAGE;
}

