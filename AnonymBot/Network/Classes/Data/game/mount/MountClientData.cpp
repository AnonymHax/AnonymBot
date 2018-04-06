#include "MountClientData.h"

void MountClientData::serialize(Writer *param1)
{
  this->serializeAs_MountClientData(param1);
}

void MountClientData::serializeAs_MountClientData(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->sex);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->isRideable);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->isWild);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->isFecondationReady);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 4, this->useHarnessColors);
  param1->writeByte(_loc2_);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    if(this->model < 0)
    {
      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->model << ") on element model.";
    }
    else
    {
      param1->writeVarInt((int)this->model);
      param1->writeShort((short)this->ancestor.size());
      uint _loc3_ = 0;
      while(_loc3_ < this->ancestor.size())
      {
        if(this->ancestor[_loc3_] < 0)
        {
          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->ancestor[_loc3_] << ") on element 3 (starting at 1) of ancestor.";
        }
        else
        {
          param1->writeInt((int)this->ancestor[_loc3_]);
          _loc3_++;
          continue;
        }
      }
      param1->writeShort((short)this->behaviors.size());
      uint _loc4_ = 0;
      while(_loc4_ < this->behaviors.size())
      {
        if(this->behaviors[_loc4_] < 0)
        {
          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->behaviors[_loc4_] << ") on element 4 (starting at 1) of behaviors.";
        }
        else
        {
          param1->writeInt((int)this->behaviors[_loc4_]);
          _loc4_++;
          continue;
        }
      }
      param1->writeUTF(this->name);
      if(this->ownerId < 0)
      {
        qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->ownerId << ") on element ownerId.";
      }
      else
      {
        param1->writeInt((int)this->ownerId);
        if(this->experience < 0 || this->experience > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experience << ") on element experience.";
        }
        else
        {
          param1->writeVarLong((double)this->experience);
          if(this->experienceForLevel < 0 || this->experienceForLevel > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForLevel << ") on element experienceForLevel.";
          }
          else
          {
            param1->writeVarLong((double)this->experienceForLevel);
            if(this->experienceForNextLevel < -9.007199254740992E15 || this->experienceForNextLevel > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForNextLevel << ") on element experienceForNextLevel.";
            }
            else
            {
              param1->writeDouble(this->experienceForNextLevel);
              if(this->level < 0)
              {
                qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->level << ") on element level.";
              }
              else
              {
                param1->writeByte(this->level);
                if(this->maxPods < 0)
                {
                  qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maxPods << ") on element maxPods.";
                }
                else
                {
                  param1->writeVarInt((int)this->maxPods);
                  if(this->stamina < 0)
                  {
                    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->stamina << ") on element stamina.";
                  }
                  else
                  {
                    param1->writeVarInt((int)this->stamina);
                    if(this->staminaMax < 0)
                    {
                      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->staminaMax << ") on element staminaMax.";
                    }
                    else
                    {
                      param1->writeVarInt((int)this->staminaMax);
                      if(this->maturity < 0)
                      {
                        qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturity << ") on element maturity.";
                      }
                      else
                      {
                        param1->writeVarInt((int)this->maturity);
                        if(this->maturityForAdult < 0)
                        {
                          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturityForAdult << ") on element maturityForAdult.";
                        }
                        else
                        {
                          param1->writeVarInt((int)this->maturityForAdult);
                          if(this->energy < 0)
                          {
                            qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energy << ") on element energy.";
                          }
                          else
                          {
                            param1->writeVarInt((int)this->energy);
                            if(this->energyMax < 0)
                            {
                              qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energyMax << ") on element energyMax.";
                            }
                            else
                            {
                              param1->writeVarInt((int)this->energyMax);
                              param1->writeInt((int)this->serenity);
                              param1->writeInt((int)this->aggressivityMax);
                              if(this->serenityMax < 0)
                              {
                                qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->serenityMax << ") on element serenityMax.";
                              }
                              else
                              {
                                param1->writeVarInt((int)this->serenityMax);
                                if(this->love < 0)
                                {
                                  qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->love << ") on element love.";
                                }
                                else
                                {
                                  param1->writeVarInt((int)this->love);
                                  if(this->loveMax < 0)
                                  {
                                    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->loveMax << ") on element loveMax.";
                                  }
                                  else
                                  {
                                    param1->writeVarInt((int)this->loveMax);
                                    param1->writeInt((int)this->fecondationTime);
                                    if(this->boostLimiter < 0)
                                    {
                                      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostLimiter << ") on element boostLimiter.";
                                    }
                                    else
                                    {
                                      param1->writeInt((int)this->boostLimiter);
                                      if(this->boostMax < -9.007199254740992E15 || this->boostMax > 9.007199254740992E15)
                                      {
                                        qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostMax << ") on element boostMax.";
                                      }
                                      else
                                      {
                                        param1->writeDouble(this->boostMax);
                                        param1->writeInt((int)this->reproductionCount);
                                        if(this->reproductionCountMax < 0)
                                        {
                                          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->reproductionCountMax << ") on element reproductionCountMax.";
                                        }
                                        else
                                        {
                                          param1->writeVarInt((int)this->reproductionCountMax);
                                          if(this->harnessGID < 0)
                                          {
                                            qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->harnessGID << ") on element harnessGID.";
                                          }
                                          else
                                          {
                                            param1->writeVarShort((int)this->harnessGID);
                                            param1->writeShort((short)this->effectList.size());
                                            uint _loc5_ = 0;
                                            while(_loc5_ < this->effectList.size())
                                            {
                                              qSharedPointerCast<ObjectEffectInteger>(this->effectList[_loc5_])->serializeAs_ObjectEffectInteger(param1);
                                              _loc5_++;
                                            }
                                            return;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void MountClientData::deserialize(Reader *param1)
{
  this->deserializeAs_MountClientData(param1);
}

void MountClientData::deserializeAs_MountClientData(Reader *param1)
{
  uint _loc9_ = 0;
  uint _loc10_ = 0;
  QSharedPointer<ObjectEffectInteger> _loc11_ ;
  uint _loc2_ = param1->readByte();
  this->sex = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->isRideable = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->isWild = BooleanByteWrapper::getFlag(_loc2_, 2);
  this->isFecondationReady = BooleanByteWrapper::getFlag(_loc2_, 3);
  this->useHarnessColors = BooleanByteWrapper::getFlag(_loc2_, 4);
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->id << ") on element of MountClientData.id.";
  }
  else
  {
    this->model = param1->readVarUhInt();
    if(this->model < 0)
    {
      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->model << ") on element of MountClientData.model.";
    }
    else
    {
      uint _loc3_ = param1->readUShort();
      uint _loc4_ = 0;
      while(_loc4_ < _loc3_)
      {
        _loc9_ = param1->readInt();
        if(_loc9_ < 0)
        {
          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << _loc9_ << ") on elements of ancestor.";
        }
        else
        {
          this->ancestor.append(_loc9_);
          _loc4_++;
          continue;
        }
      }
      uint _loc5_ = param1->readUShort();
      uint _loc6_ = 0;
      while(_loc6_ < _loc5_)
      {
        _loc10_ = param1->readInt();
        if(_loc10_ < 0)
        {
          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << _loc10_ << ") on elements of behaviors.";
        }
        else
        {
          this->behaviors.append(_loc10_);
          _loc6_++;
          continue;
        }
      }
      this->name = param1->readUTF();
      this->ownerId = param1->readInt();
      if(this->ownerId < 0)
      {
        qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->ownerId << ") on element of MountClientData.ownerId.";
      }
      else
      {
        this->experience = param1->readVarUhLong();
        if(this->experience < 0 || this->experience > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experience << ") on element of MountClientData.experience.";
        }
        else
        {
          this->experienceForLevel = param1->readVarUhLong();
          if(this->experienceForLevel < 0 || this->experienceForLevel > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForLevel << ") on element of MountClientData.experienceForLevel.";
          }
          else
          {
            this->experienceForNextLevel = param1->readDouble();
            if(this->experienceForNextLevel < -9.007199254740992E15 || this->experienceForNextLevel > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->experienceForNextLevel << ") on element of MountClientData.experienceForNextLevel.";
            }
            else
            {
              this->level = param1->readByte();
              if(this->level < 0)
              {
                qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->level << ") on element of MountClientData.level.";
              }
              else
              {
                this->maxPods = param1->readVarUhInt();
                if(this->maxPods < 0)
                {
                  qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maxPods << ") on element of MountClientData.maxPods.";
                }
                else
                {
                  this->stamina = param1->readVarUhInt();
                  if(this->stamina < 0)
                  {
                    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->stamina << ") on element of MountClientData.stamina.";
                  }
                  else
                  {
                    this->staminaMax = param1->readVarUhInt();
                    if(this->staminaMax < 0)
                    {
                      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->staminaMax << ") on element of MountClientData.staminaMax.";
                    }
                    else
                    {
                      this->maturity = param1->readVarUhInt();
                      if(this->maturity < 0)
                      {
                        qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturity << ") on element of MountClientData.maturity.";
                      }
                      else
                      {
                        this->maturityForAdult = param1->readVarUhInt();
                        if(this->maturityForAdult < 0)
                        {
                          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->maturityForAdult << ") on element of MountClientData.maturityForAdult.";
                        }
                        else
                        {
                          this->energy = param1->readVarUhInt();
                          if(this->energy < 0)
                          {
                            qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energy << ") on element of MountClientData.energy.";
                          }
                          else
                          {
                            this->energyMax = param1->readVarUhInt();
                            if(this->energyMax < 0)
                            {
                              qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->energyMax << ") on element of MountClientData.energyMax.";
                            }
                            else
                            {
                              this->serenity = param1->readInt();
                              this->aggressivityMax = param1->readInt();
                              this->serenityMax = param1->readVarUhInt();
                              if(this->serenityMax < 0)
                              {
                                qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->serenityMax << ") on element of MountClientData.serenityMax.";
                              }
                              else
                              {
                                this->love = param1->readVarUhInt();
                                if(this->love < 0)
                                {
                                  qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->love << ") on element of MountClientData.love.";
                                }
                                else
                                {
                                  this->loveMax = param1->readVarUhInt();
                                  if(this->loveMax < 0)
                                  {
                                    qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->loveMax << ") on element of MountClientData.loveMax.";
                                  }
                                  else
                                  {
                                    this->fecondationTime = param1->readInt();
                                    this->boostLimiter = param1->readInt();
                                    if(this->boostLimiter < 0)
                                    {
                                      qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostLimiter << ") on element of MountClientData.boostLimiter.";
                                    }
                                    else
                                    {
                                      this->boostMax = param1->readDouble();
                                      if(this->boostMax < -9.007199254740992E15 || this->boostMax > 9.007199254740992E15)
                                      {
                                        qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->boostMax << ") on element of MountClientData.boostMax.";
                                      }
                                      else
                                      {
                                        this->reproductionCount = param1->readInt();
                                        this->reproductionCountMax = param1->readVarUhInt();
                                        if(this->reproductionCountMax < 0)
                                        {
                                          qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->reproductionCountMax << ") on element of MountClientData.reproductionCountMax.";
                                        }
                                        else
                                        {
                                          this->harnessGID = param1->readVarUhShort();
                                          if(this->harnessGID < 0)
                                          {
                                            qDebug()<<"ERREUR - MountClientData -"<<"Forbidden value (" << this->harnessGID << ") on element of MountClientData.harnessGID.";
                                          }
                                          else
                                          {
                                            uint _loc7_ = param1->readUShort();
                                            uint _loc8_ = 0;
                                            while(_loc8_ < _loc7_)
                                            {
                                              _loc11_ = QSharedPointer<ObjectEffectInteger>(new ObjectEffectInteger() );
                                              _loc11_->deserialize(param1);
                                              this->effectList.append(_loc11_);
                                              _loc8_++;
                                            }
                                            return;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

MountClientData::MountClientData()
{
  m_types<<ClassEnum::MOUNTCLIENTDATA;
}

bool MountClientData::operator==(const MountClientData &compared)
{
  if(id == compared.id)
  if(model == compared.model)
  if(ancestor == compared.ancestor)
  if(behaviors == compared.behaviors)
  if(name == compared.name)
  if(sex == compared.sex)
  if(ownerId == compared.ownerId)
  if(experience == compared.experience)
  if(experienceForLevel == compared.experienceForLevel)
  if(experienceForNextLevel == compared.experienceForNextLevel)
  if(level == compared.level)
  if(isRideable == compared.isRideable)
  if(maxPods == compared.maxPods)
  if(isWild == compared.isWild)
  if(stamina == compared.stamina)
  if(staminaMax == compared.staminaMax)
  if(maturity == compared.maturity)
  if(maturityForAdult == compared.maturityForAdult)
  if(energy == compared.energy)
  if(energyMax == compared.energyMax)
  if(serenity == compared.serenity)
  if(aggressivityMax == compared.aggressivityMax)
  if(serenityMax == compared.serenityMax)
  if(love == compared.love)
  if(loveMax == compared.loveMax)
  if(fecondationTime == compared.fecondationTime)
  if(isFecondationReady == compared.isFecondationReady)
  if(boostLimiter == compared.boostLimiter)
  if(boostMax == compared.boostMax)
  if(reproductionCount == compared.reproductionCount)
  if(reproductionCountMax == compared.reproductionCountMax)
  if(harnessGID == compared.harnessGID)
  if(useHarnessColors == compared.useHarnessColors)
  if(effectList == compared.effectList)
  return true;
  
  return false;
}

