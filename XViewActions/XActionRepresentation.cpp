//
// Created by xyh on 2021/1/24.
//

#include "XActionRepresentation.h"
#include "../XDataModelHandle.h"
QComboBox &XActionRepresentation::get() {
    return comboBox;
}

XActionRepresentation::XActionRepresentation() {
    comboBoxItem<<"Points"<<"Outline"<<"Surface"<<"Surface With Edges"<<"WireFrame";
    comboBox.addItems(comboBoxItem);
    comboBox.setCurrentIndex(-1);
    comboBox.setEnabled(false);
    connect(&comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),[&](int index){
        auto& dh=XDataModelHandle::GetInstance();
        auto dataModel = dh.getActiveXDataModel().get();
        dataModel->setRepType(XDataModel::REP_TYPE(index));
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}
