#include "ToDoItems.hpp"

ToDoItems::ToDoItems(QObject *parent) : QAbstractListModel(parent) {}

int ToDoItems::rowCount(const QModelIndex &parent) const { return m_items.count(); }

QVariant ToDoItems::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= rowCount()) return QVariant();

    auto *item = m_items[index.row()];
    switch (role) {
        case Item: return QVariant::fromValue(item);
        case ItemId: return QVariant::fromValue(item->itemId());
        case Name: return QVariant::fromValue(item->name());
    };

    return QVariant();
}

void ToDoItems::append(const QString &name) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append(new ToDoItem(0, name));
    endInsertRows();
}
void ToDoItems::remove(int row) {
    if (row < 0 || row >= rowCount()) return;
    beginRemoveRows(QModelIndex(), row, row);
    // TODO: delete item
    m_items.removeAt(row);
    endRemoveRows();
}

QHash<int, QByteArray> ToDoItems::roleNames() const {
    return {
        { Item, "item" },
        { ItemId, "itemId" },
        { Name, "name" },
    };
}

