#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <vector>

struct Task {
    Task(const std::string& name)
        : task_body(name)
    {};
    std::string task_body;
};

class TaskModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TaskModel(QObject *parent = nullptr);

//    Q_INVOKABLE Task* getTask( int index );

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
//    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) final override;
    int rowCount(const QModelIndex& _parent = QModelIndex()) const final override;
//    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) final override;
//    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) final override;
    Q_INVOKABLE void createTask(const QString& name);

private:
    std::vector<Task> m_tasklist;
};
