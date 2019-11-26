#include "DataBase.h"

vector<User> DataBase::loadUsers() {
    vector<User> result;
    this->goToSection("Users");
    char temp[256];
    UserBuilder user_builder;
    this->dbstream.getline(temp, 256);
    while (temp[0] != '['){
        user_builder.setId(atoi(temp));
        this->dbstream.getline(temp, 256);
        user_builder.setName(temp);
        this->dbstream.getline(temp, 256);
        user_builder.setPassword(temp);
        this->dbstream.getline(temp, 256);
        result.push_back(user_builder.getInstance());
    }
    for(auto it = result.begin(); it != result.end(); it++){
        auto id = it->getId();
        this->loadPosts(id);
    }
    return result;
}

vector<Record *> DataBase::loadPosts(unsigned user_id) {
    vector<Record *> result;
    this->goToSection("UserPosts");
    this->findId1(user_id);
    int count;
    dbstream >> count;
    vector<unsigned> posts_ids;
    unsigned temp_id;
    char temp[256];
    for (int i = 0; i<count; i++){
        dbstream >> temp_id;
        posts_ids.push_back(temp_id);
    }
    PostBuilder post_builder;
    for(auto it = posts_ids.begin(); it != posts_ids.end(); it++){
        this->goToSection("Posts");
        this->findId2(*it);

        this->dbstream.getline(temp, 256);
        post_builder.setId(atoi(temp));
        this->dbstream.getline(temp, 256);
        post_builder.setOwner(atoi(temp));
        this->dbstream.getline(temp, 256);
        post_builder.setData(atoi(temp));
        this->dbstream.getline(temp, 256);
        post_builder.setContent(temp);

        post_builder.setAnswers(this->loadComments(*it));

        result.push_back(post_builder.getInstance());
    }
    return result;
}

vector<Record *> DataBase::loadComments(unsigned parent_id) {
    vector<Record *> result;
    this->goToSection("PostComments");
    this->findId1(parent_id);
    int count;
    dbstream >> count;
    vector<unsigned> answers_ids;
    unsigned temp_id;
    char temp[256];
    for (int i = 0; i<count; i++){
        dbstream >> temp_id;
        answers_ids.push_back(temp_id);
    }
    CommentBuilder comment_builder;
    for(auto it = answers_ids.begin(); it != answers_ids.end(); it++){
        this->goToSection("Comments");
        this->findId2(*it);

        this->dbstream.getline(temp, 256);
        comment_builder.setId(*it);
        this->dbstream.getline(temp, 256);
        comment_builder.setOwner(atoi(temp));
        this->dbstream.getline(temp, 256);
        comment_builder.setData(atoi(temp));
        this->dbstream.getline(temp, 256);
        comment_builder.setContent(temp);

        comment_builder.setAnswers(this->loadComments(*it));

        result.push_back(comment_builder.getInstance());
    }
    return result;
}

void DataBase::load() {
    this->users = this->loadUsers();
}

void DataBase::write() {
    ofstream exportstream("export.txt");
    // ofstream exportstream(dbfile);
    auto users = loadUsers();
    exportstream << "[Users]" << endl;
    for (auto it = users.begin(); it != users.end(); it++){
        exportstream << it->getId() << endl;
        exportstream << it->getName() << endl;
        exportstream << it->getPassword() << endl;
    }
    exportstream << "[UserPosts]" << endl;
    for (auto it = users.begin(); it != users.end(); it++) {
        auto posts = it->getPosts();
        exportstream << it->getId() << " ";
        exportstream << posts.size() << " ";
        for (auto p = posts.begin(); p != posts.end(); p++) {
            exportstream << p->getId() << " ";
        }
    }
    exportstream << "[Posts]" << endl;
    for (auto it = users.begin(); it != users.end(); it++){
        auto posts = it->getPosts();
        for (auto p = posts.begin(); p != posts.end(); p++){
            exportstream << p->getId() << endl;
            exportstream << p->getOwner() << endl;
            exportstream << p->getDate() << endl;
            exportstream << p->getContent() << endl;
        }
    }
    exportstream << "[PostComments]" << endl;
    for (auto it = users.begin(); it != users.end(); it++){
        auto posts = it->getPosts();
        for (auto p = posts.begin(); p != posts.end(); p++){
            exportstream << p->getId() << " ";
            auto comments = this->loadAllComments(p->getId());
            exportstream << comments.size() << " ";
            for (auto c = comments.begin(); c!= comments.end(); c++){
                exportstream << (*c)->getId() << " ";
            }
        }
    }
    exportstream << "[Comments]" << endl;
    for (auto it = users.begin(); it != users.end(); it++){
        auto posts = it->getPosts();
        for (auto p = posts.begin(); p != posts.end(); p++){
            exportstream << p->getId() << " ";
            auto comments = this->loadAllComments(p->getId());
            exportstream << comments.size() << " ";
            for (auto c = comments.begin(); c!= comments.end(); c++){
                exportstream << (*c)->getId() << endl;
                exportstream << (*c)->getOwner() << endl;
                exportstream << (*c)->getDate() << endl;
                exportstream << (*c)->getContent() << endl;
            }
        }
    }
    exportstream.close();
}

void DataBase::setDbFile(string dbfile){
    this->dbfile = dbfile;
    this->dbstream.open(dbfile);
}

DataBase &DataBase::instance() {
    static DataBase instance;
    return instance;
}

void DataBase::goToSection(string section_name) {
    dbstream.seekg(0, dbstream.beg);
    char temp[256];
    do{
        dbstream.getline(temp, 256);
    }while (string(temp) != "[" + section_name + "]");
}

void DataBase::findId1(unsigned id){
    unsigned temp_id = 0;
    char temp[256];
    dbstream >> temp_id;
    while (temp_id != id){
        dbstream.getline(temp, 256);
        dbstream >> temp_id;
    }
}

void DataBase::findId2(unsigned id){
    unsigned temp_id;
    char temp[256];
    dbstream >> temp_id;
    while (temp_id != id){
        for(int i = 0; i<4; i++){
            dbstream.getline(temp, 256);
        }
        dbstream >> temp_id;
    }
}

vector<Record *> DataBase::loadAllComments(unsigned int parent_id) {
    vector<Record *> result;
    this->goToSection("PostComments");
    this->findId1(parent_id);
    int count;
    dbstream >> count;
    vector<unsigned> answers_ids;
    unsigned temp_id;
    char temp[256];
    for (int i = 0; i<count; i++){
        dbstream >> temp_id;
        answers_ids.push_back(temp_id);
    }
    CommentBuilder comment_builder;
    for(auto it = answers_ids.begin(); it != answers_ids.end(); it++){
        this->goToSection("Comments");
        this->findId2(*it);

        this->dbstream.getline(temp, 256);
        comment_builder.setId(*it);
        this->dbstream.getline(temp, 256);
        comment_builder.setOwner(atoi(temp));
        this->dbstream.getline(temp, 256);
        comment_builder.setData(atoi(temp));
        this->dbstream.getline(temp, 256);
        comment_builder.setContent(temp);

        auto answers = this->loadAllComments(*it);
        comment_builder.setAnswers(answers);
        result.insert(result.end(), answers.begin(), answers.end());

        result.push_back(comment_builder.getInstance());
    }
    return result;
}

bool DataBase::checkAccess(string name, string password) {
    auto users = loadUsers();
    for (auto it = users.begin(); it!=users.end(); it++){
        if (it->getName() == name && it->getPassword() == password){
            return true;
        }
    }
    return false;
}

void DataBase::addUser(User user){
    this->users.push_back(user);
}

void DataBase::addPost(User user, Post post){
    for(auto it = users.begin(); it != users.end(); it++){
        if (it->getId() == user.getId()){
            //it->addPost(post);
        }
    }
}

void DataBase::addComment(User user, Record *parent, Comment comment){
    parent->addAnswer(&comment);
}

User *DataBase::getUser(string name) {
    for (auto it = users.begin(); it != users.end(); it++){
        if (it->getName() == name){
            return &(*it);
        }
    }
    return nullptr;
}

User *DataBase::getUser(unsigned id) {
    for (auto it = users.begin(); it != users.end(); it++){
        if (it->getId() == id){
            return &(*it);
        }
    }
    return nullptr;
}
