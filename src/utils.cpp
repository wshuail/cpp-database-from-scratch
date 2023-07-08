#include <iostream>
#include "utils.h"


void print_query(Query query){

    std::cout << "Query Columns: ";
    for (auto& column: query.columns) {
        std::cout << column << " ";
    }
    std::cout << std::endl;

    std::cout << "Query Table: " << query.table << '\n' << std::endl;

    std::cout << "Query Conditions: " << std::endl;
    for (auto& c : query.conditions) {
        std::cout << c.column << " " << c.op << " " << c.value << std::endl;
    }

}

