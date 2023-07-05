#include <iostream>
#include <csignal>

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
    std::cin >> input;
    return input;
}


int main(){

    std::string input;
    std::string command;

    while (true) {
        print_prompt(command);
        // std::getline(std::cin, input);
        input = get_input();

        command += input;

        if (input == "exit") {
            exit(0);
        } else if (input.front() == '\\' || input.back() == ';' ) {
            std::cout << "Command:\n" << command << std::endl;
            command.clear();
        } else {
            command += '\n';
        }

        // exit if ctrl_c is pressed
        std::signal(SIGINT, signal_handler);

    }

    return 0;

}



