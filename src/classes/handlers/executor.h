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

#include "../../psh.h"


class executor
{   
    public:
        executor();
        int prog_execution(std::vector<char*> args, char command[1024], char* prog, char* temp);
};

#endif