//
// Created by xyh on 2021/2/2.
//

#ifndef VTKLEARN_XDATAMODELHANDLE_H
#define VTKLEARN_XDATAMODELHANDLE_H
#include <QObject>
#include <vector>
#include "XDataModel.h"
typedef void (*ViewUpdateFunc)(long*,int);
class XDataModelHandle : QObject{
public:
    ~XDataModelHandle() override =default;
    XDataModelHandle(const XDataModelHandle&)=delete;
    XDataModelHandle& operator=(const XDataModelHandle&)=delete;
    static XDataModelHandle& GetInstance(){
        static XDataModelHandle instance;
        return instance;
    }
    XDataModel* getActiveXDataModel(){
        return mXDataModelList[miActiveDataModel];
    };
    void setViewUpdateCallback(long* p, ViewUpdateFunc pFunc){
        pView=p;
        pViewFunc=pFunc;
    }
    void viewUpdate(){
        pViewFunc(pView,0);
    }
private:
    XDataModelHandle(){

    };
public:
    int miActiveDataModel{0};
    std::vector<XDataModel*> mXDataModelList;
    long* pView;
    ViewUpdateFunc pViewFunc;
};


#endif //VTKLEARN_XDATAMODELHANDLE_H
