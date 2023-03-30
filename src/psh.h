#ifndef PSH_HEADER
#define PSH_HEADER

#include "classes/handlers/executor.h"

#include <unistd.h>     // getpid(), getcwd()
#include <sys/types.h>  // type definitions, e.g., pid_t
#include <sys/wait.h>   // wait()
#include <signal.h>     // signal name constants and kill()
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class psh
{
    public:
        psh();
};

#endif