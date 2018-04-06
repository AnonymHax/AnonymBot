#include "GuildInformationsGeneralMessage.h"

void GuildInformationsGeneralMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInformationsGeneralMessage(param1);
}

void GuildInformationsGeneralMessage::serializeAs_GuildInformationsGeneralMessage(Writer *param1)
{
  param1->writeBool(this->abandonnedPaddock);
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeByte(this->level);
    if(this->expLevelFloor < 0 || this->expLevelFloor > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expLevelFloor << ") on element expLevelFloor.";
    }
    else
    {
      param1->writeVarLong((double)this->expLevelFloor);
      if(this->experience < 0 || this->experience > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->experience << ") on element experience.";
      }
      else
      {
        param1->writeVarLong((double)this->experience);
        if(this->expNextLevelFloor < 0 || this->expNextLevelFloor > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expNextLevelFloor << ") on element expNextLevelFloor.";
        }
        else
        {
          param1->writeVarLong((double)this->expNextLevelFloor);
          if(this->creationDate < 0)
          {
            qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
          }
          else
          {
            param1->writeInt((int)this->creationDate);
            if(this->nbTotalMembers < 0)
            {
              qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->nbTotalMembers << ") on element nbTotalMembers.";
            }
            else
            {
              param1->writeVarShort((int)this->nbTotalMembers);
              if(this->nbConnectedMembers < 0)
              {
                qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->nbConnectedMembers << ") on element nbConnectedMembers.";
              }
              else
              {
                param1->writeVarShort((int)this->nbConnectedMembers);
                return;
              }
            }
          }
        }
      }
    }
  }
}

void GuildInformationsGeneralMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInformationsGeneralMessage(param1);
}

void GuildInformationsGeneralMessage::deserializeAs_GuildInformationsGeneralMessage(Reader *param1)
{
  this->abandonnedPaddock = param1->readBool();
  this->level = param1->readUByte();
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->level << ") on element of GuildInformationsGeneralMessage.level.";
  }
  else
  {
    this->expLevelFloor = param1->readVarUhLong();
    if(this->expLevelFloor < 0 || this->expLevelFloor > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expLevelFloor << ") on element of GuildInformationsGeneralMessage.expLevelFloor.";
    }
    else
    {
      this->experience = param1->readVarUhLong();
      if(this->experience < 0 || this->experience > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->experience << ") on element of GuildInformationsGeneralMessage.experience.";
      }
      else
      {
        this->expNextLevelFloor = param1->readVarUhLong();
        if(this->expNextLevelFloor < 0 || this->expNextLevelFloor > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->expNextLevelFloor << ") on element of GuildInformationsGeneralMessage.expNextLevelFloor.";
        }
        else
        {
          this->creationDate = param1->readInt();
          if(this->creationDate < 0)
          {
            qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->creationDate << ") on element of GuildInformationsGeneralMessage.creationDate.";
          }
          else
          {
            this->nbTotalMembers = param1->readVarUhShort();
            if(this->nbTotalMembers < 0)
            {
              qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->nbTotalMembers << ") on element of GuildInformationsGeneralMessage.nbTotalMembers.";
            }
            else
            {
              this->nbConnectedMembers = param1->readVarUhShort();
              if(this->nbConnectedMembers < 0)
              {
                qDebug()<<"ERREUR - GuildInformationsGeneralMessage -"<<"Forbidden value (" << this->nbConnectedMembers << ") on element of GuildInformationsGeneralMessage.nbConnectedMembers.";
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
  }
}

GuildInformationsGeneralMessage::GuildInformationsGeneralMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSGENERALMESSAGE;
}

