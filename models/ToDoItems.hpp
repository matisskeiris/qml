#pragma once
#include "ToDoItem.hpp"
#include <QScopedPointer>
#include <QAbstractListModel>
#include <QList>

class ToDoItems : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT

public:
    enum ItemRoles { Item, ItemId, Name };

    ToDoItems(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void append(const QString &name);
    Q_INVOKABLE void remove(int row);

private:
    QList<ToDoItem*> m_items;
};
