#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "User.h"

User::User(std::string name, std::string password) : name(name), password(password) {}

User::User(unsigned id, std::string name, std::string password) : id(id), name(name), password(password) {}

unsigned int User::getId() const {
    return id;
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getPassword() const {
    return password;
}

const std::vector<Post> &User::getPosts() const {
    return posts;
}
