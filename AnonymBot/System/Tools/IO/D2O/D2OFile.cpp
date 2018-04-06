#include "D2OFile.h"

D2OFile::D2OFile(const QString &path, I18nFile *I18n, GameDataTypeEnum D2O):
    m_path(path),
    m_I18nFile(I18n),
    m_D2OFile(D2O)
{
    m_accessor = new D2OFileAccessor(m_path, m_I18nFile);
}

D2OFile::~D2OFile()
{
    delete m_accessor;
}

QSharedPointer<AbstractGameData> D2OFile::readIndex(int index)
{
    return m_accessor->read(index);
}

QList<int> D2OFile::getIndexes()
{
    return m_accessor->getIndexes();
}
