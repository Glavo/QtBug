#include <QFile>
#include <QDebug>

int main() {
    qInfo() << QFile(":/a.json").exists();
}
