#include "Public.h"
#include "GlobalTranslator.h"

int main(int argc, char *argv[])
{   

    QTime timer;
    timer.start();

    GlobalTranslator globalTranslator1("/Users/Victor/Desktop/Bot-Tools/Sources",
                                      "/Users/Victor/Desktop/Translate",
                                      TRANSLATION_1);

    globalTranslator1.parse();
    globalTranslator1.serialize();
    globalTranslator1.write();

    qDebug()<<"Traduction 1 terminée en"<<timer.elapsed()<<"ms";


    GlobalTranslator globalTranslator2("/Users/Victor/Desktop/Bot-Tools/Sources",
                                       "/Users/Victor/Desktop/Translate",
                                      TRANSLATION_2);

    globalTranslator2.parse();
    globalTranslator2.serialize();
    globalTranslator2.write();

    qDebug()<<"Traduction 2 terminée en"<<timer.elapsed()<<"ms";
    return 0;
}
