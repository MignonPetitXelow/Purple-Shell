#include "psh.h"

psh::psh(){}

handlers handler;

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::string arg_v;

    while(true)
    {
        std::cout << "● " << std::getenv("USER") << "→ ";
        std::cin >> arg_v;
        int operationResult = handler.listen(false, 5, arg_v);
        if(operationResult > 0)
        std::cout << "Operation failed with error code " << operationResult << std::endl;
    }

    //cc
    return 0;
}