#pragma once

#include "I18nFileAccessor.h"

class I18nFile
{
public:
    I18nFile(const QString &path);
    ~I18nFile();

    QString getText(int id);
    QString getText(const QString &id);

private:
    I18nFileAccessor *m_accessor;
};

