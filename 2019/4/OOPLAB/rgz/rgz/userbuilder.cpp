#include "UserBuilder.h"
void UserBuilder::setName(const string &name) {
    this->name = name;
}
void UserBuilder::setPassword(const string &password) {
    this->password = password;
}
User UserBuilder::getInstance() {
    return User(this->id, this->name, this->password);
}
void UserBuilder::setId(unsigned id) {
    this->id = id;
}
