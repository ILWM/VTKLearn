//
// Created by xyh on 2021/2/8.
//

#include "XToolBarViewSet.h"

XToolBarViewSet::XToolBarViewSet(QWidget *parent) : QToolBar(parent) {
    mXActionViewSetMain.setParent(this);
    this->setParent(parent);
    this->addAction(&mXActionViewSetReset);
    this->addAction(&mXActionViewSetMain);
    this->addAction(&mXActionViewSetRear);
    this->addAction(&mXActionViewSetLeft);
    this->addAction(&mXActionViewSetRight);
    this->addAction(&mXActionViewSetTop);
    this->addAction(&mXActionViewSetBottom);
    this->addAction(&mXActionViewSetRotateCw);
    this->addAction(&mXActionViewSetRotateCCw);
}
