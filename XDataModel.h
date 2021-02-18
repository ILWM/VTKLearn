//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_XDATAMODEL_H
#define VTKLEARN_XDATAMODEL_H

#include <string>
#include <vtkDataSetReader.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkOutlineFilter.h>
#include <vtkNew.h>
#include <QStandardItem>

class XDataModel {
public:
    enum REP_TYPE{
        Points,
        Outline,
        Surface,
        SurfaceWithEdges,
        WireFrame
    };
    XDataModel()=default;
    ~XDataModel()=default;
    void readVTKFile(const std::string& filePath) const;
    vtkSmartPointer<vtkActor> getActor() const;
    void setRepType(REP_TYPE type);
    REP_TYPE getRepType() const;
    void addChildItem(XDataModel* child);
    QStandardItem* getStandardItem();
    void setStandardItem();
    void setDataName(QString str);
    void setVisibility(bool f){
        mbVisibility=f;
    }
    bool getVisibility(){
        return mbVisibility;
    }
private:
    REP_TYPE mRepType{REP_TYPE::Surface};
    vtkNew<vtkDataSetReader> mDatasetReader;
    vtkNew<vtkDataSetMapper> mDatasetMapper;
    vtkNew<vtkActor> mActor;
    vtkNew<vtkDataSetMapper> mDatasetOutlineMapper;
    vtkNew<vtkOutlineFilter> mOutlineFilter;
    vtkNew<vtkActor> mOutLineActor;
    QStandardItem* mStandardItem;
    bool mbIsChildItem{false};
    bool mbVisibility{true};
    QString mStrDataName;
    std::vector<XDataModel*> marrChildItem;
};


#endif //VTKLEARN_XDATAMODEL_H
