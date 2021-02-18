//
// Created by xyh on 2021/2/9.
//


#include <vtkCamera.h>
#include "XActionViewSetRotateCCW.h"
#include "../XDataModelHandle.h"
XActionViewSetRotateCCW::XActionViewSetRotateCCW(QObject *parent) {
    setParent(parent);
    auto icon=new QIcon("../resources/icons/ViewSetRotateCCWBlue.svg");
    setIcon(*icon);
    setStatusTip("RotateCCW");
    connect(this,&QAction::triggered,[](){
        auto& dh=XDataModelHandle::GetInstance();
        auto renderer = dh.getActiveRenderer();
        renderer->GetActiveCamera()->Roll(90);
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}
