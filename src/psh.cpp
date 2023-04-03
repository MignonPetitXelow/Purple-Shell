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
        std::cout << std::endl << PURPLE_FOREGROUND << "○ " << std::getenv("USER") << BLUE_FOREGROUND << "→" << RESET <<" ";

        // Read the user input
        char *command = NULL;
        size_t size = 0;
        size_t len = getline(&command, &size, stdin);
        command[len - 1] = '\0';

        // Check for EOF (Ctrl+D)
        if(feof(stdin))
        {
            std::cout << std::endl << GREEN_FOREGROUND << "● " << RESET << "seeya later!" << std::endl;
            exit(0);
        }

        // Create a vector to store arguments and extract the first argument of the command
        std::vector<char*> args;
        char* prog = strtok(command, " ");
        char* temp = prog;

        // Loop to extract the following arguments of the command
        while(temp != NULL)
        {
            // Add the argument to the list of arguments
            args.push_back(temp);
            temp = strtok(NULL, " ");
        }
        
        // Execute the commands with the arguments
        int processResult = exec.prog_execution(args, command, prog, temp);

        // Exit
        if(processResult == 68)
            return 0;
    }

    return 0;
}
