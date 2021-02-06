//
// Created by xyh on 2021/2/2.
//

#ifndef VTKLEARN_XDATAMODELHANDLE_H
#define VTKLEARN_XDATAMODELHANDLE_H
#include <QObject>
#include <vector>
#include "XDataModel.h"
#include "XTreeView.h"
#include "XViewMenuBar/XMenuBar.h"
#include "XViewToolBars/XToolBarRepresentation.h"
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
    static XDataModelHandle& GetInstance(){
        static XDataModelHandle instance;
        return instance;
    }
    XDataModel* getActiveXDataModel(){
        return mXDataModelList[miActiveDataModelIndex];
    };
    void setActiveDataModelIndex(int index){
        miActiveDataModelIndex=index;
    }
    std::vector<XDataModel*>& getDataModelList(){
        return mXDataModelList;
    }
    void setViewUpdateCallback(long* p, ViewUpdateFunc pFunc){
        pView=p;
        pViewFunc=pFunc;
    }
    void viewUpdate(ViewUpdateFlag flag){
        pViewFunc(pView,flag);
    }
private:
    XDataModelHandle(){
        mXTreeView=new XTreeView;
        mMenuBar=new XMenuBar();
        mToolBarRep=new XToolBarRepresentation();
    };
public:
    int miActiveDataModelIndex{0};
    std::vector<XDataModel*> mXDataModelList;
    XTreeView *mXTreeView;

    // menubar
    XMenuBar *mMenuBar;
    // toolbars
    XToolBarRepresentation *mToolBarRep;

    // fot main window update
    long* pView;
    ViewUpdateFunc pViewFunc;
};


#endif //VTKLEARN_XDATAMODELHANDLE_H
