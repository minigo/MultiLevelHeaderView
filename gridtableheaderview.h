#ifndef GRIDTABLEHEADERVIEW_H
#define GRIDTABLEHEADERVIEW_H

#include <QHeaderView>

//!
//! \brief The GridTableHeaderView class
//!
class GridTableHeaderView : public QHeaderView
{
    Q_OBJECT

public:
    GridTableHeaderView (Qt::Orientation orientation, int rows, int columns, QWidget *parent = nullptr);
    virtual ~GridTableHeaderView ();

    void setCellLabel (int row, int column, const QString &label);
    void setCellBackgroundColor (int row, int column, const QColor &color);
    void setCellForegroundColor (int row, int column, const QColor &color);

    QModelIndex indexAt (const QPoint &pos) const override;
    void paintSection (QPainter *painter, const QRect &rect, int logicalIndex) const override;
    QSize sectionSizeFromContents (int logicalIndex) const override;

    void setRowHeight (int row, int height);
    void setColumnWidth (int col, int width);

    void setSpan (int row, int column, int rowSpanCount, int columnSpanCount);
    void setSpan (int row, int column);

    QModelIndex columnSpanIndex (const QModelIndex& index) const;
    QModelIndex rowSpanIndex (const QModelIndex& index) const;

    int columnSpanSize (int row, int from, int spanCount) const;
    int rowSpanSize (int column, int from, int spanCount) const;
    int getSectionRange (QModelIndex& index, int* beginSection, int* endSection) const;

protected:
    void mousePressEvent (QMouseEvent *event) override;

protected slots:
    void slotSectionResized (int logicalIndex, int oldSize, int newSize);

signals:
    void sectionPressed (int from, int to);
};

#endif // GRIDTABLEHEADERVIEW_H
