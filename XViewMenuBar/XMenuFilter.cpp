//
// Created by xyh on 2021/2/3.
//

#include "XMenuFilter.h"
#include "../XDataModelHandle.h"
XMenuFilter::XMenuFilter() {
    menu.setTitle("Filters");
    menuAlphabetical=menu.addMenu("Alphabetical");
    aAlphabeticalMeshQuality = new QAction("Mesh Quality",menuAlphabetical);
    aAlphabeticalMeshQuality->setEnabled(true);
    menuAlphabetical->addAction(aAlphabeticalMeshQuality);
    connect(aAlphabeticalMeshQuality,&QAction::triggered, [&](){
        actionAlphabeticalMeshQuality();
    });
}

void XMenuFilter::actionAlphabeticalMeshQuality() {
    auto& dh=XDataModelHandle::GetInstance();
    auto xDataModel=std::make_shared<XDataModel>();
    xDataModel->setDataName(QString::fromStdString("MeshQuality"+std::to_string(miAlphabeticalMeshQualityIndex++)));
    dh.mXTreeView->activeDataModel->addChildItem(std::move(xDataModel));
    dh.mXTreeView->updateTreeNodes();
    //dh.getActiveXDataModel()->getStandardItem()->appendRow(xDataModel->getStandardItem().get());
}

QMenu &XMenuFilter::get() {
    return menu;
}
