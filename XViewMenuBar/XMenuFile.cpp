//
// Created by xyh on 2021/1/24.
//

#include "XMenuFile.h"
#include "../XDataModelHandle.h"
XMenuFile::XMenuFile() {
    menu.setTitle("File");
    auto aOpen=new QAction("Open",this);
    menu.addAction(aOpen);
    connect(aOpen,&QAction::triggered, [&](){
        actionOpen();
    });
}

QMenu &XMenuFile::get() {
    return menu;
}

void XMenuFile::actionOpen() {
    auto& dh=XDataModelHandle::GetInstance();
    QString filePath;
    std::unique_ptr<XDataModel> xDataModel=std::make_unique<XDataModel>();
    QFileDialog dialog;
    dialog.setWindowTitle("Open File");
    dialog.setDirectory(".");
    dialog.setNameFilter(tr("VTK (*.vtk *.VTK)"));
    dialog.setViewMode(QFileDialog::Detail);
    if(dialog.exec()){
        filePath=dialog.selectedFiles().at(0);
    }
    if(""!=filePath) {
        if (filePath.endsWith("vtk") || filePath.endsWith("VTK")) {
            xDataModel->readVTKFile(filePath.toStdString());
            auto fileName = filePath.mid(filePath.lastIndexOf('/')+1,filePath.lastIndexOf('.')-filePath.lastIndexOf('/')-1);
            xDataModel->setDataName(fileName);


            //dh.mXTreeView->mStandardItemModel.appendRow(xDataModel->getStandardItem_());


            // select row
            //auto selectionModel = dh.mXTreeView->selectionModel();
            //selectionModel->clearSelection();
            //QModelIndex headModelIndex = dh.mXTreeView->model()->index(dh.mXDataModelList.size()+1, 0);
            //QModelIndex tailModelIndex = dh.mXTreeView->model()->index(dh.mXDataModelList.size()+1, dh.mXTreeView->model()->columnCount()-1);
            //QItemSelection itemSelection(headModelIndex, tailModelIndex);
            //selectionModel->select(itemSelection, QItemSelectionModel::SelectCurrent);
            // add data
            dh.mXDataModelList.emplace_back(std::move(xDataModel));
            dh.miActiveDataModelIndex= dh.mXDataModelList.size() - 1;
            // update representation state
            dh.mToolBarRep->rep.get().setEnabled(true);
            dh.mToolBarRep->rep.get().setCurrentIndex(dh.getActiveXDataModel()->getRepType());
            // view update
            dh.mXTreeView->updateTreeNodes();
            dh.viewUpdate(XDataModelHandle::Import);
        }
    }
}
