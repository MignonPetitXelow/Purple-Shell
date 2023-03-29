#include "handlers.h"

handlers::handlers() {}

executor exec;

int handlers::listen(bool debug, int arg_c, std::string arg_v)
{
    if(arg_c == 0)
    {
        return 343;
    }
    if(arg_c == 1)
    {
        return 0;   
    }
    else
    {
        std::string command = "/bin/"; command += arg_v;
        if(debug) std::cout << "[DEBUG] command typed " << command << std::endl;
        //std::system(command.c_str()); // change this doesnt work with argumented commands
        exec.prog_execution(command);
        return 0;
    }
    return 221;
}