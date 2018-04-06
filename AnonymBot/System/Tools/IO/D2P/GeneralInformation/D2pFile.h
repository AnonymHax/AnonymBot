#pragma once

#include "System/Tools/IO/Reader.h"
#include "CompressedMap.h"


class D2PFile
{
private:


public:
    D2PFile(const QString &path);
    ~D2PFile();

    const QString &getPath() const;
    const QMap<uint, CompressedMap*> &getContent() const;

private:
    void initializeInstanceFields();
    void getFileContent();

    QString m_path;
    QMap<uint, CompressedMap*> m_content;
};
