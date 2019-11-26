#ifndef USER_H
#define USER_H
#include "Post.h"

class User {
private:
    unsigned id;
    std::string name;
public:
    unsigned int getId() const;
    const std::string &getName() const;
    const std::string &getPassword() const;
    const std::vector<Post> &getPosts() const;
    void addPost(Post post);
private:
    std::string password;
    std::vector<Post> posts;
public:
    User(
            std::string name,
            std::string password
    );
    User(
            unsigned id,
            std::string name,
            std::string password
    );
};

#endif // USER_H
