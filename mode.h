#ifndef MODE_H
#define MODE_H

#include <vector>

class Mode {
public:
    virtual std::vector<unsigned int> getOrder() = 0;
};


#endif //MODE_H
