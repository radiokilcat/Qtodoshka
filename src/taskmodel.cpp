#include "taskmodel.h"
#include "nlohmann/json.hpp"

Task first("покормить кота");
Task second("убить всех людей");

TaskModel::TaskModel(QObject *parent)
    : QAbstractListModel(parent),
      m_tasklist{first, second}
{

}

int TaskModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_tasklist.size();
}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto& s = m_tasklist.at(index.row());

    if (role == Qt::DisplayRole)
    {
        return QString::fromStdString(s.task_body);
    }
    return QVariant();

}

void TaskModel::createTask(const QString& name) {

    Task newTask {name.toStdString()};

    QAbstractListModel::beginInsertRows(QModelIndex(), m_tasklist.size(), m_tasklist.size());

    m_tasklist.push_back(std::move(newTask));

    QAbstractListModel::endInsertRows();
}
