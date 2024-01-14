#include <stdio.h>
#include <iostream>
#include <string>
#include <getopt.h>

int main()
{
    while (1)
    {
        std::cout << "< ";
        std::string in;
        std::cin >> in;
        if (in == "exit")
        {
            break;
        }
    }
    return 0;
}