#include "executor.h"

executor::executor() {} 

int executor::prog_execution(std::vector<char*> args, char command[1024], char* prog, char* temp)
{
    char** arg_v = new char*[args.size()+1];
    for(int i = 0; i < args.size(); i++)
        arg_v[i] = args[i];

    if(strcmp(command, "exit") == 0)
    {
        std::cout << "● ⛈️  exiting Shell..." << std::endl;
        return 68;
    }
    else if(strcmp(command, "psh.reload") == 0)
    {
        std::cout << "● 📦  restarting Shell..." << std::endl;
        std::cout << "● 🦖  please wait..." << std::endl;
        execvp(std::strcat(std::getenv("HOME"), "/PurpleShell"), arg_v);
        perror(command);
        return 68;
    }
    else if(strcmp(command, "neofetch") == 0)
    {
        std::cout << " ● 🪸  neofetch is unavailable on Purple Shell for the time." << std::endl;
        return 0;
    }
    else
    {
        if (!strcmp (prog, "cd"))
        {
            if (arg_v[1] == NULL)
                chdir ("/");
            else
                chdir (arg_v[1]);
            perror(command);
        }
        else
        {
            pid_t kidpid = fork();

            if(kidpid < 0)
            {
                perror("Internal error: cannot fork.");
                return -1;
            }
            else if(kidpid == 0)
            {
                execvp(prog, arg_v);
                return -1;
            }
            else
            {
                if(waitpid(kidpid,0, 0) < 0 )
                {
                    perror("Internal error: cannot wait for child.");
                    return -1;
                }
            }
        }
    }
    return 0;
}