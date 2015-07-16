#include <jni.h>
#include <QVariant>

#include "openurlclient.h"

OpenUrlClient* OpenUrlClient::m_instance = NULL;

OpenUrlClient::OpenUrlClient(QObject *parent, QObject *root)
    : QObject(parent)
{
    // using signal slot approach
    //connect(this, SIGNAL(urlSelected(QString)), this, SLOT(setUrl(QString)));
    m_instance = this;
    m_root = root;
}

OpenUrlClient* OpenUrlClient::getInstance()
{
    if (!m_instance)
        m_instance = new OpenUrlClient;
    return m_instance;
}

void OpenUrlClient::setUrl(const QString &url)
{
    if (m_url == url)
        return;
    QObject *urlText = m_root->findChild<QObject*>("urlText");
    if (urlText)
        urlText->setProperty("text", "You clicked on: " + url);
    m_url = url;
}

QString OpenUrlClient::url() const
{
    return m_url;
}

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
  Java_poc_intent_OpenUrlClient_setUrl(JNIEnv *env,
                                        jobject obj,
                                        jstring url)
{
    const char *urlStr = env->GetStringUTFChars(url, NULL);
    // using signal slot approach
    //emit OpenUrlClient::getInstance()->urlSelected(urlStr);

    // using instance
    OpenUrlClient::getInstance()->setUrl(urlStr);
    env->ReleaseStringUTFChars(url, urlStr);
    return;
}

#ifdef __cplusplus
}
#endif
