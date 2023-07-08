#include <iostream>
#include <string>
#include <vector>
#include "parser.h"

std::vector<std::string> OPERATORS = {">", "<", "=", "!=", ">=", "<="};


std::string strip(const std::string& inpt) {
    auto start_it = inpt.begin();
    auto end_it = inpt.rbegin();

    while (start_it != inpt.end() && std::isspace(*start_it))
        ++start_it;

    while (end_it != inpt.rend() && std::isspace(*end_it))
        ++end_it;

    return std::string(start_it, end_it.base());
}

bool valid_condition(std::string cond) {
    for (auto op : OPERATORS) {
        if (cond.find(op) != std::string::npos) {
            return true;
        }
    }
    return false;
}


Condition split(std::string str){

    assert (valid_condition(str));
    
    Condition cond;

    for (auto op : OPERATORS) {
        size_t pos = str.find(op);
        if (pos != std::string::npos) {
            cond.column = strip(str.substr(0, pos));
            cond.op = op;
            cond.value = strip(str.substr(pos + op.size()));
            break;
        }
    }

    return cond;

}


std::vector<std::string> split(std::string str, char delim) {
    std::vector<std::string> tokens;

    std::string::size_type last_pos = str.find_first_not_of(delim, 0);
    std::string::size_type pos = str.find_first_of(delim, last_pos);

    while (std::string::npos != pos || std::string::npos != last_pos) {
        std::string token = str.substr(last_pos, pos - last_pos);
        token = strip(token);
        tokens.push_back(token);
        last_pos = str.find_first_not_of(delim, pos);
        pos = str.find_first_of(delim, last_pos);
    }
   
    return tokens;
}

Query parse_query(std::string query) {
    
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);
    
    Query q;
    // parse query
    size_t select_pos = query.find("select");
    size_t from_pos = query.find("from");
    std::string select_clause = query.substr(select_pos + 7, from_pos - select_pos - 8);
    std::vector<std::string> columns;
    columns = split(select_clause, ',');
    for (auto col : columns) {
        q.columns.push_back(col);
    }
    
    size_t where_pos = query.find("where");
    std::string table_clause = query.substr(from_pos + 5, where_pos - from_pos - 6);
    table_clause = strip(table_clause);
    q.table = table_clause;

    size_t end_pos = query.find(";");
    std::string where_clause = query.substr(where_pos + 6, end_pos - where_pos - 6);
    where_clause += " and";

    while (where_clause.find("and") != std::string::npos) {
        Condition cond;
        size_t and_pos = where_clause.find("and");
        std::string left = where_clause.substr(0, and_pos);
        left = strip(left);

        cond = split(left);
        q.conditions.push_back(cond);
        
        std::string right = where_clause.substr(and_pos + 3);
        right = strip(right);
        where_clause = right;
    }

    return q;

}


