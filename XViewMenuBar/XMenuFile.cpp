//
// Created by xyh on 2021/1/24.
//

#include "XMenuFile.h"

XMenuFile::XMenuFile() {
    menu.setTitle("File");
    QAction *aOpen=new QAction("Open",this);
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
    auto xDataModel=new XDataModel;
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
            auto item=new QStandardItem();
            item->setText(filePath.mid(filePath.lastIndexOf('/')+1,filePath.lastIndexOf('.')-filePath.lastIndexOf('/')-1));
            item->setCheckState(Qt::Checked);
            dh.mXTreeView->mStandardItemModel.appendRow(item);
            xDataModel->setStandardItem(item);
            dh.mXDataModelList.emplace_back(xDataModel);
            dh.miActiveDataModel=dh.mXDataModelList.size()-1;
            dh.viewUpdate();
        }
    }
}
