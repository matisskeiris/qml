#include "ToDoItem.hpp"

ToDoItem::ToDoItem(int itemId, const QString &name, QObject *parent)
    : QObject(parent), m_itemId(itemId), m_name(name) {}
ToDoItem::ToDoItem(QObject *parent) : QObject(parent) {}

int ToDoItem::itemId() const { return m_itemId; }
void ToDoItem::setItemId(int itemId) {
    if (itemId == m_itemId)
        return;
    m_itemId = itemId;
    emit itemIdChanged();
}

QString ToDoItem::name() const { return m_name; }
void ToDoItem::setName(const QString &name) {
    if (name == m_name)
        return;
    m_name = name;
    emit nameChanged();
}
