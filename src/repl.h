#ifndef REPL_H
#define REPL_H

#include <string>

void signal_handler(int signal);
void print_prompt(std::string command);
std::string get_input();

#endif // !REPL_H

