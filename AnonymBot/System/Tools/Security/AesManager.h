#ifndef AESMANAGER_H
#define AESMANAGER_H

#include <QDebug>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <openssl/aes.h>
#include <initializer_list>
#include <QCryptographicHash>

#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/Writer.h"

typedef unsigned char byte;

class AesManager
{
public:
    AesManager();

    static QByteArray generateRandomAESKey();
    QByteArray hashFunction(QByteArray r, QByteArray k);
    std::string AES_NormalizeKey(const void *const apBuffer, size_t aSize);
    std::string AESDecrypt(const void *const apBuffer, size_t aBufferSize, const void *const apKey, size_t aKeySize, std::vector<byte> &aIVector);
    std::string AESEncrypt(const void *const apBuffer, size_t aBufferSize, const void *const apKey, size_t aKeySize, std::vector<byte> &aIVector);

    template <size_t multiple> size_t round_up(const size_t len)
    {
        if (len % multiple == 0) return len;
        else return ((len / multiple) + 1) * multiple;
    }
};

#endif // AESMANAGER_H
