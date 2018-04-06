#include "ActorExtendedAlignmentInformations.h"

void ActorExtendedAlignmentInformations::serialize(Writer *param1)
{
  this->serializeAs_ActorExtendedAlignmentInformations(param1);
}

void ActorExtendedAlignmentInformations::serializeAs_ActorExtendedAlignmentInformations(Writer *param1)
{
  ActorAlignmentInformations::serializeAs_ActorAlignmentInformations(param1);
  if(this->honor < 0 || this->honor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honor << ") on element honor.";
  }
  else
  {
    param1->writeVarShort((int)this->honor);
    if(this->honorGradeFloor < 0 || this->honorGradeFloor > 20000)
    {
      qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorGradeFloor << ") on element honorGradeFloor.";
    }
    else
    {
      param1->writeVarShort((int)this->honorGradeFloor);
      if(this->honorNextGradeFloor < 0 || this->honorNextGradeFloor > 20000)
      {
        qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorNextGradeFloor << ") on element honorNextGradeFloor.";
      }
      else
      {
        param1->writeVarShort((int)this->honorNextGradeFloor);
        param1->writeByte(this->aggressable);
        return;
      }
    }
  }
}

void ActorExtendedAlignmentInformations::deserialize(Reader *param1)
{
  this->deserializeAs_ActorExtendedAlignmentInformations(param1);
}

void ActorExtendedAlignmentInformations::deserializeAs_ActorExtendedAlignmentInformations(Reader *param1)
{
  ActorAlignmentInformations::deserialize(param1);
  this->honor = param1->readVarUhShort();
  if(this->honor < 0 || this->honor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honor << ") on element of ActorExtendedAlignmentInformations.honor.";
  }
  else
  {
    this->honorGradeFloor = param1->readVarUhShort();
    if(this->honorGradeFloor < 0 || this->honorGradeFloor > 20000)
    {
      qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorGradeFloor << ") on element of ActorExtendedAlignmentInformations.honorGradeFloor.";
    }
    else
    {
      this->honorNextGradeFloor = param1->readVarUhShort();
      if(this->honorNextGradeFloor < 0 || this->honorNextGradeFloor > 20000)
      {
        qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorNextGradeFloor << ") on element of ActorExtendedAlignmentInformations.honorNextGradeFloor.";
      }
      else
      {
        this->aggressable = param1->readByte();
        if(this->aggressable < 0)
        {
          qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->aggressable << ") on element of ActorExtendedAlignmentInformations.aggressable.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

ActorExtendedAlignmentInformations::ActorExtendedAlignmentInformations()
{
  m_types<<ClassEnum::ACTOREXTENDEDALIGNMENTINFORMATIONS;
}

bool ActorExtendedAlignmentInformations::operator==(const ActorExtendedAlignmentInformations &compared)
{
  if(honor == compared.honor)
  if(honorGradeFloor == compared.honorGradeFloor)
  if(honorNextGradeFloor == compared.honorNextGradeFloor)
  if(aggressable == compared.aggressable)
  return true;
  
  return false;
}

