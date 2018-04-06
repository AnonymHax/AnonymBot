#include "AesManager.h"

AesManager::AesManager()
{
}

QByteArray AesManager::generateRandomAESKey()
{
    Writer w;
    for (int i = 0; i < 32; i++)
    {
        double r = ((double) rand() / (RAND_MAX));
        w.writeByte(floor(r * 256.0));
    }

    return w.getBuffer();
}

//Antibot hash function. Hash c and encrypt it in aes 128 with key k and prepend IV
QByteArray AesManager::hashFunction(QByteArray r, QByteArray k)
{
    QByteArray t;
    t = QCryptographicHash::hash(r.data(), QCryptographicHash::Md5);

    std::vector<byte> IV;
    std::string e(AESEncrypt(t.data(), t.size(), k.data(), k.size(), IV));

    t.clear();
    for (int i = 0; i < IV.size(); i++)
        t.append(IV.at(i));
    t.append(e.data());

    Writer w;
    w.writeBytes(r.data());
    w.writeBytes(t);
    w.writeByte(5);

    return w.getBuffer();
}

// Make a Key of exactly 16 bytes, truncates or adds values if it's necessary
std::string AesManager::AES_NormalizeKey(const void *const apBuffer, size_t aSize)
{
    static const unsigned char key32[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    const char *const Buffer = reinterpret_cast<const char *>(apBuffer);
    std::string Result(reinterpret_cast<const char *>(key32), 16);
    std::copy(Buffer, Buffer + ((aSize < 16)? aSize: 16), Result.begin());
    return Result;
}

// Encrypt using AES cbc
std::string AesManager::AESEncrypt(const void *const apBuffer, size_t aBufferSize, const void *const apKey, size_t aKeySize, std::vector<byte> &aIVector)
{
    // Create IVector.
    unsigned char AES_IVector[AES_BLOCK_SIZE] = {0};
    std::srand(static_cast<int>(time(NULL)));
    std::generate(std::begin(AES_IVector), std::end(AES_IVector), std::rand);
    aIVector.resize(sizeof(AES_IVector));
    std::copy(std::begin(AES_IVector), std::end(AES_IVector), aIVector.begin());

    // Create key.
    const std::string Key(AES_NormalizeKey(apKey, aKeySize));
    AES_KEY EncryptKey;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char *>(Key.data()), 128, &EncryptKey);

    // Encrypt.
    unsigned char AES_Encrypted[1024] = {0};
    AES_cbc_encrypt(static_cast<const unsigned char *>(apBuffer), AES_Encrypted, aBufferSize, &EncryptKey, AES_IVector, AES_ENCRYPT);
    const std::string Encrypted(reinterpret_cast<const char *>(AES_Encrypted), round_up<AES_BLOCK_SIZE>(aBufferSize));

    // Finish.
    return Encrypted;
}

// Decrypt using AES cbc
std::string AesManager::AESDecrypt(const void *const apBuffer, size_t aBufferSize, const void *const apKey, size_t aKeySize, std::vector<byte> &aIVector)
{
    // Read IVector.
    unsigned char AES_IVector[AES_BLOCK_SIZE] = {0};
    std::copy(aIVector.begin(), aIVector.end(), std::begin(AES_IVector));

    // Create Key.
    const std::string Key(reinterpret_cast<const char *>(apKey));
    AES_KEY DecryptKey;
    qDebug() << "test" << QByteArray(Key.data()).toHex();
    AES_set_decrypt_key(reinterpret_cast<const unsigned char *>(Key.data()), 256, &DecryptKey);

    // Decrypt.
    unsigned char AES_Decrypted[1024] = {0};
    AES_cbc_encrypt(static_cast<const unsigned char *>(apBuffer), AES_Decrypted, aBufferSize, &DecryptKey, AES_IVector, AES_DECRYPT);
    const std::string Decrypted(reinterpret_cast<const char *>(AES_Decrypted));

    // Finish.
    return Decrypted;
}
