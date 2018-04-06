#ifndef CUSTOMTYPES
#define CUSTOMTYPES

#include "Public.h"
#include "System/Engines/DataHandler.h"
#include "System/Engines/ProcessEngine.h"
#include "System/Tools/IO/Trie.h"

enum class TableRoles {
    ROLE_1=Qt::UserRole,
    ROLE_2,
    ROLE_3,
    ROLE_4,
    ROLE_5,
    ROLE_6,
    ROLE_7,
    ROLE_8,
    ROLE_9,
    ROLE_10
};

class InteractiveModel : public QAbstractTableModel
{
    Q_OBJECT

public:    
    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;
    
    void update(const QList<InteractiveDisplayInfos> &data);

private:
    QList<InteractiveDisplayInfos> m_data;
};


class InventoryModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    InventoryModel(SocketIO *sender, ProcessEngine *engine);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void update();

    Q_INVOKABLE uint getQuantity(int index);

private:
    SocketIO *m_sender;
    ProcessEngine *m_engine;
    int m_level;
    QList<InventoryObject> m_inventoryContent;
    QList<QString> m_typeNames;
    QList<uint> m_actions;
};


class BasicStatsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    BasicStatsModel(SocketIO *sender, ProcessEngine *engine);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void update();

private:
    bool m_init;
    SocketIO *m_sender;
    ProcessEngine *m_engine;
    QList<QString> m_names;
    QList<int> m_bases;
    QList<int> m_totals;
    QList<int> m_actions;
};

class PrimaryStatsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    PrimaryStatsModel(SocketIO *sender, ProcessEngine *engine);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void update();

private:
    bool m_init;
    SocketIO *m_sender;
    ProcessEngine *m_engine;
    QList<QString> m_names;
    QList<int> m_values;
};

class SpellsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    SpellsModel(SocketIO *sender, ProcessEngine *engine);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void update();

private:
    SocketIO *m_sender;
    ProcessEngine *m_engine;
    QList<QString> m_names;
    QList<int> m_levels;
    QList<int> m_actions;
};

class JobsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    JobsModel(SocketIO *sender, ProcessEngine *engine);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void update();

private:
    SocketIO *m_sender;
    ProcessEngine *m_engine;
    QList<QString> m_names;
    QList<int> m_levels;
    QList<QStringList> m_experiences;
};

class CompleterModel : public QAbstractListModel
{
    Q_OBJECT

public:
    CompleterModel(Trie *completer);
    ~CompleterModel();

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;
    Q_INVOKABLE QString data(int i) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    Q_INVOKABLE void update(const QString& s);

private slots:
    void handleResults(const QStringList& l);

signals:
    void autoCompleteRequest(QString s);

protected:
    Trie *m_completer;

private:
    QStringList m_suggestions;
    QThread *m_thread;
};

class SpellsCompleterModel : public CompleterModel
{
    Q_OBJECT

public:
    SpellsCompleterModel(SocketIO *sender, ProcessEngine *engine, Trie *trie);
    ~SpellsCompleterModel();

    void update();

private:
    SocketIO *m_sender;
    ProcessEngine *m_engine;
};

class FightSpellsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    FightSpellsModel(SocketIO *sender, ProcessEngine *engine);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void update();

    void addSpell(RequestedSpell r);
    Q_INVOKABLE void moveSpellUp(int index);
    Q_INVOKABLE void moveSpellDown(int index);
    Q_INVOKABLE void removeSpell(int index);
    Q_INVOKABLE void setSpellCible(int index, int cible);
    Q_INVOKABLE void setSpellCastNb(int index, int castNb);
    Q_INVOKABLE void setSpellAI(int index, bool checked);

private:
    SocketIO *m_sender;
    ProcessEngine *m_engine;

    QList<bool> m_intelligentSpells;
    QList<QString> m_names;
    QList<int> m_costs;
    QList<QString> m_ranges;
    QList<int> m_castNbs;
    QList<int> m_cibles;
};

class FightMonstersModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    FightMonstersModel(SocketIO *sender, ProcessEngine *engine);

    int rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;

    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::UserRole + 1) const;

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

    void update();

    void addMonster(int id);

    Q_INVOKABLE void removeMonster(int index);
    Q_INVOKABLE void setMonsterLevelMin(int index, int levelMin);
    Q_INVOKABLE void setMonsterLevelMax(int index, int levelMax);

private:
    SocketIO *m_sender;
    ProcessEngine *m_engine;

    QList<QString> m_names;
    QList<int> m_levelMins;
    QList<int> m_levelMaxs;
};

#endif // CUSTOMTYPES

