#include "psh.h"

psh::psh(){}

executor exec;

int main()
{
    while(true)
    {
        std::cout << std::endl << "● " << std::getenv("USER") << "→ ";
        char command[1024];
        std::cin.getline(command, 1024);

        std::vector<char*> args;
        char* prog = strtok(command, " ");
        char* temp = prog;

        while(temp != NULL)
        {
            args.push_back(temp);
            temp = strtok(NULL, " ");
        }

        int processResult = exec.prog_execution(args, command, prog, temp);
        if(processResult == 68)
            return 0;
    }

    return 0;
}