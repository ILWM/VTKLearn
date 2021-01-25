//
// Created by xyh on 2021/1/24.
//

#include <iostream>
#include "XToolBarRepresentation.h"

XToolBarRepresentation::XToolBarRepresentation(QWidget* parent) {
    rep.get().setParent(this);
    this->addWidget(&rep.get());
    this->setParent(parent);
    //connect(&rep.get(),QOverload<int>::of(&QComboBox::currentIndexChanged),[&](int index){
    //    repMode=index;
    //    emit repModeChanged();
    //});
}

int XToolBarRepresentation::getRepMode() const {
    return repMode;
}

