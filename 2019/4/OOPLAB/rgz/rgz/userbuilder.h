#ifndef USERBUILDER_H
#define USERBUILDER_H
#include "User.h"

class UserBuilder{
private:
    string name;
    string password;
    unsigned int id;
public:
    void setName(const string &name);
    void setPassword(const string &password);
    void setId(unsigned id);
    User getInstance();
};

#endif // USERBUILDER_H
