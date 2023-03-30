#pragma once

class commandobj
{
    public:
        virtual int execute(void) = 0;
        virtual const char** data(void) = 0;
};