#ifndef RSAMANAGER_H
#define RSAMANAGER_H

#include "Public.h"
#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/Writer.h"

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include "ostream"
#include "sstream"

class RsaManager
{
public:
    RsaManager();
    QByteArray publicKeyDecrypt(const QByteArray &signature);
    QByteArray loginPublicKeyEncrypt(const QByteArray &credentials);
    QList<int> generateCredentials(const QString &salt, QByteArray aesKey, const QString &username, const QString &password);

    void setLoginPublicKey(const QByteArray &lPKey);

    QByteArray getDecodedKey() const;
    QString getPurifiedKey() const;
    QByteArray getEncryptedCredentials() const;
    QList<int> getCredentials() const;

private:
    QString m_publicKey;
    QString m_loginPublicKey;
    QByteArray m_outputSignatureVector;
    QByteArray m_outputCredentialsVector;
    QList<int> m_credentials;
};

#endif
