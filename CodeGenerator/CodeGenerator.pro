QMAKE_MAC_SDK = macosx10.11
CONFIG +=c++11

QMAKE_CXXFLAGS_DEBUG -= -O
QMAKE_CXXFLAGS_RELEASE += -O3

QT += gui network core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CodeGenerator

HEADERS += \
    AbstractParser.h \
    AbstractSerializer.h \
    Public.h \
    HeaderSerializer.h \
    Splitter.h \
    SourceSerializer.h \
    Translator.h \
    MessageTranslator.h \
    ClassTranslator.h \
    ClassLocalizer.h \
    MessageLocalizer.h \
    MessageDeclarator.h \
    GlobalTranslator.h \
    ClassManager.h \
    EnumLocalizer.h \
    EnumTranslator.h \
    EnumDeclarator.h \
    ClassDeclarator.h \
    DataTranslator.h \
    DataLocalizer.h \
    DataDeclarator.h \
    DataTypeDeclarator.h \
    DataConverter.h \
    MessageEnum.h \
    ClassEnum.h \
    MessageUtils.h

SOURCES += \
    AbstractParser.cpp \
    AbstractSerializer.cpp \
    main.cpp \
    HeaderSerializer.cpp \
    Splitter.cpp \
    SourceSerializer.cpp \
    Translator.cpp \
    MessageTranslator.cpp \
    ClassTranslator.cpp \
    ClassLocalizer.cpp \
    MessageLocalizer.cpp \
    GlobalTranslator.cpp \
    MessageDeclarator.cpp \
    ClassManager.cpp \
    EnumLocalizer.cpp \
    EnumTranslator.cpp \
    EnumDeclarator.cpp \
    ClassDeclarator.cpp \
    DataTranslator.cpp \
    DataLocalizer.cpp \
    DataDeclarator.cpp \
    DataTypeDeclarator.cpp \
    DataConverter.cpp \
    MessageEnum.cpp \
    ClassEnum.cpp \
    MessageUtils.cpp
