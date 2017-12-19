#include <QApplication>
#include "Game.h"
#include <QString>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Game* game = new Game(2);
    game->show();

    return a.exec();
}

