//
// Created by xyh on 2021/2/8.
//

#include <vtkCamera.h>
#include "XActionViewSetRear.h"
#include "../XDataModelHandle.h"
XActionViewSetRear::XActionViewSetRear(QObject *parent) {
    setParent(parent);
    auto icon=new QIcon("../resources/icons/ViewSetRearBlue.svg");
    setIcon(*icon);
    setStatusTip("后视图");
    connect(this,&QAction::triggered,[](){
        auto& dh=XDataModelHandle::GetInstance();
        auto renderer = dh.getActiveRenderer();
        auto camera = renderer->GetActiveCamera();
        camera->SetPosition(0,0,0);
        camera->SetViewUp(0,1,0);
        camera->SetFocalPoint(0,0,1);
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}