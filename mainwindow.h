//
// Created by xyh on 2021/1/22.
//

#ifndef VTKLEARN_MAINWINDOW_H
#define VTKLEARN_MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QToolBar>
#include <QComboBox>
#include <QWidgetAction>

#include <vtkNew.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkDataSetReader.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>

#include "XToolBarRepresentation.h"
#include "XDataModel.h"
#include "XViewMenuBar/XMenuBar.h"
#include "XDataModelHandle.h"
#include "XTreeView.h"

//#ifdef Debug
//#define mLog(...) std::cout<<"mLog: "<<__VA_ARGS__<<" "<<__FILE__<<":"<<__LINE__<<std::endl;
//#else
//#define mLog(...)
//#endif
//#include <iostream>

template<typename T>
void mLog(const T&){std::cout<<std::endl;}
template<typename T, typename... Types>
void mLog(const T& first, const Types&... args){
    std::cout<<first<<" ";
    mLog(args...);
}

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

    static void update(long* p, int f){
        auto flag = XDataModelHandle::ViewUpdateFlag(f);
        auto m = reinterpret_cast<mainwindow*>(p);
        auto& dh=XDataModelHandle::GetInstance();
        switch (flag) {
            case XDataModelHandle::ViewUpdateFlag::DataMODIFY:
                for(auto&item : dh.getDataModelList()){
                    if(item->getVisibility()){
                        m->mRendererList[m->miRendererListCurIndex]->AddActor(item->getActor());
                    }else{
                        m->mRendererList[m->miRendererListCurIndex]->RemoveActor(item->getActor());
                    };
                }
                m->mRendererList[m->miRendererListCurIndex]->ResetCameraClippingRange();
                m->mRenderWindow->Render();
                break;
            case XDataModelHandle::ViewUpdateFlag::Import:
                for(auto&item : dh.getDataModelList()){
                    if(item->getVisibility()){
                        m->mRendererList[m->miRendererListCurIndex]->AddActor(item->getActor());
                    }else{
                        m->mRendererList[m->miRendererListCurIndex]->RemoveActor(item->getActor());
                    };
                }
                m->mRendererList[m->miRendererListCurIndex]->ResetCamera();
                m->mRenderWindow->Render();
            case XDataModelHandle::ViewUpdateFlag::Pure :
            default:
                m->mRenderWindow->Render();
        }
    }

private:
    void initWidget();

private:
    Ui::mainwindow *ui;

    int miRendererListCurIndex{0};
    std::vector<vtkSmartPointer<vtkRenderer>> mRendererList;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;

};

#endif //VTKLEARN_MAINWINDOW_H
