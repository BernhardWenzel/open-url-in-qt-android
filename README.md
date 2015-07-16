# open-url-in-qt-android

Sample implementation to demonstrate how to launch a QT app on Android by clicking on a link that has a specific schema (`pocintent://`).

The important parts are:

## `poc.intent.OpenUrlClient` extends `QtActivity` 

* implements `onNewIntent(Intent intent)`  <http://developer.android.com/reference/android/app/Activity.html#onNewIntent(android.content.Intent)>

* JNI call to the C++ side of QT `public static native void setUrl(String url)`

## C++ implementation `openurlclient.cpp`

* implementation of the JNI call


		JNIEXPORT void JNICALL
		  Java_poc_intent_OpenUrlClient_setUrl(JNIEnv *env, jobject obj, jstring url)
		{
			const char *urlStr = env->GetStringUTFChars(url, NULL);
			OpenUrlClient::getInstance()->setUrl(urlStr);
			env->ReleaseStringUTFChars(url, urlStr);
			return;
		}


## `AndroidManifest.xml`

```xml
<activity ... android:name="poc.intent.OpenUrlClient" ... android:launchMode="singleTask">
...
<intent-filter>
			<action android:name="android.intent.action.VIEW"/>
			<category android:name="android.intent.category.DEFAULT"/>
			<category android:name="android.intent.category.BROWSABLE"/>
			<data android:scheme="pocintent" android:path="/"/>
</intent-filter>
```

* `android:name` pointing to our `QtActivity` implementation

* `launchMode=singleTask` as described in <http://developer.android.com/reference/android/R.styleable.html#AndroidManifestActivity_launchMode>

* `<intent-filter>` `Browsable` category (<http://developer.android.com/reference/android/content/Intent.html#CATEGORY_BROWSABLE>) and our specific schema `pocintent://`

