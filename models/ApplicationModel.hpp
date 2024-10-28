#pragma once
#include <QObject>
#include <QtQmlIntegration>
#include "ToDoItems.hpp"


class ApplicationModel : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Created on MainApplication initialization")

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(ToDoItems *items READ items CONSTANT)

private:
    ToDoItems m_items;

public:
    ApplicationModel(QObject *parent = nullptr) : QObject(parent) {}
    QString name() const { return "MainApp"; }
    ToDoItems* items() { return &m_items; }
};
