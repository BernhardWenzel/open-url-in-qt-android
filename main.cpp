#include <QtGui>
#include <QtQuick>

#include "openurlclient.h"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    QObject *rootObject = view.rootObject();
    rootObject->setProperty("text1Text",QVariant("Open an url with schema pocintent://..."));
    OpenUrlClient *openUrlClient = new OpenUrlClient(&view, rootObject);
    view.engine()->rootContext()->setContextProperty(QLatin1String("openUrlClient"), openUrlClient);

    view.show();

    return app.exec();
}
