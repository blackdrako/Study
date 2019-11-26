#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>

#include "User.h"
#include "Comment.h"
#include "Post.h"
#include "UserBuilder.h"
#include "CommentBuilder.h"
#include "PostBuilder.h"

class DataBase{
private:
    DataBase(){};
    DataBase(const DataBase&);
    DataBase& operator=(const DataBase&);
    string dbfile;
    ifstream dbstream;
    vector<User> users;
    vector<User> loadUsers();
    vector<Record *> loadPosts(unsigned user_id);
    vector<Record *> loadComments(unsigned int parent_id);
    vector<Record *> loadAllComments(unsigned int parent_id);

    void goToSection(string section_name);
    void findId1(unsigned int id);
    void findId2(unsigned int id);
public:
    static DataBase& instance();
    void setDbFile(string dbfile);
    void load();
    void write();
    bool checkAccess(string name, string password);
    void addUser(User user);
    void addPost(User user, Post post);
    void addComment(User user, Record *parent, Comment comment);
    User *getUser(string name);
    User *getUser(unsigned id);
};

#endif // DATABASE_H
