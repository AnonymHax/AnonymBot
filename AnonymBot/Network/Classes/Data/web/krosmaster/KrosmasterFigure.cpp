#include "KrosmasterFigure.h"

void KrosmasterFigure::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterFigure(param1);
}

void KrosmasterFigure::serializeAs_KrosmasterFigure(Writer *param1)
{
  param1->writeUTF(this->uid);
  if(this->figure < 0)
  {
    qDebug()<<"ERREUR - KrosmasterFigure -"<<"Forbidden value (" << this->figure << ") on element figure.";
  }
  else
  {
    param1->writeVarShort((int)this->figure);
    if(this->pedestal < 0)
    {
      qDebug()<<"ERREUR - KrosmasterFigure -"<<"Forbidden value (" << this->pedestal << ") on element pedestal.";
    }
    else
    {
      param1->writeVarShort((int)this->pedestal);
      param1->writeBool(this->bound);
      return;
    }
  }
}

void KrosmasterFigure::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterFigure(param1);
}

void KrosmasterFigure::deserializeAs_KrosmasterFigure(Reader *param1)
{
  this->uid = param1->readUTF();
  this->figure = param1->readVarUhShort();
  if(this->figure < 0)
  {
    qDebug()<<"ERREUR - KrosmasterFigure -"<<"Forbidden value (" << this->figure << ") on element of KrosmasterFigure.figure.";
  }
  else
  {
    this->pedestal = param1->readVarUhShort();
    if(this->pedestal < 0)
    {
      qDebug()<<"ERREUR - KrosmasterFigure -"<<"Forbidden value (" << this->pedestal << ") on element of KrosmasterFigure.pedestal.";
    }
    else
    {
      this->bound = param1->readBool();
      return;
    }
  }
}

KrosmasterFigure::KrosmasterFigure()
{
  m_types<<ClassEnum::KROSMASTERFIGURE;
}

bool KrosmasterFigure::operator==(const KrosmasterFigure &compared)
{
  if(uid == compared.uid)
  if(figure == compared.figure)
  if(pedestal == compared.pedestal)
  if(bound == compared.bound)
  return true;
  
  return false;
}

