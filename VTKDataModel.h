//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_VTKDATAMODEL_H
#define VTKLEARN_VTKDATAMODEL_H

#include <string>
#include <vtkDataSetReader.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkOutlineFilter.h>
#include <vtkNew.h>

class VTKDataModel {
public:
    enum REP_TYPE{
        Points,
        Outline,
        Surface,
        SurfaceWithEdges,
        WireFrame
    };
    VTKDataModel()=default;
    ~VTKDataModel()=default;
    void readVTKFile(const std::string& filePath) const;
    vtkSmartPointer<vtkActor> getActor() const;
    void setRepType(REP_TYPE type) const;

private:
    vtkNew<vtkDataSetReader> mDatasetReader;
    vtkNew<vtkDataSetMapper> mDatasetMapper;
    vtkNew<vtkActor> mActor;
    vtkNew<vtkDataSetMapper> mDatasetOutlineMapper;
    vtkNew<vtkOutlineFilter> mOutlineFilter;
    vtkNew<vtkActor> mOutLineActor;
};


#endif //VTKLEARN_VTKDATAMODEL_H
