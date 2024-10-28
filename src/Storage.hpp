#pragma once
#include "ToDoItems.hpp"
#include <QString>
#include <QList>

class Storage {
public:
    QList<QString> m_todos;
    Storage() : m_todos({"Thing 1", "Thing 2"}) {}
};

class StorageModel {
public:
    StorageModel(Storage &storage, ToDoItems &modelView) {
        for (const auto &todo : storage.m_todos) {
            modelView.append(todo);
        }
    }
};
