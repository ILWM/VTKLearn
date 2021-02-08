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
        auto camera = renderer->GetActiveCamera();
        double up[3]{0};
        camera->GetViewUp(up);
        if(up[0]==1){
            camera->SetViewUp(0,-1,0);
        }else if(up[0]==-1){
            camera->SetViewUp(0,1,0);
        }else if(up[1]==1){
            camera->SetViewUp(1,0,0);
        }else if(up[1]==-1){
            camera->SetViewUp(-1,0,0);
        }else if(up[2]==1){
            //camera->SetFocalPoint()
        }
        renderer->ResetCamera();
        dh.viewUpdate(XDataModelHandle::Pure);
    });
}
