#ifndef HANDLER_HEADER
#define HANDLER_HEADER

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "../handlers/executor.h"

class handlers
{
    public:
        handlers();
        int listen(bool debug, int arg_c, std::string arg_v);
};

#endif