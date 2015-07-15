#include <QtGui>
#include <QtQuick>

#include "openurlclient.h"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    QQuickView view;

    OpenUrlClient *openUrlClient = new OpenUrlClient(&view);
    view.engine()->rootContext()->setContextProperty(QLatin1String("openUrlClient"), openUrlClient);

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    view.show();

    return app.exec();
}
