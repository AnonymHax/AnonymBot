#include "ItemData.h"

int ItemData::getId() const
{
  return m_id;
}

uint ItemData::getNameId() const
{
  return m_nameId;
}

uint ItemData::getTypeId() const
{
  return m_typeId;
}

uint ItemData::getDescriptionId() const
{
  return m_descriptionId;
}

uint ItemData::getIconId() const
{
  return m_iconId;
}

uint ItemData::getLevel() const
{
  return m_level;
}

uint ItemData::getRealWeight() const
{
  return m_realWeight;
}

bool ItemData::getCursed() const
{
  return m_cursed;
}

int ItemData::getUseAnimationId() const
{
  return m_useAnimationId;
}

bool ItemData::getUsable() const
{
  return m_usable;
}

bool ItemData::getTargetable() const
{
  return m_targetable;
}

bool ItemData::getExchangeable() const
{
  return m_exchangeable;
}

double ItemData::getPrice() const
{
  return m_price;
}

bool ItemData::getTwoHanded() const
{
  return m_twoHanded;
}

bool ItemData::getEtheral() const
{
  return m_etheral;
}

int ItemData::getItemSetId() const
{
  return m_itemSetId;
}

QString ItemData::getCriteria() const
{
  return m_criteria;
}

QString ItemData::getCriteriaTarget() const
{
  return m_criteriaTarget;
}

bool ItemData::getHideEffects() const
{
  return m_hideEffects;
}

bool ItemData::getEnhanceable() const
{
  return m_enhanceable;
}

bool ItemData::getNonUsableOnAnother() const
{
  return m_nonUsableOnAnother;
}

uint ItemData::getAppearanceId() const
{
  return m_appearanceId;
}

bool ItemData::getSecretRecipe() const
{
  return m_secretRecipe;
}

QList<uint> ItemData::getDropMonsterIds() const
{
  return m_dropMonsterIds;
}

uint ItemData::getRecipeSlots() const
{
  return m_recipeSlots;
}

QList<uint> ItemData::getRecipeIds() const
{
  return m_recipeIds;
}

bool ItemData::getBonusIsSecret() const
{
  return m_bonusIsSecret;
}

QList<EffectInstanceData> ItemData::getPossibleEffects() const
{
  return m_possibleEffects;
}

QList<uint> ItemData::getFavoriteSubAreas() const
{
  return m_favoriteSubAreas;
}

uint ItemData::getFavoriteSubAreasBonus() const
{
  return m_favoriteSubAreasBonus;
}

int ItemData::getCraftXpRatio() const
{
  return m_craftXpRatio;
}

bool ItemData::getNeedUseConfirm() const
{
  return m_needUseConfirm;
}

bool ItemData::getIsDestructible() const
{
  return m_isDestructible;
}

QList<QList<double>> ItemData::getNuggetsBySubarea() const
{
  return m_nuggetsBySubarea;
}

QList<uint> ItemData::getContainerIds() const
{
  return m_containerIds;
}

QList<QList<int>> ItemData::getResourcesBySubarea() const
{
  return m_resourcesBySubarea;
}

QString ItemData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString ItemData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void ItemData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
    else if(field->getName() == "realWeight")
        m_realWeight = readUInt(field->getValue());
    
    else if(field->getName() == "cursed")
        m_cursed = readBool(field->getValue());
    
    else if(field->getName() == "useAnimationId")
        m_useAnimationId = readInt(field->getValue());
    
    else if(field->getName() == "usable")
        m_usable = readBool(field->getValue());
    
    else if(field->getName() == "targetable")
        m_targetable = readBool(field->getValue());
    
    else if(field->getName() == "exchangeable")
        m_exchangeable = readBool(field->getValue());
    
    else if(field->getName() == "price")
        m_price = readDouble(field->getValue());
    
    else if(field->getName() == "twoHanded")
        m_twoHanded = readBool(field->getValue());
    
    else if(field->getName() == "etheral")
        m_etheral = readBool(field->getValue());
    
    else if(field->getName() == "itemSetId")
        m_itemSetId = readInt(field->getValue());
    
    else if(field->getName() == "criteria")
        m_criteria = readUTF(field->getValue());
    
    else if(field->getName() == "criteriaTarget")
        m_criteriaTarget = readUTF(field->getValue());
    
    else if(field->getName() == "hideEffects")
        m_hideEffects = readBool(field->getValue());
    
    else if(field->getName() == "enhanceable")
        m_enhanceable = readBool(field->getValue());
    
    else if(field->getName() == "nonUsableOnAnother")
        m_nonUsableOnAnother = readBool(field->getValue());
    
    else if(field->getName() == "appearanceId")
        m_appearanceId = readUInt(field->getValue());
    
    else if(field->getName() == "secretRecipe")
        m_secretRecipe = readBool(field->getValue());
    
    else if(field->getName() == "dropMonsterIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_dropMonsterIds << readUInt(data);
    }
    
    else if(field->getName() == "recipeSlots")
        m_recipeSlots = readUInt(field->getValue());
    
    else if(field->getName() == "recipeIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_recipeIds << readUInt(data);
    }
    
    else if(field->getName() == "bonusIsSecret")
        m_bonusIsSecret = readBool(field->getValue());
    
    else if(field->getName() == "possibleEffects")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_possibleEffects << *qSharedPointerCast<EffectInstanceData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "favoriteSubAreas")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_favoriteSubAreas << readUInt(data);
    }
    
    else if(field->getName() == "favoriteSubAreasBonus")
        m_favoriteSubAreasBonus = readUInt(field->getValue());
    
    else if(field->getName() == "craftXpRatio")
        m_craftXpRatio = readInt(field->getValue());
    
    else if(field->getName() == "needUseConfirm")
        m_needUseConfirm = readBool(field->getValue());
    
    else if(field->getName() == "isDestructible")
        m_isDestructible = readBool(field->getValue());
    
    else if(field->getName() == "nuggetsBySubarea")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<double> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readDouble(data);
        
        m_nuggetsBySubarea << secondList;
      }
    }
    
    else if(field->getName() == "containerIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_containerIds << readUInt(data);
    }
    
    else if(field->getName() == "resourcesBySubarea")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_resourcesBySubarea << secondList;
      }
    }
    
  }
}

