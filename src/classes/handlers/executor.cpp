#include "executor.h"

executor::executor() {} 

int executor::prog_execution(std::string native_path)
{
    FILE *ha = popen(native_path.c_str(), "r");

    if(ha == NULL)
        return 465;

    char buf[64];
    size_t read;
    while((read = fread(buf, 1, sizeof(buf), ha)) > 0)
        fwrite(buf, 1, read, stdout);
        
    pclose(ha);

    return 0;
}