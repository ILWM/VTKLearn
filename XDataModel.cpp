//
// Created by xyh on 2021/1/24.
//

#include "XDataModel.h"

#include <utility>

void XDataModel::readVTKFile(const std::string& filePath) const {
    mDatasetReader->SetFileName(filePath.c_str());
    mDatasetMapper->SetInputConnection(mDatasetReader->GetOutputPort());
    mActor->SetMapper(mDatasetMapper);
    mActor->Modified();
}

vtkSmartPointer<vtkActor> XDataModel::getActor() const {
    return mActor;
}

void XDataModel::setRepType(XDataModel::REP_TYPE type){
    mRepType=type;
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

void XDataModel::setStandardItem() {
    auto item=new QStandardItem();
    item->setText(mStrDataName);
    item->setCheckable(true);
    item->setCheckState(Qt::Checked);
    item->setEditable(false);
    mStandardItem=item;
}

void XDataModel::setDataName(QString str) {
    mStrDataName=std::move(str);
}

QStandardItem *XDataModel::getStandardItem() {
    return mStandardItem;
}

XDataModel::REP_TYPE XDataModel::getRepType() const {
    return mRepType;
}

void XDataModel::addChildItem(XDataModel* child) {
    marrChildItem.emplace_back(child);
}
