#pragma once
#include <QObject>
#include <QtQmlIntegration>

class ToDoItem : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int itemId READ itemId WRITE setItemId NOTIFY itemIdChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

signals:
    void itemIdChanged();
    void nameChanged();

public:
    ToDoItem(int itemId, const QString &name, QObject *parent = nullptr);
    ToDoItem(QObject *parent = nullptr);

    int itemId() const;
    void setItemId(int itemId);

    QString name() const;
    void setName(const QString &name);

private:
    int m_itemId;
    QString m_name;
};
