#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <set>

#include "network/client.hpp"

#define MAX_INPUT_SIZE 128

int main(int argc, char ** argv)
{
    std::string currLine;
    std::set<std::string> usernames;

    const std::string DELIMITER = " ";
    const std::string ERROR_MESSAGE =  "[MPoker]: unknown command\n";
    const std::string REPEATED_USERNAME_ERROR_MESSAGE =  "[MPoker]: username in use\n";
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

        }else if(keyword.compare("leave") == 0){
            
        }else if(keyword.compare("create") == 0){
            std::size_t oldPos = pos;
            pos = currLine.find(DELIMITER, oldPos + 1);
            keyword = currLine.substr(oldPos + 1, pos - oldPos - 1);
            if(keyword.compare("user") == 0){
                oldPos = pos;
                pos = currLine.find(DELIMITER, pos + 1);
                keyword = currLine.substr(oldPos + 1, pos);
                if(usernames.find(keyword) == usernames.end()){
                    usernames.insert(keyword);
                }else{
                    std::cout << REPEATED_USERNAME_ERROR_MESSAGE;
                }
            }else if(keyword.compare("server") == 0){
                oldPos = pos;
                pos = currLine.find(DELIMITER, pos);
                keyword = currLine.substr(oldPos + 1, pos);
            }else{
                std::cout << ERROR_MESSAGE;
            }
        }else{
            std::cout << ERROR_MESSAGE;
        }
    }
    return 0;
}