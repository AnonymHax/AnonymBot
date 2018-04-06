#include "I18nFile.h"


I18nFile::I18nFile(const QString &path)
{
    m_accessor = new I18nFileAccessor(path);
}

I18nFile::~I18nFile()
{
    delete m_accessor;
}

QString I18nFile::getText(int id)
{
    if (!m_accessor->indexExist(id))
        qDebug()<<"ERREUR - I18nFile - L'index"<<id<<"n'a pas été trouvé";

    return m_accessor->getText(id);
}

QString I18nFile::getText(const QString &id)
{
    if (!m_accessor->indexExist(id))
        qDebug()<<"ERREUR - I18nFile - L'index"<<id<<"n'a pas été trouvé";

    return m_accessor->getText(id);
}

