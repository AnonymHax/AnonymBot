#ifndef CLASSMANAGER_H
#define CLASSMANAGER_H

#include "System/Tools/Singleton.h"
#include "Network/Classes/AbstractClass.h"

class ClassManagerSingleton;

class ClassManager
{
  friend Singleton<ClassManager>;

public:
  QSharedPointer<AbstractClass> getClass(int classId);
};

class ClassManagerSingleton : public Singleton<ClassManager>
{};

#endif // CLASSMANAGER_H