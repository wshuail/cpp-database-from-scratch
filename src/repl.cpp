#include <iostream>
#include <csignal>
#include "parser.h"
#include "utils.h"


void signal_handler(int signal){
    std::cout << "Ctrl-C pressed" << std::endl;
    exit(signal);
}

void print_prompt(std::string command){
    if (command.empty()){
        std::cout << "cmd> ";
    } else {
        std::cout << "   > ";
    }
    std::cout.flush();
}

std::string get_input(){
    std::string input;
    std::getline(std::cin, input);
    // std::cin >> input;
    return input;
}



