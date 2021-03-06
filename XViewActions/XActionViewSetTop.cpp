//
// Created by xyh on 2021/2/8.
//

#include <vtkCamera.h>
#include "XActionViewSetTop.h"
#include "../XDataModelHandle.h"
XActionViewSetTop::XActionViewSetTop(QObject *parent) {
    setParent(parent);
    auto icon=new QIcon("../resources/icons/ViewSetTopBlue.svg");
    setIcon(*icon);
    setStatusTip("俯视图");
    connect(this,&QAction::triggered,[](){
        auto& dh=XDataModelHandle::GetInstance();
        auto renderer = dh.getActiveRenderer();
        auto camera = renderer->GetActiveCamera();
        camera->SetPosition(0,0,0);
        camera->SetViewUp(0,0,-1);
        camera->SetFocalPoint(0,-1,0);
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}