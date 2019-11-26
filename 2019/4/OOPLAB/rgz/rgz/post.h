#ifndef POST_H
#define POST_H
#include "Record.h"

class Post : public Record{
public:
    Post(unsigned int id, string content, time_t date, vector<Record *> answers) : Record(id, content, date, answers){};
};

#endif // POST_H
