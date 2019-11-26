#ifndef RECORD_H
#define RECORD_H
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class Record{
private:
    unsigned id;
    unsigned owner;
    string content;
    time_t date;
    vector<Record *> answers;
public:
    const vector<Record *> &getAnswers() const {
        return answers;
    }
    const string &getContent() const {
        return content;
    }
    const time_t getDate() const {
        return date;
    }
    unsigned getId() const{
        return id;
    }
    unsigned getOwner() const{
        return owner;
    }
    void addAnswer(Record *answer);
    Record(unsigned int id, string content, time_t date, vector<Record *> answers) : id(id), content(content), date(date), answers(answers) {}
};

#endif // RECORD_H
