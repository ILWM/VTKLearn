//
// Created by xyh on 2021/1/24.
//

#include "VTKDataModel.h"

void VTKDataModel::readVTKFile(const std::string& filePath) const {
    mDatasetReader->SetFileName(filePath.c_str());
    mDatasetMapper->SetInputConnection(mDatasetReader->GetOutputPort());
    mActor->SetMapper(mDatasetMapper);
    mActor->Modified();
}

vtkSmartPointer<vtkActor> VTKDataModel::getActor() const {
    return mActor;
}

void VTKDataModel::setRepType(VTKDataModel::REP_TYPE type) const {
    switch (type) {
        case REP_TYPE::Points :
            mActor->GetProperty()->SetRepresentationToPoints();
            break;
        case REP_TYPE::Outline :
            mOutlineFilter->SetInputConnection(mDatasetReader->GetOutputPort());
            mDatasetOutlineMapper->SetInputConnection(mOutlineFilter->GetOutputPort());
            mOutLineActor->SetMapper(mDatasetOutlineMapper);
            break;
        case REP_TYPE::Surface :
            mActor->GetProperty()->SetRepresentationToSurface();
            mActor->GetProperty()->EdgeVisibilityOff();
            break;
        case REP_TYPE::SurfaceWithEdges :
            mActor->GetProperty()->EdgeVisibilityOn();
            mActor->GetProperty()->SetRepresentationToSurface();
            break;
        case REP_TYPE::WireFrame :
            mActor->GetProperty()->SetRepresentationToWireframe();
            break;
        default:
            mActor->GetProperty()->SetRepresentationToSurface();
            mActor->GetProperty()->EdgeVisibilityOn();
            break;
    }
    mActor->Modified();
}