
#include <library.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


   // QSettings settings;
  //  QString dbPath = settings.readValue("DBPath", QString(/*fallback path*/)).toString();
    //do smth with dbPath
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    w.show();
    return a.exec();
}
