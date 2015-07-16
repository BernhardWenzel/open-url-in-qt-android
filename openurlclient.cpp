#include <jni.h>
#include "openurlclient.h"

OpenUrlClient* OpenUrlClient::m_instance = NULL;

OpenUrlClient::OpenUrlClient(QObject *parent)
    : QObject(parent)
{
    connect(this, SIGNAL(urlSelected(QString)), this, SLOT(setUrl(QString)));
    m_instance = this;
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
    //emit OpenUrlClient::getInstance()->urlSelected(urlStr);
    OpenUrlClient::getInstance()->setUrl(urlStr);

    env->ReleaseStringUTFChars(url, urlStr);
    return;
}

#ifdef __cplusplus
}
#endif
