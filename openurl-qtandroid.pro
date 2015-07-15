QT += quick androidextras

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

SOURCES += \
    main.cpp \
    openurlclient.cpp

OTHER_FILES += \
    qml/main.qml \
    android-sources/src/poc/intent/OpenUrlClient.java \
    android-sources/AndroidManifest.xml

RESOURCES += \
    main.qrc

HEADERS += \
    openurlclient.h
