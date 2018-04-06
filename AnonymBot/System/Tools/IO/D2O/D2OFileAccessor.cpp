#include "D2OFileAccessor.h"


D2OFileAccessor::D2OFileAccessor(const QString &path, I18nFile *I18n):
    m_path(path),
    m_I18n(I18n)
{
    m_reader = new Reader(m_path);

    QString header = m_reader->readBytes(3).data();

    if (header != "D2O")
        qDebug()<<"ERREUR - D2OFileAccessor - Le fichier D2O est malformé"<<path;

    int indexPos = m_reader->readInt();
    m_reader->setPosition(indexPos);

    int indexCount = m_reader->readInt();
    for (int i = 1; i < indexCount; i += 8)
    {
        int index = m_reader->readInt();
        int pos = m_reader->readInt();
        m_indexes[index] = pos;
    }

    int classesCount = m_reader->readInt();
    for (int i = 0; i < classesCount; i++)
    {
        int classId = m_reader->readInt();
        m_classes[classId] = readClassDefinition();
    }

    foreach(ClassDefinition *classDef, m_classes)
        classDef->setField(m_classes, m_I18n);
}

D2OFileAccessor::~D2OFileAccessor()
{
    delete m_reader;

    foreach(ClassDefinition *def, m_classes.values())
        delete def;
}

ClassDefinition *D2OFileAccessor::readClassDefinition()
{
    QString className = m_reader->readUTF();
    QString classNamespace = m_reader->readUTF();
    ClassDefinition *m_class = new ClassDefinition(className);

    int fieldCount = m_reader->readInt();
    for (int i = 0; i < fieldCount; i++)
    {
        QString fieldName = m_reader->readUTF();
        m_class->addField(fieldName, m_reader);
    }

    return m_class;
}

QSharedPointer<AbstractGameData> D2OFileAccessor::read(int index)
{
    if (!m_indexes.contains(index))
        qDebug()<<"ERREUR - D2OFileAccessor n'a pas trouvé l'index :"<<index;

    m_reader->setPosition(m_indexes[index]);
    int classId = m_reader->readInt();
    return m_classes[classId]->read(m_reader, m_I18n);
}


QList<int> D2OFileAccessor::getIndexes()
{
    return m_indexes.keys();
}
