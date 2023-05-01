/***
 * @name executor.cpp
 * @author MignonPetitXelow / Xelow
 * @date 30-03-2023
 */

#include "executor.h"
#include "../utils/color.h"

// Def of the constructor for the "executor.cpp" class
executor::executor() {} 

int executor::prog_execution(std::vector<char*> args, char *command, char* prog, char* temp)
{
    // Allocate memory for the char array holding the command args and copy args from the vector to the char array
    char** arg_v = new char*[args.size()+1];
    for(int i = 0; i < args.size(); i++)
        arg_v[i] = args[i];

    // Check if the command is "exit" or "psh.reload"
    if(strcmp(command, "exit") == 0)
    {
        std::cout << "● ⛈️  exiting Shell..." << std::endl;
        exit(0);
    }
    else if(strcmp(command, "psh.reload") == 0)
    {
        std::cout << "● 📦  restarting Shell..." << std::endl;
        std::cout << "● 🦖  please wait..." << std::endl;

        // Concatenate the HOME directory path with the "PurpleShell" binary filename to get the full path to the binary and exec program
        execvp("/bin/PurpleShell", arg_v);
        perror(command);

        exit(0);
    }
    else if(strcmp(command, "neofetch") == 0)
    {
        femfetch femfetch;
        femfetch.fetch();
        return 0;
    }
    else
    {
        if(strcmp(prog, "cd") == 0) 
        {
            // If there is no arg after "cd", change the working directory to the root directory
            if (arg_v[1] == NULL)
                chdir("/");

            // Otherwise, change the working directory to the specified directory
            else
                chdir(arg_v[1]);
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
                if(errno != 0)
                {
                    std::string err = ""; err += RED_FOREGROUND; err += "× "; err += command;
                    perror(err.c_str());
                    exit(0);
                }
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

