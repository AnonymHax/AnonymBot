#include "TaxCollectorDialogQuestionExtendedMessage.h"

void TaxCollectorDialogQuestionExtendedMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorDialogQuestionExtendedMessage(param1);
}

void TaxCollectorDialogQuestionExtendedMessage::serializeAs_TaxCollectorDialogQuestionExtendedMessage(Writer *param1)
{
  TaxCollectorDialogQuestionBasicMessage::serializeAs_TaxCollectorDialogQuestionBasicMessage(param1);
  if(this->maxPods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->maxPods << ") on element maxPods.";
  }
  else
  {
    param1->writeVarShort((int)this->maxPods);
    if(this->prospecting < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
    }
    else
    {
      param1->writeVarShort((int)this->prospecting);
      if(this->wisdom < 0)
      {
        qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->wisdom << ") on element wisdom.";
      }
      else
      {
        param1->writeVarShort((int)this->wisdom);
        if(this->taxCollectorsCount < 0)
        {
          qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element taxCollectorsCount.";
        }
        else
        {
          param1->writeByte(this->taxCollectorsCount);
          param1->writeInt((int)this->taxCollectorAttack);
          if(this->kamas < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
          }
          else
          {
            param1->writeVarInt((int)this->kamas);
            if(this->experience < 0 || this->experience > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->experience << ") on element experience.";
            }
            else
            {
              param1->writeVarLong((double)this->experience);
              if(this->pods < 0)
              {
                qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->pods << ") on element pods.";
              }
              else
              {
                param1->writeVarInt((int)this->pods);
                if(this->itemsValue < 0)
                {
                  qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->itemsValue << ") on element itemsValue.";
                }
                else
                {
                  param1->writeVarInt((int)this->itemsValue);
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

void TaxCollectorDialogQuestionExtendedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorDialogQuestionExtendedMessage(param1);
}

void TaxCollectorDialogQuestionExtendedMessage::deserializeAs_TaxCollectorDialogQuestionExtendedMessage(Reader *param1)
{
  TaxCollectorDialogQuestionBasicMessage::deserialize(param1);
  this->maxPods = param1->readVarUhShort();
  if(this->maxPods < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->maxPods << ") on element of TaxCollectorDialogQuestionExtendedMessage.maxPods.";
  }
  else
  {
    this->prospecting = param1->readVarUhShort();
    if(this->prospecting < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->prospecting << ") on element of TaxCollectorDialogQuestionExtendedMessage.prospecting.";
    }
    else
    {
      this->wisdom = param1->readVarUhShort();
      if(this->wisdom < 0)
      {
        qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->wisdom << ") on element of TaxCollectorDialogQuestionExtendedMessage.wisdom.";
      }
      else
      {
        this->taxCollectorsCount = param1->readByte();
        if(this->taxCollectorsCount < 0)
        {
          qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element of TaxCollectorDialogQuestionExtendedMessage.taxCollectorsCount.";
        }
        else
        {
          this->taxCollectorAttack = param1->readInt();
          this->kamas = param1->readVarUhInt();
          if(this->kamas < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->kamas << ") on element of TaxCollectorDialogQuestionExtendedMessage.kamas.";
          }
          else
          {
            this->experience = param1->readVarUhLong();
            if(this->experience < 0 || this->experience > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->experience << ") on element of TaxCollectorDialogQuestionExtendedMessage.experience.";
            }
            else
            {
              this->pods = param1->readVarUhInt();
              if(this->pods < 0)
              {
                qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->pods << ") on element of TaxCollectorDialogQuestionExtendedMessage.pods.";
              }
              else
              {
                this->itemsValue = param1->readVarUhInt();
                if(this->itemsValue < 0)
                {
                  qDebug()<<"ERREUR - TaxCollectorDialogQuestionExtendedMessage -"<<"Forbidden value (" << this->itemsValue << ") on element of TaxCollectorDialogQuestionExtendedMessage.itemsValue.";
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
}

TaxCollectorDialogQuestionExtendedMessage::TaxCollectorDialogQuestionExtendedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE;
}

