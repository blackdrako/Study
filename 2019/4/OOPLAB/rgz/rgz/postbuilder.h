#ifndef POSTBUILDER_H
#define POSTBUILDER_H
#include <string>
#include <ctime>
#include <vector>

#include "Post.h"

using namespace std;

class PostBuilder{
private:
    unsigned id;
    unsigned owner;
    string content;
    time_t data;
    vector<Record *> answers;
public:
    void setId(unsigned int id);

    void setOwner(unsigned owner);

    void setContent(const string &content);

    void setData(time_t data);

    void setAnswers(vector<Record *> answers);

    Post *getInstance();
};

#endif // POSTBUILDER_H
