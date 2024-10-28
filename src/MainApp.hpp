#pragma once
#include "models/ApplicationModel.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQmlIntegration>

class MainApp : public QGuiApplication {
    Q_OBJECT

public:
    MainApp(int &argc, char **argv);

    QString name() const { return "MainApp"; }

private:
    QQmlApplicationEngine m_engine;
    ApplicationModel m_qmlBackend;
};
