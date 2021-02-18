//
// Created by xyh on 2021/2/8.
//

#include <vtkCamera.h>
#include "XActionViewSetRotateCW.h"
#include "../XDataModelHandle.h"
XActionViewSetRotateCW::XActionViewSetRotateCW(QObject *parent) {
    setParent(parent);
    auto icon=new QIcon("../resources/icons/ViewSetRotateCWBlue.svg");
    setIcon(*icon);
    setStatusTip("RotateCW");
    connect(this,&QAction::triggered,[](){
        auto& dh=XDataModelHandle::GetInstance();
        auto renderer = dh.getActiveRenderer();
        renderer->GetActiveCamera()->Roll(-90);
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}