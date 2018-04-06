#pragma once

#include "D2PFile.h"

class D2PFolder
{
public:
    D2PFolder(const QString &folderName);
    ~D2PFolder();

    const QString &getFolderName() const;
    const uint &getD2PFileCount() const;
    const QList<D2PFile*> &getFolderContent() const;

private:
    QString m_folderName;
    QList<D2PFile*> m_folderContent;
    uint m_D2PFileCount;
};

