//
// Created by xyh on 2021/2/4.
//
#include <QStyleFactory>
#include "XTreeView.h"
#include "XDataModelHandle.h"
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

    connect(&mStandardItemModel,&QStandardItemModel::itemChanged,[](QStandardItem* item){
        auto& dh=XDataModelHandle::GetInstance();
        int index=0;
        for(auto&i : dh.getDataModelList()){
            if(i->getStandardItem()==item){
                dh.setActiveDataModelIndex(index);
                i->setVisibility(!i->getVisibility());
                break;
            }
            index++;
        }
        dh.viewUpdate(XDataModelHandle::DataMODIFY);
    });
    connect(this,&QTreeView::clicked,[&](const QModelIndex &index){
        auto& dh=XDataModelHandle::GetInstance();
        dh.setActiveDataModelIndex(index.row()-1);
        dh.mToolBarRep->rep.get().setCurrentIndex(dh.getActiveXDataModel()->getRepType());
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}
