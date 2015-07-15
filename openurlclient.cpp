#include "openurlclient.h"

#include <QtAndroidExtras/QAndroidJniObject>

OpenUrlClient::OpenUrlClient(QObject *parent)
    : QObject(parent)
{
    connect(this, SIGNAL(urlClicked()), this, SLOT(updateAndroidUrlClicked()));
}

void OpenUrlClient::setUrl(const QString &url)
{
    if (m_url == url)
        return;

    m_url = url;
    emit urlClicked();
}

QString OpenUrlClient::url() const
{
    return m_url;
}

void OpenUrlClient::updateAndroidUrlClicked()
{
    QAndroidJniObject javaUrl = QAndroidJniObject::fromString(m_url);
    QAndroidJniObject::callStaticMethod<void>("poc/intent/OpenUrlClient",
                                       "openUrl",
                                       "(Ljava/lang/String;)V",
                                       javaUrl.object<jstring>());
}
