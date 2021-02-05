#include <QCoreApplication>
#include <game.h>
//QString::fromUtf8().toLocal8Bit().data();
int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
    QCoreApplication app(argc, argv);

    srand(time(NULL));

    Game game;
    game.initGame();

    while (game.getPlaying())
    {
        game.mainMenu();
    }
    return app.exec();
}
