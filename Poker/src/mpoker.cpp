#include <stdio.h>
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#define MAX_INPUT_SIZE 128
int main(int argc, char ** argv)
{
    std::string currLine;
    const std::string DELIMITER = " ";
    while(1)
    {
        std:: cout<< "> ";   
        std::getline(std::cin, currLine);
        currLine.erase(std::unique(currLine.begin(), currLine.end(), [](char a, char b){return a == ' ' && b == ' ';}), currLine.end());
        std::size_t pos = currLine.find(DELIMITER, 0);
        std::string keyword = currLine.substr(0, pos);
        if(keyword.compare("exit") == 0){
            std::cout << "[MPoker]: exiting\n";
            return 0;
        }else if(keyword.compare("join") == 0){

        }else{
            std::cout << "[MPoker]: unknown command\n";
        }
    }
    return 0;
}