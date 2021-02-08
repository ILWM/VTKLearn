//
// Created by xyh on 2021/2/8.
//

#include "XActionViewSetReset.h"
#include "../XDataModelHandle.h"
XActionViewSetReset::XActionViewSetReset(QObject *parent) {
    setParent(parent);
    auto icon=new QIcon("../resources/icons/ViewSetResetBlue.svg");
    setIcon(*icon);
    setStatusTip("Reset");
    connect(this,&QAction::triggered,[](){
        auto& dh=XDataModelHandle::GetInstance();
        auto renderer = dh.getActiveRenderer();
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}