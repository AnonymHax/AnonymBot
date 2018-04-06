#include "CustomTypes.h"

int InteractiveModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_data.size();
}

int InteractiveModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

QVariant InteractiveModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_data[index.row()].name;
    case TableRoles::ROLE_2:
        return  m_data[index.row()].id;
    case TableRoles::ROLE_3:
        return  m_data[index.row()].cellId;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> InteractiveModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)TableRoles::ROLE_1] = "name";
    roles[(int)TableRoles::ROLE_2] = "uid";
    roles[(int)TableRoles::ROLE_3] = "cellId";

    return roles;
}

void InteractiveModel::update(const QList<InteractiveDisplayInfos> &data)
{
    beginResetModel();
    m_data = data;
    endResetModel();
}

InventoryModel::InventoryModel(SocketIO *sender, ProcessEngine *engine):
    m_engine(engine),
    m_sender(sender),
    m_level(-1)
{}

int InventoryModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_inventoryContent.size();
}

int InventoryModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 3;
}

QVariant InventoryModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return D2OManagerSingleton::get()->getItem(m_inventoryContent[index.row()].GID)->getName();
    case TableRoles::ROLE_2:
        return  m_inventoryContent[index.row()].quantity;
    case TableRoles::ROLE_3:
        return  m_inventoryContent[index.row()].GID;
    case TableRoles::ROLE_4:
        return m_typeNames[index.row()];
    case TableRoles::ROLE_5:
        return m_actions[index.row()];
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> InventoryModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)TableRoles::ROLE_1] = "name";
    roles[(int)TableRoles::ROLE_2] = "quantity";
    roles[(int)TableRoles::ROLE_3] = "id";
    roles[(int)TableRoles::ROLE_4] = "typeName";
    roles[(int)TableRoles::ROLE_5] = "actions";

    return roles;
}

void InventoryModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);
    uint level = 0;

    if(infos.mapData.gameContext == GameContextEnum::ROLE_PLAY)
        level = infos.mapData.playersOnMap[infos.mapData.botId].level;

    else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
        level = infos.fightData.fighters[infos.fightData.botFightData.botId].level;

    bool newObjects = m_inventoryContent.size() != infos.playerData.inventoryContent.size();

    if(newObjects)
        beginRemoveRows(QModelIndex(), 0, m_typeNames.size()-1);

    m_inventoryContent.clear();
    m_typeNames.clear();
    m_actions.clear();

    if(newObjects)
    {
        endRemoveRows();
        beginInsertRows(QModelIndex(), 0, infos.playerData.inventoryContent.size()-1);
    }

    m_inventoryContent = infos.playerData.inventoryContent;

    foreach(InventoryObject i, m_inventoryContent)
    {
        QSharedPointer<ItemData> c = D2OManagerSingleton::get()->getItem(i.GID);
        QSharedPointer<ItemTypeData> l = qSharedPointerCast<ItemTypeData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::ITEMTYPES, c->getTypeId()));
        m_typeNames<<l->getName();

        int d = 0;

        if(c->getUsable() && (c->getLevel() <= level))
            d |= 0x1;

        if(c->getIsDestructible())
            d |= 0x2;


        if(c->getLevel() <= level)
        {
            if(m_engine->getStatsModule().canEquipItem(i.GID))
                d |= 0x4;
        }

        if(i.isEquipped)
            d |= 0x8;

        m_actions<<d;
    }

    if(newObjects)
        endInsertRows();

    else
        emit dataChanged(index(0, 0), index(m_inventoryContent.size()-1, 0));
}

uint InventoryModel::getQuantity(int index)
{
    return m_inventoryContent[index].quantity;
}


BasicStatsModel::BasicStatsModel(SocketIO *sender, ProcessEngine *engine):
    m_engine(engine),
    m_sender(sender)
{
    beginInsertColumns(QModelIndex(), 0, 0);

    QList<int> l = {11, 12, 10, 15, 13, 14};
    QSharedPointer<CharacteristicData> a;
    foreach(const int &i, l)
    {
        a = qSharedPointerCast<CharacteristicData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::CHARACTERISTICS, i));
        m_names<<a->getName();
    }

    endInsertColumns();
}

int BasicStatsModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_names.size();
}

int BasicStatsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    if(m_bases.size() > 0)
        return 4;

    return 1;
}

QVariant BasicStatsModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_names[index.row()];
    case TableRoles::ROLE_2:
        return  m_bases[index.row()];
    case TableRoles::ROLE_3:
        return  m_totals[index.row()];
    case TableRoles::ROLE_4:
        return  m_actions[index.row()];
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> BasicStatsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)TableRoles::ROLE_1] = "name";
    roles[(int)TableRoles::ROLE_2] = "base";
    roles[(int)TableRoles::ROLE_3] = "total";
    roles[(int)TableRoles::ROLE_4] = "action";

    return roles;
}

void BasicStatsModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);

    m_bases.clear();
    m_totals.clear();
    m_actions.clear();

    int b = infos.playerData.stats.vitality.base;
    int r = infos.playerData.stats.vitality.alignGiftBonus + infos.playerData.stats.vitality.contextModif +
            infos.playerData.stats.vitality.objectsAndMountBonus + infos.playerData.stats.vitality.additionnal;

    m_bases<<b;
    m_totals<<b+r;

    b = infos.playerData.stats.wisdom.base;
    r = infos.playerData.stats.wisdom.alignGiftBonus + infos.playerData.stats.wisdom.contextModif +
            infos.playerData.stats.wisdom.objectsAndMountBonus + infos.playerData.stats.wisdom.additionnal; ;

    m_bases<<b;
    m_totals<<b+r;

    b = infos.playerData.stats.strength.base;
    r = infos.playerData.stats.strength.alignGiftBonus + infos.playerData.stats.strength.contextModif +
            infos.playerData.stats.strength.objectsAndMountBonus + infos.playerData.stats.strength.additionnal; ;

    m_bases<<b;
    m_totals<<b+r;

    b = infos.playerData.stats.intelligence.base;
    r = infos.playerData.stats.intelligence.alignGiftBonus + infos.playerData.stats.intelligence.contextModif +
            infos.playerData.stats.intelligence.objectsAndMountBonus + infos.playerData.stats.intelligence.additionnal;

    m_bases<<b;
    m_totals<<b+r;

    b = infos.playerData.stats.chance.base;
    r = infos.playerData.stats.chance.alignGiftBonus + infos.playerData.stats.chance.contextModif +
            infos.playerData.stats.chance.objectsAndMountBonus + infos.playerData.stats.chance.additionnal;

    m_bases<<b;
    m_totals<<b+r;

    b = infos.playerData.stats.agility.base;
    r = infos.playerData.stats.agility.alignGiftBonus + infos.playerData.stats.agility.contextModif +
            infos.playerData.stats.agility.objectsAndMountBonus + infos.playerData.stats.agility.additionnal;

    m_bases<<b;
    m_totals<<b+r;


    if(infos.playerData.stats.statsRequiredVitality <= infos.playerData.stats.statsPoints)
        m_actions<<infos.playerData.stats.statsRequiredVitality;

    else
        m_actions<<0;

    if(infos.playerData.stats.statsRequiredWisdom <= infos.playerData.stats.statsPoints)
        m_actions<<infos.playerData.stats.statsRequiredWisdom;

    else
        m_actions<<0;

    if(infos.playerData.stats.statsRequiredStrength <= infos.playerData.stats.statsPoints)
        m_actions<<infos.playerData.stats.statsRequiredStrength;

    else
        m_actions<<0;

    if(infos.playerData.stats.statsRequiredAgility <= infos.playerData.stats.statsPoints)
        m_actions<<infos.playerData.stats.statsRequiredAgility;

    else
        m_actions<<0;

    if(infos.playerData.stats.statsRequiredChance <= infos.playerData.stats.statsPoints)
        m_actions<<infos.playerData.stats.statsRequiredChance;

    else
        m_actions<<0;

    if(infos.playerData.stats.statsRequiredAgility <= infos.playerData.stats.statsPoints)
        m_actions<<infos.playerData.stats.statsRequiredAgility;

    else
        m_actions<<0;

    emit dataChanged(index(0,0), index(m_totals.size()-1,0));
}


PrimaryStatsModel::PrimaryStatsModel(SocketIO *sender, ProcessEngine *engine):
    m_engine(engine),
    m_sender(sender)
{
    beginInsertRows(QModelIndex(), 0, 5);

    QList<int> l = {44, 48, 19, 26};
    m_names<<"PA"<<"PM";

    QSharedPointer<CharacteristicData> a;
    foreach(const int &i, l)
    {
        a = qSharedPointerCast<CharacteristicData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::CHARACTERISTICS, i));
        m_names<<a->getName();
    }

    endInsertRows();
}

int PrimaryStatsModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_names.size();
}

int PrimaryStatsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    if(m_values.size() > 0)
        return 2;

    return 1;
}

QVariant PrimaryStatsModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_names[index.row()];
    case TableRoles::ROLE_2:
        return m_values[index.row()];
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> PrimaryStatsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)TableRoles::ROLE_1] = "name";
    roles[(int)TableRoles::ROLE_2] = "value";

    return roles;
}

void PrimaryStatsModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);

    m_values.clear();

    int t = infos.playerData.stats.actionPoints.base + infos.playerData.stats.actionPoints.alignGiftBonus
            + infos.playerData.stats.actionPoints.contextModif +
            infos.playerData.stats.actionPoints.objectsAndMountBonus + infos.playerData.stats.actionPoints.additionnal;

    m_values<<t;

    t = infos.playerData.stats.movementPoints.base + infos.playerData.stats.movementPoints.alignGiftBonus
            + infos.playerData.stats.movementPoints.contextModif +
            infos.playerData.stats.movementPoints.objectsAndMountBonus + infos.playerData.stats.movementPoints.additionnal;

    m_values<<t;

    t = infos.playerData.stats.initiative.base + infos.playerData.stats.initiative.alignGiftBonus
            + infos.playerData.stats.initiative.contextModif +
            infos.playerData.stats.initiative.objectsAndMountBonus + infos.playerData.stats.initiative.additionnal;

    m_values<<t;

    t = infos.playerData.stats.range.base + infos.playerData.stats.range.alignGiftBonus
            + infos.playerData.stats.range.contextModif +
            infos.playerData.stats.range.objectsAndMountBonus + infos.playerData.stats.range.additionnal;

    m_values<<t;

    t = infos.playerData.stats.prospecting.base + infos.playerData.stats.prospecting.alignGiftBonus
            + infos.playerData.stats.prospecting.contextModif +
            infos.playerData.stats.prospecting.objectsAndMountBonus + infos.playerData.stats.prospecting.additionnal;

    m_values<<t;

    t = infos.playerData.stats.summonableCreaturesBoost.base + infos.playerData.stats.summonableCreaturesBoost.alignGiftBonus
            + infos.playerData.stats.summonableCreaturesBoost.contextModif +
            infos.playerData.stats.summonableCreaturesBoost.objectsAndMountBonus + infos.playerData.stats.summonableCreaturesBoost.additionnal;

    m_values<<t;

    emit dataChanged(index(0,0), index(m_values.size()-1, 0));
}

SpellsModel::SpellsModel(SocketIO *sender, ProcessEngine *engine):
    m_engine(engine),
    m_sender(sender)
{}

int SpellsModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_names.size();
}

int SpellsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 3;
}

QVariant SpellsModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_names[index.row()];
    case TableRoles::ROLE_2:
        return  m_levels[index.row()];
    case TableRoles::ROLE_3:
        return  m_actions[index.row()];
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> SpellsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)TableRoles::ROLE_1] = "name";
    roles[(int)TableRoles::ROLE_2] = "level";
    roles[(int)TableRoles::ROLE_3] = "action";

    return roles;
}

void SpellsModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);

    uint level = 0;

    if(infos.mapData.gameContext == GameContextEnum::ROLE_PLAY)
        level = infos.mapData.playersOnMap[infos.mapData.botId].level;

    else if(infos.mapData.gameContext == GameContextEnum::FIGHT)
        level = infos.fightData.fighters[infos.fightData.botFightData.botId].level;

    bool newSpells = m_names.size() != infos.playerData.spells.size();

    if(newSpells)
        beginResetModel();

    m_names.clear();
    m_levels.clear();
    m_actions.clear();

    QSharedPointer<SpellData> spellData;
    foreach(const Spell &spell, infos.playerData.spells)
    {
        spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, spell.spellID));
        m_names<<spellData->getName();
        m_levels<<spell.spellLevel;

        int a = 0;

        if(spell.spellLevel <= infos.playerData.stats.spellsPoints &&
                (spell.spellLevel != 5 || level >= 100) && spellData->getSpellLevels().size() > spell.spellLevel &&
                spell.spellID != 0)
        {
            a = spell.spellLevel;
        }

        m_actions<<a;
    }

    if(newSpells)
        endResetModel();

    else
        emit dataChanged(index(0, 0), index(m_names.size()-1, 0));
}

JobsModel::JobsModel(SocketIO *sender, ProcessEngine *engine):
    m_engine(engine),
    m_sender(sender)
{}

int JobsModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_names.size();
}

int JobsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 2;
}

QVariant JobsModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_names[index.row()];
    case TableRoles::ROLE_2:
        return  m_levels[index.row()];
    case TableRoles::ROLE_3:
        return m_experiences[index.row()];
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> JobsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)TableRoles::ROLE_1] = "name";
    roles[(int)TableRoles::ROLE_2] = "level";
    roles[(int)TableRoles::ROLE_3] = "experience";

    return roles;
}

void JobsModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);

    beginResetModel();
    m_names.clear();
    m_levels.clear();
    m_experiences.clear();

    QSharedPointer<JobData> jobData;
    foreach(const JobExperience &e, infos.craftData.jobs)
    {
        jobData = qSharedPointerCast<JobData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::JOBS, e.jobId));
        m_names<<jobData->getName();
        m_levels<<e.jobLevel;
        QStringList exp;
        exp <<  QString::number(qRound(100*((double)(e.jobXP-e.jobXpLevelFloor)/(double)(e.jobXpNextLevelFloor-e.jobXpLevelFloor))));
        exp << QString::number(e.jobXP);
        exp << QString::number(e.jobXpNextLevelFloor);
        m_experiences << exp;
    }

    endResetModel();
}

CompleterModel::CompleterModel(Trie *completer):
    m_completer(completer)
{
    m_thread = new QThread();
    m_completer->moveToThread(m_thread);

    connect(this, SIGNAL(autoCompleteRequest(QString)), m_completer, SLOT(autoComplete(QString)));
    connect(m_completer, SIGNAL(autoCompleteResults(QStringList)), this, SLOT(handleResults(QStringList)));
    connect(m_thread, SIGNAL(finished()), m_thread, SLOT(deleteLater()));

    m_thread->start();
}

CompleterModel::~CompleterModel()
{
}

int CompleterModel::rowCount(const QModelIndex & parent) const
{
    return m_suggestions.size();
}

QVariant CompleterModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_suggestions[index.row()];
    default:
        return QVariant();
    }
}

QString CompleterModel::data(int i) const
{
    if(m_suggestions.size()-1 >= i && i >= 0)
        return m_suggestions[i];

    else
        return QString();
}

QHash<int, QByteArray> CompleterModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[(int)TableRoles::ROLE_1] = "suggestion";

    return roles;
}

void CompleterModel::update(const QString &s)
{
    emit autoCompleteRequest(s);
}

void CompleterModel::handleResults(const QStringList &l)
{
    if(l != m_suggestions)
    {
        beginResetModel();
        m_suggestions = l;
        endResetModel();
    }
}

SpellsCompleterModel::SpellsCompleterModel(SocketIO *sender, ProcessEngine *engine, Trie *trie):
    m_sender(sender),
    m_engine(engine),
    CompleterModel(trie)
{

}

SpellsCompleterModel::~SpellsCompleterModel()
{
}

void SpellsCompleterModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);

    m_completer->clear();
    QSharedPointer<SpellData> spellData;

    foreach(Spell s, infos.playerData.spells)
    {
        spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, s.spellID));
        m_completer->addWord(spellData->getName(), s.spellID);
    }
}

FightSpellsModel::FightSpellsModel(SocketIO *sender, ProcessEngine *engine):
    m_engine(engine),
    m_sender(sender)
{}

int FightSpellsModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_names.size();
}

int FightSpellsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 5;
}

QVariant FightSpellsModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_intelligentSpells[index.row()];
    case TableRoles::ROLE_2:
        return  m_names[index.row()];
    case TableRoles::ROLE_3:
        return  m_costs[index.row()];
    case TableRoles::ROLE_4:
        return  m_ranges[index.row()];
    case TableRoles::ROLE_5:
        return m_castNbs[index.row()];
    case TableRoles::ROLE_6:
        return m_cibles[index.row()];
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> FightSpellsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[(int)TableRoles::ROLE_1] = "intelligentSpell";
    roles[(int)TableRoles::ROLE_2] = "name";
    roles[(int)TableRoles::ROLE_3] = "cost";
    roles[(int)TableRoles::ROLE_4] = "range";
    roles[(int)TableRoles::ROLE_5] = "castNb";
    roles[(int)TableRoles::ROLE_6] = "cible";

    return roles;
}

void FightSpellsModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);

    beginResetModel();

    m_intelligentSpells.clear();
    m_names.clear();
    m_costs.clear();
    m_ranges.clear();
    m_castNbs.clear();
    m_cibles.clear();

    QList<RequestedSpell> requestedSpells = m_engine->getFightModule().getRequestedSpells(m_sender);

    int level;
    QSharedPointer<SpellData> spellData;
    QSharedPointer<SpellLevelData> spellLevelData;

    foreach(const RequestedSpell &r, requestedSpells)
    {
        level = m_engine->getData(m_sender).playerData.spells[r.spellID].spellLevel;

        spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, r.spellID));
        spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellData->getSpellLevels()[level-1]));

        m_intelligentSpells << r.useAI;
        m_names << spellData->getName();
        m_costs << spellLevelData->getApCost();
        m_ranges << QString::number(spellLevelData->getMinRange())+" - "+QString::number(spellLevelData->getRange());
        m_castNbs << r.castNb;
        m_cibles << (int)r.spellCible;
    }

    endResetModel();
}

void FightSpellsModel::addSpell(RequestedSpell r)
{
    beginInsertRows(QModelIndex(), m_intelligentSpells.size(), m_intelligentSpells.size());

    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);
    rs<<r;

    int level = m_engine->getData(m_sender).playerData.spells[r.spellID].spellLevel;

    QSharedPointer<SpellData> spellData = qSharedPointerCast<SpellData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLS, r.spellID));
    QSharedPointer<SpellLevelData> spellLevelData = qSharedPointerCast<SpellLevelData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SPELLLEVELS, spellData->getSpellLevels()[level-1]));

    m_intelligentSpells << r.useAI;
    m_names << spellData->getName();
    m_costs << spellLevelData->getApCost();
    m_ranges << QString::number(spellLevelData->getMinRange())+" - "+QString::number(spellLevelData->getRange());
    m_castNbs << r.castNb;
    m_cibles << (int)r.spellCible;

    m_engine->getFightModule().setRequestedSpells(m_sender, rs);

    endInsertRows();
}

void FightSpellsModel::moveSpellUp(int index)
{
    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);

    if(index != 0)
    {
        beginMoveRows(QModelIndex(), index, index, QModelIndex(), index-1);

        rs.move(index, index-1);

        m_intelligentSpells.move(index, index-1);
        m_names.move(index, index-1);
        m_costs.move(index, index-1);
        m_ranges.move(index, index-1);
        m_castNbs.move(index, index-1);
        m_cibles.move(index, index-1);

        m_engine->getFightModule().setRequestedSpells(m_sender, rs);

        endMoveRows();
    }
}

void FightSpellsModel::moveSpellDown(int index)
{
    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);

    if(index != rs.size()-1)
    {
        beginMoveRows(QModelIndex(), index, index, QModelIndex(), index+2);

        rs.move(index, index+1);

        m_intelligentSpells.move(index, index+1);
        m_names.move(index, index+1);
        m_costs.move(index, index+1);
        m_ranges.move(index, index+1);
        m_castNbs.move(index, index+1);
        m_cibles.move(index, index+1);

        m_engine->getFightModule().setRequestedSpells(m_sender, rs);

        endMoveRows();
    }
}

void FightSpellsModel::removeSpell(int index)
{
    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);

    beginRemoveRows(QModelIndex(), index, index);

    rs.removeAt(index);

    m_intelligentSpells.removeAt(index);
    m_names.removeAt(index);
    m_costs.removeAt(index);
    m_ranges.removeAt(index);
    m_castNbs.removeAt(index);
    m_cibles.removeAt(index);

    m_engine->getFightModule().setRequestedSpells(m_sender, rs);

    endRemoveRows();
}

void FightSpellsModel::setSpellCible(int index, int cible)
{
    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);

    rs[index].spellCible = (SpellCible)cible;

    m_engine->getFightModule().setRequestedSpells(m_sender, rs);
}

void FightSpellsModel::setSpellCastNb(int index, int castNb)
{
    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);

    rs[index].castNb = castNb;

    m_engine->getFightModule().setRequestedSpells(m_sender, rs);
}

void FightSpellsModel::setSpellAI(int index, bool checked)
{
    QList<RequestedSpell> rs = m_engine->getFightModule().getRequestedSpells(m_sender);

    rs[index].useAI = checked;

    m_engine->getFightModule().setRequestedSpells(m_sender, rs);
}

FightMonstersModel::FightMonstersModel(SocketIO *sender, ProcessEngine *engine):
    m_engine(engine),
    m_sender(sender)
{}

int FightMonstersModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_names.size();
}

int FightMonstersModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 4;
}

QVariant FightMonstersModel::data(const QModelIndex &index, int role) const
{
    // Check boundaries
    if(index.column() < 0 ||
            columnCount() <= index.column() ||
            index.row() < 0 ||
            rowCount() <= index.row())
    {
        qDebug() << "Warning: " << index.row() << ", " << index.column();
        return QVariant();
    }

    // Nominal case
    switch((TableRoles)role)
    {
    case TableRoles::ROLE_1:
        return m_names[index.row()];
    case TableRoles::ROLE_2:
        return m_levelMins[index.row()];
    case TableRoles::ROLE_3:
        return m_levelMaxs[index.row()];
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> FightMonstersModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[(int)TableRoles::ROLE_1] = "name";
    roles[(int)TableRoles::ROLE_2] = "levelMin";
    roles[(int)TableRoles::ROLE_3] = "levelMax";

    return roles;
}

void FightMonstersModel::update()
{
    const BotData &infos = m_engine->getData(m_sender);

    beginResetModel();

    m_names.clear();
    m_levelMins.clear();
    m_levelMaxs.clear();

    QList<MonsterCondition> requestedMonsters = m_engine->getData(m_sender).fightData.requestedMonsters.monsterConditions;

    QSharedPointer<MonsterData> monsterData;

    foreach(const MonsterCondition &r, requestedMonsters)
    {
        monsterData = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, r.id));
        m_names << monsterData->getName();
        m_levelMins<<r.levelMin;
        m_levelMaxs<<r.levelMax;
    }

    endResetModel();
}

void FightMonstersModel::addMonster(int id)
{
    beginInsertRows(QModelIndex(), m_names.size(), m_names.size());

    RequestedMonsters rs = m_engine->getData(m_sender).fightData.requestedMonsters;
    MonsterCondition r;
    r.id = id;
    rs.monsterConditions<<r;
    m_engine->getFightModule().setRequestedMonsters(m_sender, rs);

    QSharedPointer<MonsterData> monsterData = qSharedPointerCast<MonsterData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::MONSTERS, r.id));
    m_names << monsterData->getName();
    m_levelMins<<0;
    m_levelMaxs<<0;

    endInsertRows();
}

void FightMonstersModel::removeMonster(int index)
{
    beginRemoveRows(QModelIndex(), index, index);

    RequestedMonsters rs = m_engine->getData(m_sender).fightData.requestedMonsters;
    rs.monsterConditions.removeAt(index);
    m_engine->getFightModule().setRequestedMonsters(m_sender, rs);

    m_names.removeAt(index);
    m_levelMins.removeAt(index);
    m_levelMaxs.removeAt(index);

    endRemoveRows();
}

void FightMonstersModel::setMonsterLevelMin(int index, int levelMin)
{
    RequestedMonsters rs = m_engine->getData(m_sender).fightData.requestedMonsters;
    rs.monsterConditions[index].levelMin = levelMin;
    m_engine->getFightModule().setRequestedMonsters(m_sender, rs);
}

void FightMonstersModel::setMonsterLevelMax(int index, int levelMax)
{
    RequestedMonsters rs = m_engine->getData(m_sender).fightData.requestedMonsters;
    rs.monsterConditions[index].levelMax = levelMax;
    m_engine->getFightModule().setRequestedMonsters(m_sender, rs);
}


