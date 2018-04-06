#include "NpcData.h"

int NpcData::getId() const
{
  return m_id;
}

uint NpcData::getNameId() const
{
  return m_nameId;
}

QList<QList<int>> NpcData::getDialogMessages() const
{
  return m_dialogMessages;
}

QList<QList<int>> NpcData::getDialogReplies() const
{
  return m_dialogReplies;
}

QList<uint> NpcData::getActions() const
{
  return m_actions;
}

uint NpcData::getGender() const
{
  return m_gender;
}

QString NpcData::getLook() const
{
  return m_look;
}

int NpcData::getTokenShop() const
{
  return m_tokenShop;
}

bool NpcData::getFastAnimsFun() const
{
  return m_fastAnimsFun;
}

QString NpcData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void NpcData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "dialogMessages")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_dialogMessages << secondList;
      }
    }
    
    else if(field->getName() == "dialogReplies")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_dialogReplies << secondList;
      }
    }
    
    else if(field->getName() == "actions")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_actions << readUInt(data);
    }
    
    else if(field->getName() == "gender")
        m_gender = readUInt(field->getValue());
    
    else if(field->getName() == "look")
        m_look = readUTF(field->getValue());
    
    else if(field->getName() == "tokenShop")
        m_tokenShop = readInt(field->getValue());
    
    else if(field->getName() == "fastAnimsFun")
        m_fastAnimsFun = readBool(field->getValue());
    
  }
}

