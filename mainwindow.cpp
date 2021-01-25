//
// Created by xyh on 2021/1/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    ui->centralView->setRenderWindow(mRenderWindow);

    //mMenuBar=new XViewQMenuBar(this);
    //setMenuBar(mMenuBar);
//
    //mToolBarRep=new QToolBarRepresentation(this);
    //connect(mToolBarRep,&QToolBarRepresentation::repModeChanged,this,&mainwindow::toolBarRepAction);
    //addToolBar(mToolBarRep);
    /*
    auto *comboBox = new QComboBox(ui->toolBar);
    comboBox->addItems(comboBoxItem);
    auto *action = new QWidgetAction(ui->toolBar);
    action->setDefaultWidget(comboBox);
    ui->toolBar->addAction(action);
    */

    //connect(ui->actionOpen, &QAction::triggered,[this]{
    //    this->importFile();
    //});
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::importFile() {
    QFileDialog dialog;
    dialog.setWindowTitle("Open File");
    dialog.setDirectory("../../");
    dialog.setViewMode(QFileDialog::Detail);
    if(dialog.exec()){
        mFilePath=dialog.selectedFiles().at(0);
        mFileFolder=mFilePath.mid(0,mFilePath.lastIndexOf('/'));
        mFilePathWithoutSuffix=mFilePath.mid(0,mFilePath.lastIndexOf('.'));
    }
    if(""!=mFilePath) {
        if (mFilePath.endsWith("vtk") || mFilePath.endsWith("VTK")) {
            readVtkFile(mFilePath);
        }
    }
}

int mainwindow::readVtkFile(const QString& filePath) {
    auto* model=new VTKDataModel;
    model->readVTKFile(filePath.toStdString());
    mVtkDataModelList.push_back(model);
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(mVtkDataModelList[mVtkDataModelListCurIndex]->getActor());
    mRendererList.emplace_back(renderer);
    mRenderWindow->AddRenderer(renderer);
    mRenderWindow->Render();
    return 0;
}

void mainwindow::toolBarRepAction() {
    //mVtkDataModelList[mVtkDataModelListCurIndex]->setRepType(VTKDataModel::REP_TYPE(mToolBarRep->getRepMode()));
    //mRenderWindow->Render();
}