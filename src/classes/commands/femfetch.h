#ifndef FEMFETCH_HEADER
#define FEMFETCH_HEADER

#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <fstream>
#include <sys/statvfs.h>
#include "../utils/color.h"

class femfetch
{
    public:
        femfetch();
        std::string get_cpu(void);
        long get_totalmemory(void);
        std::string get_kernel(void);
        std::string get_os(void);
        std::string get_distrib(void);
        unsigned long get_totaldiskspace(void);
        void fetch(void);
};

#endif