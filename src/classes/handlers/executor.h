#ifndef EXECUTOR_HEADER
#define EXECUTOR_HEADER

#include <string>
#include <stdio.h>

class executor
{   
    public:
        executor();
        int prog_execution(std::string native_path);
};

#endif