#include "RsaManager.h"

RsaManager::RsaManager()
{
    SSL_library_init();
    CRYPTO_malloc_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();

    std::stringstream stream;

    stream<<"-----BEGIN PUBLIC KEY-----\n"
            "MIIBUzANBgkqhkiG9w0BAQEFAAOCAUAAMIIBOwKCATIAgucoka9J2PXcNdjcu6CuDmgteIMB+rih\n"
            "2UZJIuSoNT/0J/lEKL/W4UYbDA4U/6TDS0dkMhOpDsSCIDpO1gPG6+6JfhADRfIJItyHZflyXNUj\n"
            "WOBG4zuxc/L6wldgX24jKo+iCvlDTNUedE553lrfSU23Hwwzt3+doEfgkgAf0l4ZBez5Z/ldp9it\n"
            "2NH6/2/7spHm0Hsvt/YPrJ+EK8ly5fdLk9cvB4QIQel9SQ3JE8UQrxOAx2wrivc6P0gXp5Q6bHQo\n"
            "ad1aUp81Ox77l5e8KBJXHzYhdeXaM91wnHTZNhuWmFS3snUHRCBpjDBCkZZ+CxPnKMtm2qJIi57R\n"
            "slALQVTykEZoAETKWpLBlSm92X/eXY2DdGf+a7vju9EigYbX0aXxQy2Ln2ZBWmUJyZE8B58CAwEA\n"
            "AQ==\n"
            "-----END PUBLIC KEY-----\n";

    m_publicKey = QString::fromStdString(stream.str());
}

QByteArray RsaManager::publicKeyDecrypt(const QByteArray &signature)
{
    char * DPKey = new char[m_publicKey.size()];
    strcpy(DPKey, m_publicKey.toStdString().c_str());

    BIO *bp_dofus = BIO_new_mem_buf(DPKey, -1);
    RSA *my_rsa = PEM_read_bio_RSA_PUBKEY(bp_dofus, NULL, NULL, NULL);

    uchar *inputSignature, *outputSignature;
    outputSignature = new uchar[RSA_size(my_rsa)];
    inputSignature = (uchar*)signature.data();

    int buflen = RSA_public_decrypt(signature.size(), inputSignature, outputSignature, my_rsa, RSA_PKCS1_PADDING);
    if(buflen == -1)
        qDebug()<<"ERREUR - RsaManager - Une erreur est survenue -"<<ERR_error_string(ERR_get_error(), NULL);

    RSA_free(my_rsa);
    BIO_free_all(bp_dofus);
    m_outputSignatureVector = QByteArray((const char*)outputSignature, buflen);
    delete outputSignature;
    delete DPKey;

    return m_outputSignatureVector;
}

QByteArray RsaManager::loginPublicKeyEncrypt(const QByteArray &credentials)
{
    char * loginPublicKeyByte = new char[m_loginPublicKey.size()];
    strcpy(loginPublicKeyByte, m_loginPublicKey.toStdString().c_str());

    BIO *bp_login = BIO_new_mem_buf(loginPublicKeyByte, -1);
    RSA *my_second_rsa = PEM_read_bio_RSA_PUBKEY(bp_login, NULL, NULL, NULL);
    uchar *pinputCredentials, *poutputCredentials;
    poutputCredentials = new uchar[RSA_size(my_second_rsa)];
    pinputCredentials = (uchar*)credentials.data();

    int buflen = RSA_public_encrypt(credentials.size(), pinputCredentials, poutputCredentials, my_second_rsa, RSA_PKCS1_PADDING);
    RSA_free(my_second_rsa);
    BIO_free_all(bp_login);

    m_outputCredentialsVector = QByteArray((const char*)poutputCredentials, buflen);
    delete poutputCredentials;
    delete loginPublicKeyByte;

    return m_outputCredentialsVector;
}

void RsaManager::setLoginPublicKey(const QByteArray &lPKey)
{
    const std::string lPKeyStr(lPKey.begin(), lPKey.end());
    QString lPKeyStrEnc = QByteArray(reinterpret_cast<const char*>(lPKeyStr.c_str()), lPKeyStr.length()).toBase64();

    std::stringstream lPKeyStrEncFor;
    for(int i=0; i!= lPKeyStrEnc.length(); i++){

        lPKeyStrEncFor << (lPKeyStrEnc).toStdString()[i];
        if((i+1)%76==0){
            if(i!=0) lPKeyStrEncFor << "\n";
        }
    }

    std::stringstream SlPKeyStrEnc;
    SlPKeyStrEnc << "-----BEGIN PUBLIC KEY-----" << "\n" << lPKeyStrEncFor.str() << "\n" << "-----END PUBLIC KEY-----";
    m_loginPublicKey = QString::fromStdString(SlPKeyStrEnc.str());
}

QList<int> RsaManager::generateCredentials(const QString &salt, QByteArray aesKey, const QString &username, const QString &password)
{
    Writer temp;
    temp.writeUTFBytes(salt.toStdString().c_str());
    temp.writeBytes(aesKey);
    temp.writeByte(username.size());
    temp.writeUTFBytes(username.toStdString().c_str());
    temp.writeUTFBytes(password.toStdString().c_str());

    QByteArray credentials(temp.getBuffer());

    credentials = loginPublicKeyEncrypt(credentials);
    Reader reader(credentials);
    m_credentials.clear();

    for(int i = 0; i < credentials.size(); i++)
    {
        char data = reader.readByte();
        m_credentials<<(int)data;
    }

    return m_credentials;
}

QByteArray RsaManager::getDecodedKey() const
{
    return m_outputSignatureVector;
}

QString RsaManager::getPurifiedKey() const
{
    return m_loginPublicKey;
}

QByteArray RsaManager::getEncryptedCredentials() const
{
    return m_outputCredentialsVector;
}

QList<int> RsaManager::getCredentials() const
{
    return m_credentials;
}

