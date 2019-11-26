#ifndef COMMENTBUILDER_H
#define COMMENTBUILDER_H
#include <string>
#include <ctime>
#include <vector>

using namespace std;

#include "Comment.h"

class CommentBuilder{
private:
    unsigned id;
    unsigned owner;
    string content;
    time_t data;
    vector<Record *> answers;
public:
    void setId(unsigned int id);

    void setOwner(unsigned owner_id);

    void setContent(const string &content);

    void setData(time_t data);

    void setAnswers(const vector<Record *> answers);

    Comment *getInstance();
};

#endif // COMMENTBUILDER_H
