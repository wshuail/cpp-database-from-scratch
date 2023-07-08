#ifndef parser_h
#define parser_h

#include <string>
#include <vector>

struct Condition {
    std::string column;
    std::string op;
    std::string value;
};

struct Query {
    std::vector<std::string> columns;
    std::string table;
    std::vector<Condition> conditions;
};


Query parse_query(std::string query);


#endif

