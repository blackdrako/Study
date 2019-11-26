#ifndef COMMENT_H
#define COMMENT_H
#include "Record.h"

class Comment : public Record{
public:
    Comment(unsigned int id, string content, time_t date, vector<Record *> answers) : Record(id, content, date, answers){};
};

#endif // COMMENT_H
