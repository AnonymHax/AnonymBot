#ifndef PARAMSDECODER_H
#define PARAMSDECODER_H

#include "System/Tools/IO/D2O/GameDataDeclarator.h"
#include "System/Tools/IO/D2O/D2OManager.h"

class ParamsDecoder
{
public:
    static QString decodeParams(QString message, QStringList parameters, QString paramPrefix = "%");

private:
    static QString processReplace(QString param1, QString paramIdentifier, QStringList parameters);
};

#endif // PARAMSDECODER_H
