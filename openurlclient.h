#ifndef OPENURLCLIENT_H
#define OPENURLCLIENT_H

#include <QObject>

class OpenUrlClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlClicked)
public:
    explicit OpenUrlClient(QObject *parent = 0);

    void setUrl(const QString &url);
    QString url() const;

signals:
    void urlClicked();

private slots:
    void updateAndroidUrlClicked();

private:
    QString m_url;
};

#endif
