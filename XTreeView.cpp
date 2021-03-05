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
    setStyle(QStyleFactory::create("windows"));
    setModel(&mStandardItemModel);
    initTree();

    connect(&mStandardItemModel,&QStandardItemModel::itemChanged,[&](QStandardItem* item){
        auto& dh=XDataModelHandle::GetInstance();
        int idx=1;
        for(auto&i : dh.getDataModelList()){
            if(reinterpret_cast<qlonglong>(i.get())== item->data(ITEM)){
                //disable not active, enable active cur_active_index
                if(i->getVisibility()){
                    checkFlag=true;
                }else{
                    auto selectionModel = dh.mXTreeView->selectionModel();
                    selectionModel->clearSelection();
                    QModelIndex headModelIndex = dh.mXTreeView->model()->index(idx, 0);
                    QModelIndex tailModelIndex = dh.mXTreeView->model()->index(idx, dh.mXTreeView->model()->columnCount()-1);
                    QItemSelection itemSelection(headModelIndex, tailModelIndex);
                    selectionModel->select(itemSelection, QItemSelectionModel::SelectCurrent);
                }
                i->setVisibility(!i->getVisibility());
                break;
            }
            idx++;
        }
        dh.viewUpdate(XDataModelHandle::DataMODIFY);
    });
    connect(this,&QTreeView::clicked,[&](const QModelIndex &index){
        if(checkFlag){
            checkFlag=false;
            return;
        }
        auto& dh=XDataModelHandle::GetInstance();
        dh.setActiveDataModelIndex(index.row()-1);
        dh.mToolBarRep->rep.get().setCurrentIndex(dh.getActiveXDataModel()->getRepType());
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}


void addChildNode(int& idx,std::shared_ptr<XDataModel>& data, std::unique_ptr<QStandardItem>& item){
    for(auto& ch:data->mArrChildItem){
        if(ch) {
            addChildNode(idx,ch, data->getStandardItem());
        }
    }
    item->appendRow(data->getStandardItem()->clone());
    //idx++;
}
void XTreeView::updateTreeNodes() {
    mStandardItemModel.clear();
    initTree();
    int idx=1;
    auto& dh=XDataModelHandle::GetInstance();
    for(auto& item:dh.mXDataModelList){
        for(auto& ch:item->mArrChildItem) {
            if(ch) {
                addChildNode(idx,ch, item->getStandardItem());
            }
        }
        mStandardItemModel.appendRow(item->getStandardItem()->clone());
        if(activeDataModel==item){
            //setSelectedRow(idx);
        }
        idx++;
    }
    expandAll();
}

void XTreeView::setSelectedRow(int row) {
    auto selectionModel = this->selectionModel();
    selectionModel->clearSelection();
    QModelIndex headModelIndex = this->model()->index(row, 0);
    QModelIndex tailModelIndex = this->model()->index(row, this->model()->columnCount()-1);
    QItemSelection itemSelection(headModelIndex, tailModelIndex);
    selectionModel->select(itemSelection, QItemSelectionModel::SelectCurrent);
}
