#include "CommentBuilder.h"

void CommentBuilder::setId(unsigned int id) {
    this->id = id;
}

void CommentBuilder::setOwner(unsigned owner_id) {
    this->owner = owner;
}

void CommentBuilder::setContent(const string &content) {
    this->content = content;
}

void CommentBuilder::setData(time_t data) {
    this->data = data;
}

void CommentBuilder::setAnswers(const vector<Record *> answers) {
    this->answers = answers;
}

Comment *CommentBuilder::getInstance() {
    return new Comment(
            this->id,
            this->content,
            this->data,
            this->answers
    );
}
