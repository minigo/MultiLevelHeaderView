#include "gridtableheaderview.h"
#include "gridtableheadermodel.h"
#include "gridtableview.h"

#include <QtCore/QDebug>
#include <QApplication>
#include <QStandardItemModel>
#include <QVBoxLayout>

void example1 ()
{
    QWidget w;
    w.setLayout(new QVBoxLayout);
    GridTableView view;
    w.layout ()->addWidget(&view);

    QStandardItemModel model;

    for (int i = 0; i < 9; i++)
    {
        QList<QStandardItem *> items;
        for (int j = 0; j < 9; j++)
            items.append (new QStandardItem (QString ("item(%1,%2)").arg (i).arg (j)));
        model.appendRow (items);
    }

    view.setModel (&model);

    view.setGridHeaderview (Qt::Horizontal, 2);
    view.setGridHeaderview (Qt::Vertical, 3);

    GridTableHeaderView *hHeader = view.gridHeaderview (Qt::Horizontal);
    GridTableHeaderView *vHeader = view.gridHeaderview (Qt::Vertical);

    if (hHeader) {
        hHeader->setSpan (0, 0, 2, 0);
        hHeader->setSpan (0, 1, 2, 0);
        hHeader->setSpan (0, 2, 2, 0);
        hHeader->setSpan (0, 3, 1, 2);
        hHeader->setSpan (0, 5, 2, 0);
        hHeader->setSpan (0, 6);

        hHeader->setCellLabel (0, 0, "cell1");
        hHeader->setCellLabel (0, 1, "cell2");
        hHeader->setCellLabel (0, 2, "cell3");
        hHeader->setCellLabel (0, 3, "cell4");
        hHeader->setCellLabel (1, 3, "cell5");
        hHeader->setCellLabel (1, 4, "cell6");
        hHeader->setCellLabel (0, 5, "cell7");

        hHeader->setCellBackgroundColor (0, 0, Qt::cyan);
        hHeader->setCellForegroundColor (0, 0, Qt::blue);
    }
    if (vHeader) {

        vHeader->setSpan (0, 0, 0, 3);
        vHeader->setSpan (1, 0, 3, 0);
        vHeader->setSpan (1, 1, 2, 0);
        vHeader->setSpan (4, 0, 0, 3);
        vHeader->setSpan (5, 0, 0, 3);
        vHeader->setSpan (6, 0);

        vHeader->setCellLabel (0, 0, "cell1");
        vHeader->setCellLabel (1, 0, "cell2");
        vHeader->setCellLabel (1, 1, "cell3");
        vHeader->setCellLabel (3, 1, "cell4");
        vHeader->setCellLabel (1, 2, "cell5");
        vHeader->setCellLabel (2, 2, "cell6");
        vHeader->setCellLabel (3, 2, "cell7");
        vHeader->setCellLabel (4, 0, "cell8");
        vHeader->setCellLabel (5, 0, "cell9");
    }
    w.show ();
}

void example2 ()
{
    QWidget w;
    w.setLayout (new QVBoxLayout);
    GridTableView view;
    w.layout ()->addWidget (&view);

    QStandardItemModel model;

    for (int i = 0; i < 9; i++)
    {
        QList<QStandardItem *> items;
        for (int j = 0; j < 9; j++)
            items.append (new QStandardItem (QString ("item(%1,%2)").arg (i).arg (j)));
        model.appendRow (items);
    }

    view.setModel (&model);

    view.setGridHeaderview (Qt::Horizontal, 2);
    //view.setGridHeaderview (Qt::Vertical, 3);

    GridTableHeaderView *hHeader = view.gridHeaderview (Qt::Horizontal);
    //GridTableHeaderView *vHeader = view.gridHeaderview (Qt::Vertical);

    if (hHeader) {
        hHeader->setSpan (0, 0, 2, 0);
        hHeader->setSpan (0, 1, 2, 0);
        hHeader->setSpan (0, 2, 2, 0);
        hHeader->setSpan (0, 3, 1, 2);
        hHeader->setSpan (0, 5, 2, 0);
        hHeader->setSpan (0, 6);

        hHeader->setCellLabel (0, 0, "cell1");
        hHeader->setCellLabel (0, 1, "cell2");
        hHeader->setCellLabel (0, 2, "cell3");
        hHeader->setCellLabel (0, 3, "cell4");
        hHeader->setCellLabel (1, 3, "cell5");
        hHeader->setCellLabel (1, 4, "cell6");
        hHeader->setCellLabel (0, 5, "cell7");

        hHeader->setCellBackgroundColor (0, 0, Qt::cyan);
        hHeader->setCellForegroundColor (0, 0, Qt::blue);
    }
    //    if (vHeader) {

    //        vHeader->setSpan (0, 0, 0, 3);
    //        vHeader->setSpan (1, 0, 3, 0);
    //        vHeader->setSpan (1, 1, 2, 0);
    //        vHeader->setSpan (4, 0, 0, 3);
    //        vHeader->setSpan (5, 0, 0, 3);
    //        vHeader->setSpan (6, 0);

    //        vHeader->setCellLabel (0, 0, "cell1");
    //        vHeader->setCellLabel (1, 0, "cell2");
    //        vHeader->setCellLabel (1, 1, "cell3");
    //        vHeader->setCellLabel (3, 1, "cell4");
    //        vHeader->setCellLabel (1, 2, "cell5");
    //        vHeader->setCellLabel (2, 2, "cell6");
    //        vHeader->setCellLabel (3, 2, "cell7");
    //        vHeader->setCellLabel (4, 0, "cell8");
    //        vHeader->setCellLabel (5, 0, "cell9");
    //    }
    w.show ();
}

int main (int argc, char *argv[])
{
    QApplication a (argc, argv);

    QWidget w;
    w.setLayout (new QVBoxLayout);
    GridTableView view;
    QTableView view1;
    w.layout ()->addWidget (&view);
    w.layout ()->addWidget (&view1);

    QStandardItemModel model (0, 4);

    for (int i = 0; i < 4; i++)
    {
        QList<QStandardItem *> items;
        for (int j = 0; j < 4; j++)
            items.append (new QStandardItem (QString ("item(%1,%2)").arg (i).arg (j)));
        model.appendRow (items);
    }

    view.setModel (&model);
    //view.setGridHeaderview (Qt::Horizontal, 2);
    //GridTableHeaderView *hHeader = view.gridHeaderview (Qt::Horizontal);

    GridTableHeaderView *hHeader = new GridTableHeaderView (Qt::Horizontal, 2, 4);
    hHeader->setRowHeight (0, 50);

    if (hHeader)
    {


        hHeader->setCellLabel (0, 0, "Header");
        hHeader->setCellLabel (0, 3, "Header");

        hHeader->setCellLabel (1, 0, "cell1");
        hHeader->setCellLabel (1, 1, "cell2");
        hHeader->setCellLabel (1, 2, "cell3");

        hHeader->setSpan (0, 0, 0, 3);
        //hHeader->setSpan (0, 3, 2, 0);
    }

    view.setHorizontalHeader (hHeader);

    view1.setModel (hHeader->model ());

    //qDebug () << hHeader->model ()->rowCount () << hHeader->model ()->columnCount ();
    //    GridTableHeaderModel *gthm = dynamic_cast<GridTableHeaderModel *> (hHeader->model ());

    //    {
    //        QModelIndex ind = gthm->index (0, 0);
    //        qDebug () << ind.data ();
    //        qDebug () << ind.data (Qt::SizeHintRole);
    //    }

    //    {
    //        QModelIndex ind = gthm->index (0, 1);
    //        qDebug () << ind.data ();
    //        qDebug () << ind.data (Qt::SizeHintRole);
    //    }

    //    {
    //        QModelIndex ind = gthm->index (1, 0);
    //        qDebug () << ind.data ();
    //        qDebug () << ind.data (Qt::SizeHintRole);
    //    }

    //    {
    //        QModelIndex ind = gthm->index (1, 3);
    //        qDebug () << ind.data ();
    //        qDebug () << ind.data (Qt::SizeHintRole);
    //    }

    w.show ();
    return a.exec ();
}
