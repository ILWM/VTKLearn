//
// Created by xyh on 2021/2/8.
//

#include <vtkCamera.h>
#include "XActionViewSetLeft.h"
#include "../XDataModelHandle.h"
XActionViewSetLeft::XActionViewSetLeft(QObject *parent) {
    setParent(parent);
    auto icon=new QIcon("../resources/icons/ViewSetLeftBlue.svg");
    setIcon(*icon);
    setStatusTip("左视图");
    connect(this,&QAction::triggered,[](){
        auto& dh=XDataModelHandle::GetInstance();
        auto renderer = dh.getActiveRenderer();
        auto camera = renderer->GetActiveCamera();
        camera->SetPosition(0,0,0);
        camera->SetViewUp(0,1,0);
        camera->SetFocalPoint(1,0,0);
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}