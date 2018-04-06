#pragma once

#include "System/Tools/IO/Reader.h"
#include "ClassDefinition.h"
#include "System/Tools/IO/I18n/I18nFile.h"
#include "System/Tools/IO/D2O/AbstractGameData.h"


class D2OFileAccessor
{
public:
    D2OFileAccessor(const QString &path, I18nFile *I18n);
    ~D2OFileAccessor();

    QList<int> getIndexes();

    QSharedPointer<AbstractGameData> read(int index);

private:
    ClassDefinition *readClassDefinition();

    QString m_path;
    Reader *m_reader;
    QMap<int, int> m_indexes;
    QMap<int, ClassDefinition*> m_classes;
    I18nFile *m_I18n;
};
