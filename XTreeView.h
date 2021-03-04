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
    void updateTreeNodes();
public:
    QStandardItemModel mStandardItemModel;
    // hide: not active  show: active
    bool checkFlag{false};
};


#endif //VTKLEARN_XTREEVIEW_H
