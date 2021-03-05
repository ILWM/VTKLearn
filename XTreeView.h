//
// Created by xyh on 2021/2/4.
//

#ifndef VTKLEARN_XTREEVIEW_H
#define VTKLEARN_XTREEVIEW_H

#include <memory>
#include <QTreeView>
#include <QStandardItemModel>
#include "XDataModel.h"
class XTreeView:public QTreeView {
public:
    explicit XTreeView(QWidget *parent = nullptr);
    void updateTreeNodes();
    void setSelectedRow(int row);
private:
    void initTree(){
        auto rootItem=new QStandardItem();
        rootItem->setText("builtin");
        rootItem->setCheckable(false);
        auto rootItem1=new QStandardItem();
        rootItem1->setText("builtin1");
        rootItem1->setCheckable(false);
        rootItem->appendRow(rootItem1);
        auto rootItem2=new QStandardItem();
        for (int i = 0; i < rootItem->rowCount(); ++i) {
            rootItem2->appendRow(rootItem->child(i));
        }
        mStandardItemModel.appendRow(rootItem2);
    };
public:
    QStandardItemModel mStandardItemModel;
    // hide: not active  show: active
    bool checkFlag{false};
    std::shared_ptr<XDataModel> activeDataModel;
};


#endif //VTKLEARN_XTREEVIEW_H
