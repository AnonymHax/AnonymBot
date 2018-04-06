#include "AbstractServerModule.h"

AbstractServerModule::AbstractServerModule()
{
    ServerHandlerSingleton::get()->addModule(this);
}

AbstractServerModule::~AbstractServerModule()
{
}

void AbstractServerModule::serverConnectionEstablished()
{
}

void AbstractServerModule::serverConnectionFailed()
{
}

void AbstractServerModule::serverDisconnected(bool anticipatedDisconnection)
{
}
