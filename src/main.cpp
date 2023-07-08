#include <iostream>
#include <csignal>
#include "parser.h"
#include "utils.h"
#include "repl.h"


int main(){

    std::string input;
    std::string command;

    while (true) {
        print_prompt(command);
        // std::getline(std::cin, input);
        input = get_input();
        // std::cout << "input: " << input << std::endl;

        command += input;
        // std::cout << "command: " << command << std::endl;

        if (input == "exit") {
            exit(0);
        } else if (input.front() == '\\' || input.back() == ';' ) {
            // std::cout << "Command:\n" << command << std::endl;
            Query query = parse_query(command);
            for (auto &column: query.columns){
                std::cout << column << " ";
            }
            print_query(query);
            command.clear();
        } else {
            command += '\n';
        }

        // exit if ctrl_c is pressed
        std::signal(SIGINT, signal_handler);

    }

    return 0;

}



