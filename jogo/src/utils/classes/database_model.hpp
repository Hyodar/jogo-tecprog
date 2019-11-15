
#ifndef DATABASE_MODEL_HPP_
#define DATABASE_MODEL_HPP_

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class DatabaseModel {

public:
    virtual json store() = 0;

};

#endif // DATABASE_MODEL_HPP_
