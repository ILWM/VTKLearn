//
// Created by xyh on 2021/2/4.
//

#ifndef VTKLEARN_XTREEVIEW_H
#define VTKLEARN_XTREEVIEW_H

#include <QTreeView>
#include <QStandardItemModel>

class XTreeView:public QTreeView {
public:
    explicit XTreeView(QWidget *parent = nullptr);

public:
    QStandardItemModel mStandardItemModel;
};


#endif //VTKLEARN_XTREEVIEW_H
