#include "Ui.h"
#include <QTextCodec>
void Ui::loginDialog() {
    system("cls");
    cout << QString::fromUtf8("Вы находитесь на странице входа").toLocal8Bit().data() << endl;
    string name;
    string password;
    cout << QString::fromUtf8("Введите имя пользователя:").toLocal8Bit().data() << endl;
    cin >> name;
    cout << QString::fromUtf8("Введите пароль:").toLocal8Bit().data() << endl;
    cin >> password;
    if (DataBase::instance().checkAccess(name, password)){
        cout << QString::fromUtf8("Вход успешен. В блог какого пользователя перейти? ").toLocal8Bit().data() << endl;
        cin >> name;
        userDialog(name);
    }else{
        cout << QString::fromUtf8("Пользователь не зарегистрирован. Повторить попытку (1), перейти к регистрации (2) или выйти (0)?").toLocal8Bit().data() << endl;
        int choice;
        cin >> choice;
        if (choice == 1){
            loginDialog();
        }else if (choice == 2){
            registrationDialog();
        }
    }
}

void Ui::registrationDialog() {
    system("cls");
    cout << QString::fromUtf8("Вы находитесь на странице регистрации").toLocal8Bit().data() << endl;
    UserBuilder ub;
    string name;
    cout << QString::fromUtf8("Введите имя пользователя:").toLocal8Bit().data() << endl;
    cin >> name;
    ub.setName(name);
    string password;
    cout << QString::fromUtf8("Введите пароль:").toLocal8Bit().data() << endl;
    cin >> password;
    ub.setPassword(password);
    DataBase::instance().addUser(ub.getInstance());
    loginDialog();
}

void Ui::userDialog(string user_name) {
    system("cls");
    cout << QString::fromUtf8("Вы просматриваете информацию о пользователе").toLocal8Bit().data() << endl;
    User *u = DataBase::instance().getUser(user_name);
    cout << QString::fromUtf8("Имя: ").toLocal8Bit().data() << u->getName() << endl;
    cout << QString::fromUtf8("Созданные посты: ").toLocal8Bit().data() << endl;
    for (auto it = u->getPosts().begin(); it != u->getPosts().end(); it++){
        cout << it->getId() << endl;
    }
    cout << QString::fromUtf8("Введите номер поста для просмотра или 0 чтобы выйти").toLocal8Bit().data() << endl;
    int choice;
    cin >> choice;
    if (choice){
        for (auto it = u->getPosts().begin(); it != u->getPosts().end(); it++){
            if (it->getId() == choice){
                postDialog(*it);
            }
        }
    }
}

void Ui::postDialog(Post post) {
    system("cls");
    cout << QString::fromUtf8("Вы просматриваете информацию о посте").toLocal8Bit().data() << endl;
    cout << QString::fromUtf8("Автор поста: ").toLocal8Bit().data() << DataBase::instance().getUser(post.getOwner()) << endl;
    time_t raw_time = post.getDate();
    cout << QString::fromUtf8("Дата создания: ").toLocal8Bit().data() << asctime(localtime(&raw_time));
    cout << QString::fromUtf8("Содержание: ").toLocal8Bit().data() << endl << post.getContent() << endl;
    cout << QString::fromUtf8("Комментарии: ").toLocal8Bit().data() << endl;
    for (auto it = post.getAnswers().begin(); it != post.getAnswers().end(); it++){
        cout << (*it)->getId() << endl;
    }
    cout << QString::fromUtf8("Введите номер комментария для просмотра или 0 чтобы выйти").toLocal8Bit().data() << endl;
    int choice;
    cin >> choice;
    if (choice){
        for (auto it = post.getAnswers().begin(); it != post.getAnswers().end(); it++){
            if ((*it)->getId() == choice){
                commentDialog(**it);
            }
        }
    }
}

void Ui::commentDialog(Record comment) {
    system("cls");
    cout << QString::fromUtf8("Вы просматриваете информацию о комментарии").toLocal8Bit().data() << endl;
    cout << QString::fromUtf8("Автор комментария: ").toLocal8Bit().data() << DataBase::instance().getUser(comment.getOwner()) << endl;
    time_t raw_time = comment.getDate();
    cout << QString::fromUtf8("Дата создания: ").toLocal8Bit().data() << asctime(localtime(&raw_time));
    cout << QString::fromUtf8("Содержание: ").toLocal8Bit().data() << endl << comment.getContent() << endl;
    cout << QString::fromUtf8("Ответы: ").toLocal8Bit().data() << endl;
    for (auto it = comment.getAnswers().begin(); it != comment.getAnswers().end(); it++){
        cout << (*it)->getId() << endl;
    }
    cout << QString::fromUtf8("Введите номер комментария для просмотра или 0 чтобы выйти").toLocal8Bit().data() << endl;
    int choice;
    cin >> choice;
    if (choice){
        for (auto it = comment.getAnswers().begin(); it != comment.getAnswers().end(); it++){
            if ((*it)->getId() == choice){
                commentDialog(**it);
            }
        }
    }
}
