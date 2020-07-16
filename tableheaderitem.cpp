#include "tableheaderitem.h"

TableHeaderItem::TableHeaderItem (TableHeaderItem *parent) {
    TableHeaderItem (0, 0, parent);
}

TableHeaderItem::TableHeaderItem (int row, int column, TableHeaderItem *parent):
    _parentItem (parent), _row (row), _column (column)
{}

TableHeaderItem *TableHeaderItem::insertChild (int row, int col)
{
    TableHeaderItem *child = new TableHeaderItem (row, col, this);
    _childItems.insert (QPair<int, int> (row, col), child);
    return child;
}

TableHeaderItem *TableHeaderItem::child (int row, int col)
{
    QHash<QPair<int,int>,TableHeaderItem*>::iterator it = _childItems.find (QPair<int, int> (row, col));
    if (it != _childItems.end ())
        return it.value ();
    return nullptr;
}

TableHeaderItem *TableHeaderItem::parent () {
    return _parentItem;
}

int TableHeaderItem::row () const {
    return _row;
}

int TableHeaderItem::column () const {
    return _column;
}

void TableHeaderItem::setData (const QVariant &data, int role){
    _itemData.insert (role, data);
}

QVariant TableHeaderItem::data (int role) const
{
    QHash<int,QVariant>::const_iterator it = _itemData.find (role);
    if (it != _itemData.end ())
        return it.value ();
    return QVariant ();
}

void TableHeaderItem::clear ()
{
    for (TableHeaderItem* item: _childItems) {
        if (item) {
            item->clear ();
            delete item;
        }
    }
    _childItems.clear ();
}
