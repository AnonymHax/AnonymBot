#pragma once

#include "Public.h"
#include "System/Tools/IO/Reader.h"


class I18nFileAccessor
{
public:
    I18nFileAccessor(const QString &path);
    ~I18nFileAccessor();

    QString getText(int index);
    QString getText(const QString &index);

    bool indexExist(const QString &index);
    bool indexExist(int index);

private:
    QString m_path;
    Reader *m_reader;
    QMap<int, int> m_indexes;
    QMap<QString, int> m_textIndexes;
};
