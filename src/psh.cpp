/***
 * @name psh.cpp
 * @author MignonPetitXelow / Xelow
 * @date 30-03-2023 
 */

#include "psh.h"

// Def of the constructor for the "psh.cpp" class
psh::psh(){}

executor exec;

int main()
{
    while(true)
    {
        // Display the prompt for the user to enter a command
        std::cout << std::endl << "\033[0;2;35m● " << std::getenv("USER") << "\033[0;2;34m→\033[0;2;0m ";

        // Read the user input
        char command[1024];
        std::cin.getline(command, 1024);

        // Create a vector to store args and extract the fist argument of the command
        std::vector<char*> args;
        char* prog = strtok(command, " ");
        char* temp = prog;

        // Loop to extract the following arguments of the command
        while(temp != NULL)
        {
            // Add the argument to the list of args
            args.push_back(temp);
            temp = strtok(NULL, " ");
        }
        
        // Execute the commands with the args
        int processResult = exec.prog_execution(args, command, prog, temp);

        // Exit
        if(processResult == 68)
            return 0;
    }

    return 0;
}