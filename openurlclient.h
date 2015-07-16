#ifndef OPENURLCLIENT_H
#define OPENURLCLIENT_H

#include <QObject>

class OpenUrlClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlSelected)
public:
    explicit OpenUrlClient(QObject *parent = 0);
    QString url() const;
    static OpenUrlClient* getInstance();

public slots:
    void setUrl(const QString &url);

signals:
    void urlSelected(const QString &url);

private:
    QString m_url;
    static OpenUrlClient* m_instance;
};

#endif
