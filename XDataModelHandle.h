//
// Created by xyh on 2021/2/2.
//

#ifndef VTKLEARN_XDATAMODELHANDLE_H
#define VTKLEARN_XDATAMODELHANDLE_H
#include <QObject>
#include <vector>
#include <memory>
#include <mutex>

#include <vtkGenericRenderWindowInteractor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkNamedColors.h>

#include "XDataModel.h"
#include "XTreeView.h"
#include "XViewMenuBar/XMenuBar.h"
#include "XViewToolBars/XToolBarRepresentation.h"
#include "XViewToolBars/XToolBarViewSet.h"

typedef void (*ViewUpdateFunc)(long*,int);
class XDataModelHandle : QObject{
public:
    enum ViewUpdateFlag{
        Pure,
        DataMODIFY,
        Import
    };
    ~XDataModelHandle() override =default;
    XDataModelHandle(const XDataModelHandle&)=delete;
    XDataModelHandle& operator=(const XDataModelHandle&)=delete;
    // 饿汉
    // static XDataModelHandle& GetInstance(){
    //     static XDataModelHandle instance;
    //     return instance;
    // }
    // 懒汉
    static XDataModelHandle& GetInstance(){
        static std::once_flag flag;
        std::call_once(flag,[&]{
            ptr.reset(new XDataModelHandle);
        });
        return *ptr;
    }
    std::unique_ptr<XDataModel>& getActiveXDataModel(){
        return mXDataModelList[miActiveDataModelIndex];
    };
    void setActiveDataModelIndex(int index){
        miActiveDataModelIndex=index;
    }

    vtkSmartPointer<vtkRenderer> getActiveRenderer(){
        return mRendererList[miActiveRendererIndex];
    };
    void setActiveRendererIndex(int index){
        miActiveRendererIndex=index;
    }

    vtkSmartPointer<vtkGenericOpenGLRenderWindow> getActiveRenderWindow(){
        return mRenderWindowList[miActiveRenderWindowIndex];
    };
    void setActiveRenderWindowIndex(int index){
        miActiveRenderWindowIndex=index;
    }

    std::vector<std::unique_ptr<XDataModel>>& getDataModelList(){
        return mXDataModelList;
    }
    void setViewUpdateCallback(long* p, ViewUpdateFunc pFunc){
        pView=p;
        pViewFunc=pFunc;
    }
    void viewUpdate(ViewUpdateFlag flag){
        pViewFunc(pView,flag);
    }
    void newRenderWindow(){
        vtkSmartPointer<vtkRenderer> renderer=vtkSmartPointer<vtkRenderer>::New();
        vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWin=vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
        renderWin->AddRenderer(renderer);
        mRendererList.emplace_back(renderer);
        mRenderWindowList.emplace_back(renderWin);
        miActiveRendererIndex=mRendererList.size()-1;
        miActiveRenderWindowIndex=mRenderWindowList.size()-1;

    }
    void addAxes(){
        auto axes=vtkSmartPointer<vtkAxesActor>::New();
        auto widget=vtkSmartPointer<vtkOrientationMarkerWidget>::New();
        vtkNew<vtkNamedColors> colors;
        double rgba[4]{0.0, 0.0, 0.0, 0.0};
        colors->GetColor("Carrot", rgba);
        widget->SetOutlineColor(rgba[0], rgba[1], rgba[2]);
        widget->SetOrientationMarker(axes);
        widget->SetInteractor(getActiveRenderWindow()->GetInteractor());
        widget->SetViewport(0.0, 0.0, 0.2, 0.2);
        widget->SetEnabled(1);
        widget->InteractiveOff();
        mAxesWidgetList.emplace_back(widget);
        mAxesList.emplace_back(axes);
    }
private:
    XDataModelHandle(){
        mXTreeView=new XTreeView;
        mMenuBar=new XMenuBar;
        mToolBarRep=new XToolBarRepresentation;
        mToolBarViewSet=new XToolBarViewSet;
        newRenderWindow();
    };
    static std::unique_ptr<XDataModelHandle> ptr;
public:
    int miActiveDataModelIndex{0};
    std::vector<std::unique_ptr<XDataModel>> mXDataModelList;
    int miActiveRendererIndex{0};
    std::vector<vtkSmartPointer<vtkRenderer>> mRendererList;
    int miActiveRenderWindowIndex{0};
    std::vector<vtkSmartPointer<vtkGenericOpenGLRenderWindow>> mRenderWindowList;
    int miActiveAxesIndex{0};
    std::vector<vtkSmartPointer<vtkAxesActor>> mAxesList;
    int miActiveAxesWidgetIndex{0};
    std::vector<vtkSmartPointer<vtkOrientationMarkerWidget>> mAxesWidgetList;
    int miActiveInteractIndex{0};
    std::vector<vtkSmartPointer<vtkGenericRenderWindowInteractor>> mRenderWindowInteractList;
    int miActiveViewIndex{0};
    std::vector<vtkSmartPointer<vtkOrientationMarkerWidget>> mViewList;



    // tree view
    XTreeView *mXTreeView;
    // menubar
    XMenuBar *mMenuBar;
    // toolbars
    XToolBarRepresentation *mToolBarRep;
    XToolBarViewSet *mToolBarViewSet;

    // fot main window update
    long* pView{};
    ViewUpdateFunc pViewFunc{};
};


#endif //VTKLEARN_XDATAMODELHANDLE_H
