//
// Created by xyh on 2021/2/4.
//
#include <QStyleFactory>
#include "XTreeView.h"

XTreeView::XTreeView(QWidget *parent) : QTreeView(parent) {
    setParent(parent);
    // hide header
    //mStandardItemModel.setHorizontalHeaderLabels(QStringList()<<"builtin");
    setHeaderHidden(true);
    auto rootItem=new QStandardItem();
    rootItem->setText("builtin");
    rootItem->setCheckable(false);
    mStandardItemModel.appendRow(rootItem);
    setStyle(QStyleFactory::create("windows"));
    setModel(&mStandardItemModel);
}
