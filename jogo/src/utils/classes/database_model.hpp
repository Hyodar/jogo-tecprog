
#include <vector>
template <class S>

class DatabaseModel {

public:
    virtual std::vector<float> store() = 0;
    //virtual S* recover() = 0;

};