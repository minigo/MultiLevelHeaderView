#ifndef GRIDTABLEHEADERMODEL_H
#define GRIDTABLEHEADERMODEL_H

#include "tableheaderitem.h"

#include <QAbstractTableModel>

//!
//! \brief The GridTableHeaderModel class
//!
class GridTableHeaderModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum HeaderRole
    {
        ColumnSpanRole = Qt::UserRole+1,
        RowSpanRole,
    };

    GridTableHeaderModel (int row, int column, QObject *parent = nullptr);
    virtual ~GridTableHeaderModel ();

    QModelIndex index (int row, int column, const QModelIndex &parent = QModelIndex ()) const override;
    int rowCount (const QModelIndex &parent = QModelIndex()) const override;
    int columnCount (const QModelIndex &parent = QModelIndex()) const override;
    Qt::ItemFlags flags (const QModelIndex &index) const override;

    QVariant data (const QModelIndex &index, int role) const override;
    bool setData (const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

private:
    int _row;
    int _column;
    TableHeaderItem *_rootItem {nullptr};
};

#endif // GRIDTABLEHEADERMODEL_H
