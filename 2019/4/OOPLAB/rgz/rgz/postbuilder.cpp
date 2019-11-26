#include "PostBuilder.h"

void PostBuilder::setId(unsigned int id) {
    this->id = id;
}

void PostBuilder::setOwner(unsigned owner) {
    this->owner = owner;
}

void PostBuilder::setContent(const string &content) {
    this->content = content;
}

void PostBuilder::setData(time_t data) {
    this->data = data;
}

void PostBuilder::setAnswers(vector<Record *> answers) {
    this->answers = answers;
}

Post * PostBuilder::getInstance() {
    return new Post(
            this->id,
            this->content,
            this->data,
            this->answers
    );
}
