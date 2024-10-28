#include "MainApp.hpp"
#include <QQmlContext>
#include "Storage.hpp"

MainApp::MainApp(int &argc, char **argv) : QGuiApplication(argc, argv) {
    QObject::connect(
        &m_engine, &QQmlApplicationEngine::objectCreationFailed, this, []() { exit(-1); }, Qt::QueuedConnection);

    m_engine.setInitialProperties({{"application", QVariant::fromValue(&m_qmlBackend)}});
    m_engine.loadFromModule("qml", "MainWindow");

    Storage storage;
    StorageModel storageModel(storage, *m_qmlBackend.items());
}
