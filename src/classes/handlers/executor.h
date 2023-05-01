#ifndef EXECUTOR_HEADER
#define EXECUTOR_HEADER

#include <unistd.h>
#include <sys/types.h>  
#include <sys/wait.h>   
#include <signal.h>     
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "../commands/femfetch.h"

#include "../../psh.h"


class executor
{   
    public:
        executor();
        int prog_execution(std::vector<char*> args, char *command, char* prog, char* temp);
};

#endif