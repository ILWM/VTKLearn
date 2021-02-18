//
// Created by xyh on 2021/2/3.
//

#include "XMenuFilter.h"
#include "../XDataModelHandle.h"
XMenuFilter::XMenuFilter() {
    menu.setTitle("Filters");
    menuAlphabetical=menu.addMenu("Alphabetical");
    aAlphabeticalMeshQuality = new QAction("Mesh Quality",menuAlphabetical);
    aAlphabeticalMeshQuality->setEnabled(false);
    menuAlphabetical->addAction(aAlphabeticalMeshQuality);
    connect(aAlphabeticalMeshQuality,&QAction::triggered, [&](){
        actionAlphabeticalMeshQuality();
    });
}

void XMenuFilter::actionAlphabeticalMeshQuality() {
    auto& dh=XDataModelHandle::GetInstance();
    auto xDataModel=new XDataModel;
    xDataModel->setDataName(QString::fromStdString("MeshQuality"+std::to_string(miAlphabeticalMeshQualityIndex++)));
    xDataModel->setStandardItem();
    //dh.getActiveXDataModel()->addChildItem(xDataModel);
    dh.getActiveXDataModel()->getStandardItem()->appendRow(xDataModel->getStandardItem());
}

QMenu &XMenuFilter::get() {
    return menu;
}
