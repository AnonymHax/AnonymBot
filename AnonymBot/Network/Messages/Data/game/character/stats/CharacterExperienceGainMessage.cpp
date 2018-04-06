#include "CharacterExperienceGainMessage.h"

void CharacterExperienceGainMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterExperienceGainMessage(param1);
}

void CharacterExperienceGainMessage::serializeAs_CharacterExperienceGainMessage(Writer *param1)
{
  if(this->experienceCharacter < 0 || this->experienceCharacter > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceCharacter << ") on element experienceCharacter.";
  }
  else
  {
    param1->writeVarLong((double)this->experienceCharacter);
    if(this->experienceMount < 0 || this->experienceMount > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceMount << ") on element experienceMount.";
    }
    else
    {
      param1->writeVarLong((double)this->experienceMount);
      if(this->experienceGuild < 0 || this->experienceGuild > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceGuild << ") on element experienceGuild.";
      }
      else
      {
        param1->writeVarLong((double)this->experienceGuild);
        if(this->experienceIncarnation < 0 || this->experienceIncarnation > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceIncarnation << ") on element experienceIncarnation.";
        }
        else
        {
          param1->writeVarLong((double)this->experienceIncarnation);
          return;
        }
      }
    }
  }
}

void CharacterExperienceGainMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterExperienceGainMessage(param1);
}

void CharacterExperienceGainMessage::deserializeAs_CharacterExperienceGainMessage(Reader *param1)
{
  this->experienceCharacter = param1->readVarUhLong();
  if(this->experienceCharacter < 0 || this->experienceCharacter > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceCharacter << ") on element of CharacterExperienceGainMessage.experienceCharacter.";
  }
  else
  {
    this->experienceMount = param1->readVarUhLong();
    if(this->experienceMount < 0 || this->experienceMount > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceMount << ") on element of CharacterExperienceGainMessage.experienceMount.";
    }
    else
    {
      this->experienceGuild = param1->readVarUhLong();
      if(this->experienceGuild < 0 || this->experienceGuild > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceGuild << ") on element of CharacterExperienceGainMessage.experienceGuild.";
      }
      else
      {
        this->experienceIncarnation = param1->readVarUhLong();
        if(this->experienceIncarnation < 0 || this->experienceIncarnation > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - CharacterExperienceGainMessage -"<<"Forbidden value (" << this->experienceIncarnation << ") on element of CharacterExperienceGainMessage.experienceIncarnation.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

CharacterExperienceGainMessage::CharacterExperienceGainMessage()
{
  m_type = MessageEnum::CHARACTEREXPERIENCEGAINMESSAGE;
}

