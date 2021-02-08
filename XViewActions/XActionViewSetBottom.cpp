//
// Created by xyh on 2021/2/8.
//

#include <vtkCamera.h>
#include "XActionViewSetBottom.h"
#include "../XDataModelHandle.h"
XActionViewSetBottom::XActionViewSetBottom(QObject *parent) {
    setParent(parent);
    auto icon=new QIcon("../resources/icons/ViewSetBottomBlue.svg");
    setIcon(*icon);
    setStatusTip("仰视图");
    connect(this,&QAction::triggered,[](){
        auto& dh=XDataModelHandle::GetInstance();
        auto renderer = dh.getActiveRenderer();
        auto camera = renderer->GetActiveCamera();
        camera->SetPosition(0,0,0);
        camera->SetViewUp(0,0,1);
        camera->SetFocalPoint(0,1,0);
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}