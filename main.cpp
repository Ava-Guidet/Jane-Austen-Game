#include <QApplication>
#include "austen.h"
int main(int argc, char ** argv){
    QApplication app(argc,argv);
    Austen austenQ;
    austenQ.show();
    return app.exec();
}
