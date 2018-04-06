#include "CraftModule.h"

CraftModule::CraftModule(QMap<SocketIO *, BotData> *connectionsData, MapModule *mapModule):
    AbstractModule(ModuleType::FARM, connectionsData),
    m_mapModule(mapModule)
{
    QObject::connect(m_mapModule, SIGNAL(hasFinishedMoving(SocketIO*)), this, SLOT(useCraftingBench(SocketIO*)));
    QObject::connect(m_mapModule, SIGNAL(couldNotMove(SocketIO*)), this, SLOT(couldNotMove(SocketIO*)));

    foreach(int index, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::RECIPES))
    {
        QSharedPointer<RecipeData> recipe = qSharedPointerCast<RecipeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::RECIPES, index));
        m_recipesName[recipe->getResultName()] = recipe->getResultId();

        RecipeInfos infos;
        infos.quantity = -1;
        infos.jobId = recipe->getJobId();
        infos.joblevel = recipe->getResultLevel();
        infos.name = recipe->getResultName();
        infos.skillId = recipe->getSkillId();
        infos.recipeId = recipe->getResultId();

        for (int i = 0; i < recipe->getIngredientIds().size(); i++)
            infos.ingredients[recipe->getIngredientIds()[i]] = recipe->getQuantities()[i];

        m_recipes[recipe->getResultId()] = infos;
    }
}

void CraftModule::reset(SocketIO *sender)
{
    m_botData[sender].craftData.recipeQuantities.clear();
    m_botData[sender].craftData.recipeStack.clear();
    m_botData[sender].craftData.isCrafting = false;
    m_botData[sender].craftData.step = 0;
}

bool CraftModule::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::EXCHANGEOBJECTMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectModifiedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
        }
    }
        break;

    case MessageEnum::EXCHANGEOBJECTSMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectsModifiedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
        }
    }
        break;

    case MessageEnum::EXCHANGEOBJECTADDEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectAddedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
            addCraftComponent(sender, message.object);

            if (compareRecipes(m_botData[sender].craftData.recipeStack, m_botData[sender].craftData.toCraft.ingredients) &&
                    m_botData[sender].craftData.countSet)
            {
                ExchangeReadyMessage message;
                message.step = m_botData[sender].craftData.step;
                message.ready = true;

                sender->send(message);
                processCrafting(sender);
            }
        }
    }
        break;

    case MessageEnum::EXCHANGEOBJECTSADDEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectsAddedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
            foreach (QSharedPointer<ObjectItem> o, message.object)
                addCraftComponent(sender, o);

            if (compareRecipes(m_botData[sender].craftData.recipeStack, m_botData[sender].craftData.toCraft.ingredients) &&
                    m_botData[sender].craftData.countSet)
            {
                ExchangeReadyMessage message;
                message.step = m_botData[sender].craftData.step;
                message.ready = true;

                sender->send(message);
                processCrafting(sender);
            }
        }
    }
        break;

    case MessageEnum::EXCHANGEOBJECTREMOVEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectRemovedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
        }
    }
        break;

    case MessageEnum::EXCHANGEOBJECTSREMOVEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            ExchangeObjectsRemovedMessage message;
            message.deserialize(&reader);

            m_botData[sender].craftData.step++;
        }
    }
        break;

    case MessageEnum::EXCHANGEKAMAMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
            m_botData[sender].craftData.step++;
    }
        break;

    case MessageEnum::EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
            m_botData[sender].craftData.step++;
    }
        break;

    case MessageEnum::INTERACTIVEUSEERRORMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
            m_botData[sender].craftData.recipeQuantities.clear();
            m_botData[sender].craftData.recipeStack.clear();
            m_botData[sender].craftData.isCrafting = false;
            m_botData[sender].craftData.step = 0;

            emit scriptActionDone(sender);
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.countSet = false;
            m_botData[sender].craftData.recipeStack.clear();

            foreach (int r, m_botData[sender].craftData.toCraft.ingredients.keys())
            {
                ExchangeObjectMoveMessage message;
                message.quantity = m_botData[sender].craftData.toCraft.ingredients[r];
                message.objectUID = r;

                sender->send(message);
            }

            ExchangeCraftCountRequestMessage message;
            message.count = m_botData[sender].craftData.recipeQuantities[m_botData[sender].craftData.toCraft.recipeId];
            sender->send(message);
        }
    }
        break;

    case MessageEnum::EXCHANGESTARTOKCRAFTMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.countSet = false;
            m_botData[sender].craftData.recipeStack.clear();

            foreach (int r, m_botData[sender].craftData.toCraft.ingredients.keys())
            {
                ExchangeObjectMoveMessage message;
                message.quantity = m_botData[sender].craftData.toCraft.ingredients[r];
                message.objectUID = r;

                sender->send(message);
            }

            ExchangeCraftCountRequestMessage message;
            message.count = m_botData[sender].craftData.recipeQuantities[m_botData[sender].craftData.toCraft.recipeId];
            sender->send(message);
        }
    }
        break;

    case MessageEnum::EXCHANGECRAFTCOUNTMODIFIEDMESSAGE:
    {
        if (m_botData[sender].generalData.botState == BotState::CRAFTING_STATE &&
                m_botData[sender].craftData.isCrafting)
        {
            m_botData[sender].craftData.countSet = true;
            if (compareRecipes(m_botData[sender].craftData.recipeStack, m_botData[sender].craftData.toCraft.ingredients))
            {
                ExchangeReadyMessage message;
                message.step = m_botData[sender].craftData.step;
                message.ready = true;

                sender->send(message);
                processCrafting(sender);
            }
        }
    }
        break;
    }
}

bool CraftModule::processCraft(SocketIO *sender)
{
    processCraftQuantities(sender);
    m_botData[sender].craftData.step = 0;

    if (m_botData[sender].craftData.recipeQuantities.isEmpty() ||
            m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
        return false;

    processCrafting(sender);
    return true;
}

void CraftModule::processCrafting(SocketIO *sender)
{
    processCraftQuantities(sender);

    if (m_botData[sender].craftData.craftList.isEmpty() ||
            m_botData[sender].generalData.botState != BotState::INACTIVE_STATE)
    {
        m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
        m_botData[sender].craftData.recipeQuantities.clear();
        m_botData[sender].craftData.recipeStack.clear();
        m_botData[sender].craftData.isCrafting = false;
        m_botData[sender].craftData.step = 0;

        emit scriptActionDone(sender);
        return;
    }

    foreach (RecipeInfos r, m_botData[sender].craftData.craftList)
    {
        if (m_botData[sender].craftData.recipeQuantities[r.recipeId])
        {
            foreach (InteractiveElementInfos ie, m_botData[sender].mapData.interactivesOnMap)
            {
                foreach (InteractiveSkillInfos is, ie.enabledSkills)
                {
                    if (is.ID == r.skillId)
                    {
                        m_botData[sender].craftData.isCrafting = true;
                        m_botData[sender].generalData.botState = BotState::CRAFTING_STATE;

                        MapPoint craftingBench = MapPoint::fromCellId(m_botData[sender].mapData.map.getInteractiveElementCellID(ie.elementId));
                        MapPoint bot = MapPoint::fromCellId(m_botData[sender].mapData.playersOnMap[m_botData[sender].mapData.botId].cellId);
                        QList<CellData> map = m_botData[sender].mapData.map.getCellData();
                        QList<uint> cells;

                        for (int i = 0; i < 8; i++)
                        {
                            MapPoint cell = craftingBench.getNearestCellInDirection(i);
                            if (cell.getCellId() <= map.size())
                                if (!CellInfo::pointMov(map, cell.getX(), cell.getY(), false))
                                    cells << cell.getCellId();
                        }

                        MapPoint mp = craftingBench.getNearestFreeCellInDirection(craftingBench.advancedOrientationTo(bot),
                                                                                  m_botData[sender].mapData.map.getCellData(),
                                                                                  cells,
                                                                                  true,
                                                                                  true,
                                                                                  false);

                        if (cells.indexOf(mp.getCellId()) == -1)
                            mp = craftingBench;

                        m_botData[sender].craftData.toCraft = r;
                        m_botData[sender].craftData.craftingBench = ie;
                        m_botData[sender].craftData.craftingBenchSkill = is;

                        if (mp.getCellId() == bot.getCellId())
                            useCraftingBench(sender);
                        else
                            m_botData[sender].farmData.moved = m_mapModule->changeCell(sender, mp.getCellId());

                        return;
                    }
                }
            }
        }
    }

    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].craftData.recipeQuantities.clear();
    m_botData[sender].craftData.recipeStack.clear();
    m_botData[sender].craftData.isCrafting = false;
    m_botData[sender].craftData.step = 0;

    emit scriptActionDone(sender);
    return;
}

void CraftModule::useCraftingBench(SocketIO *sender)
{
    // TODO: Hugo FIX
    if(m_botData[sender].scriptData.activeModule == getType())
    {
        InteractiveElementInfos ie = m_botData[sender].craftData.craftingBench;
        InteractiveSkillInfos is = m_botData[sender].craftData.craftingBenchSkill;

        InteractiveUseRequestMessage message;
        message.elemId = ie.elementId;
        message.skillInstanceUid = is.UID;

        sender->send(message);
    }
}

void CraftModule::couldNotMove(SocketIO *sender)
{
    m_botData[sender].generalData.botState = BotState::INACTIVE_STATE;
    m_botData[sender].craftData.recipeQuantities.clear();
    m_botData[sender].craftData.recipeStack.clear();
    m_botData[sender].craftData.isCrafting = false;
    m_botData[sender].craftData.step = 0;

    emit scriptActionDone(sender);
}

void CraftModule::processCraftQuantities(SocketIO *sender)
{
    m_botData[sender].craftData.recipeQuantities.clear();
    QList<RecipeInfos> updatedRecipes = m_botData[sender].craftData.craftList;
    QList<InventoryObject> inventoryContent = m_botData[sender].playerData.inventoryContent;

    foreach (RecipeInfos r, updatedRecipes)
    {
        int i = 0;
        while (canCraftItem(sender, inventoryContent, r))
        {
            removeFromInventory(inventoryContent, r);
            i++;
        }

        if (!i)
            continue;
        else if ((r.quantity == -1) || (i < r.quantity))
            m_botData[sender].craftData.recipeQuantities[r.recipeId] = i;
        else if (i > r.quantity)
            m_botData[sender].craftData.recipeQuantities[r.recipeId] = r.quantity;
    }
}

bool CraftModule::canCraftItem(SocketIO *sender, QList<InventoryObject> inventory, RecipeInfos recipe)
{
    if (m_botData[sender].craftData.jobs[recipe.jobId].jobLevel < recipe.joblevel)
        return false;

    QMap<uint, uint> objects;
    foreach (InventoryObject o, inventory)
        objects[o.GID] = o.quantity;

    bool ok = true;
    foreach (uint id, recipe.ingredients.keys())
        if (objects[id] < recipe.ingredients[id])
            ok = false;

    return false;
}

void CraftModule::removeFromInventory(QList<InventoryObject> &inventory, RecipeInfos recipe)
{
    foreach (uint id, recipe.ingredients.keys())
        for (QList<InventoryObject>::iterator i = inventory.begin(); i != inventory.end(); i++)
            if ((*i).GID == id)
                (*i).quantity -= recipe.ingredients[id];
}

void CraftModule::addCraftComponent(SocketIO *sender, QSharedPointer<ObjectItem> o)
{
    m_botData[sender].craftData.recipeStack[o->objectGID] = o->quantity;
}

bool CraftModule::compareRecipes(QMap<uint, uint> left, QMap<uint, uint> right)
{
    foreach (int i, left.keys())
        if (left[i] != right[i])
            return false;

    foreach (int i, right.keys())
        if (right[i] != left[i])
            return false;

    return true;
}

QList<uint> CraftModule::getCraftList(SocketIO *sender) const
{
    QList<uint> craftId;
    foreach (RecipeInfos infos, m_botData[sender].craftData.craftList)
        craftId << infos.recipeId;

    return craftId;
}

QMap<QString, uint> CraftModule::getRecipesName() const
{
    return m_recipesName;
}

void CraftModule::addItemToCraftList(SocketIO *sender, QString craft)
{
    m_botData[sender].craftData.craftList << m_recipes[m_recipesName[craft]];
    processCraftQuantities(sender);
}

void CraftModule::updateQuantity(SocketIO *sender, uint index, int quantity)
{
    m_botData[sender].craftData.craftList[index].quantity = quantity;
    processCraftQuantities(sender);
}

void CraftModule::removeItemOfCraftList(SocketIO *sender, uint index)
{
    m_botData[sender].craftData.craftList.removeAt(index);
    processCraftQuantities(sender);
}
