#ifndef UI_H
#define UI_H
#include <iostream>

using namespace std;

#include "User.h"
#include "Post.h"
#include "Comment.h"
#include "UserBuilder.h"
#include "PostBuilder.h"
#include "CommentBuilder.h"
#include "DataBase.h"

class Ui{
public:
    void loginDialog();
    void registrationDialog();
    void userDialog(string user_name);
    void postDialog(Post post);
    void commentDialog(Record comment);
};

#endif // UI_H
