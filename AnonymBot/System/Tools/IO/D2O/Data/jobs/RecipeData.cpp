#include "RecipeData.h"

int RecipeData::getResultId() const
{
  return m_resultId;
}

uint RecipeData::getResultNameId() const
{
  return m_resultNameId;
}

uint RecipeData::getResultTypeId() const
{
  return m_resultTypeId;
}

uint RecipeData::getResultLevel() const
{
  return m_resultLevel;
}

QList<int> RecipeData::getIngredientIds() const
{
  return m_ingredientIds;
}

QList<uint> RecipeData::getQuantities() const
{
  return m_quantities;
}

int RecipeData::getJobId() const
{
  return m_jobId;
}

int RecipeData::getSkillId() const
{
  return m_skillId;
}

QString RecipeData::getResultName() const
{
  return m_I18n->getText(m_resultNameId);
}

void RecipeData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "resultId")
        m_resultId = readInt(field->getValue());
    
    else if(field->getName() == "resultNameId")
        m_resultNameId = readUInt(field->getValue());
    
    else if(field->getName() == "resultTypeId")
        m_resultTypeId = readUInt(field->getValue());
    
    else if(field->getName() == "resultLevel")
        m_resultLevel = readUInt(field->getValue());
    
    else if(field->getName() == "ingredientIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_ingredientIds << readInt(data);
    }
    
    else if(field->getName() == "quantities")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_quantities << readUInt(data);
    }
    
    else if(field->getName() == "jobId")
        m_jobId = readInt(field->getValue());
    
    else if(field->getName() == "skillId")
        m_skillId = readInt(field->getValue());
    
  }
}

