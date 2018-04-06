#ifndef SERVERSTATUSENUM_H
#define SERVERSTATUSENUM_H

enum class ServerStatusEnum
{
    STATUS_UNKNOWN = 0,
    OFFLINE = 1,
    STARTING = 2,
    ONLINE = 3,
    NOJOIN = 4,
    SAVING = 5,
    STOPING = 6,
    FULL = 7
};

#endif // SERVERSTATUSENUM_H