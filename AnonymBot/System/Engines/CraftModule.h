#ifndef CRAFTMODULE_H
#define CRAFTMODULE_H

#include "Public.h"
#include "MapModule.h"
#include "AbstractModule.h"

class CraftModule : public AbstractModule
{
    Q_OBJECT

public:
    CraftModule(QMap<SocketIO*, BotData> *connectionsData, MapModule *mapModule);

    virtual void reset(SocketIO *sender);
    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    bool processCraft(SocketIO *sender);
    void processCrafting(SocketIO *sender);
    void processCraftQuantities(SocketIO *sender);

    QMap<QString, uint> getRecipesName() const;
    QList<uint> getCraftList(SocketIO *sender) const;
    void addItemToCraftList(SocketIO *sender, QString craft);
    void removeItemOfCraftList(SocketIO *sender, uint index);
    void updateQuantity(SocketIO *sender, uint index, int quantity);

private slots:
    void couldNotMove(SocketIO *sender);
    void useCraftingBench(SocketIO *sender);

private:
    void addCraftComponent(SocketIO *sender, QSharedPointer<ObjectItem> o);
    bool compareRecipes(QMap<uint, uint> left, QMap<uint, uint> right);
    void removeFromInventory(QList<InventoryObject> &inventory, RecipeInfos recipe);
    bool canCraftItem(SocketIO *sender, QList<InventoryObject> inventory, RecipeInfos recipe);

    MapModule *m_mapModule;
    QMap<QString, uint> m_recipesName;
    QMap<uint, RecipeInfos> m_recipes;
};

#endif // CRAFTMODULE_H
