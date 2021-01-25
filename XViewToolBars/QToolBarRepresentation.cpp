//
// Created by xyh on 2021/1/24.
//

#include <iostream>
#include "QToolBarRepresentation.h"

QToolBarRepresentation::QToolBarRepresentation(QWidget* parent) {
    this->p=parent;
    rep.get().setParent(this);
    this->addWidget(&rep.get());
    this->setParent(parent);
    connect(&rep.get(),QOverload<int>::of(&QComboBox::currentIndexChanged),[&](int index){
        repMode=index;
        emit repModeChanged();
    });
}

int QToolBarRepresentation::getRepMode() const {
    return repMode;
}

