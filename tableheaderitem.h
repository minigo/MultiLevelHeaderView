#ifndef TABLEHEADERITEM_H
#define TABLEHEADERITEM_H

#include <QHash>
#include <QPair>
#include <QVariant>

class TableHeaderItem
{
public:
    TableHeaderItem (TableHeaderItem *parent = nullptr);
    TableHeaderItem (int row, int column, TableHeaderItem *parent = nullptr);

    TableHeaderItem *insertChild (int row, int col);
    TableHeaderItem *child (int row, int col);

    TableHeaderItem *parent ();

    int row () const;
    int column () const;

    void setData (const QVariant &data, int role);
    QVariant data (int role) const;

    void clear ();

private:
    TableHeaderItem *_parentItem {nullptr};
    int _row;
    int _column;

    QHash<QPair<int,int>, TableHeaderItem*> _childItems;
    QHash<int,QVariant> _itemData;
};

#endif // TABLEHEADERITEM_H
