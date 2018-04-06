#ifndef SINGLETON_H
#define SINGLETON_H

#include "Public.h"

template <typename T>
class Singleton
{
protected:
    Singleton(){}
    ~Singleton(){}

public:

    static T* get()
    {

        if (m_init == false)
        {
            m_instance = new T();
            m_init = true;
        }
        return m_instance;
    }

    static void kill()
    {
        delete m_instance;
        m_init = false;
        m_instance = NULL;
    }

private:
    static bool m_init;
    static T* m_instance;
};

template <typename T>
T* Singleton<T>::m_instance = NULL;

template<typename T>
bool Singleton<T>::m_init = false;

#endif // SINGLETON_H
