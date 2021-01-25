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

    mMenuBar=new XViewQMenuBar(this);
    setMenuBar(mMenuBar);

    mToolBarRep=new XToolBarRepresentation(this);
    addToolBar(mToolBarRep);

    XDataModelHandle::GetInstance().setViewUpdateCallback(reinterpret_cast<long *>(this), mainwindow::update);

    vtkSmartPointer<vtkRenderer> renderer=vtkSmartPointer<vtkRenderer>::New();
    mRendererList.emplace_back(renderer);
    miRendererListCurIndex=0;
    mRenderWindow->AddRenderer(renderer);

    /*
    auto *comboBox = new QComboBox(ui->toolBar);
    comboBox->addItems(comboBoxItem);
    auto *action = new QWidgetAction(ui->toolBar);
    action->setDefaultWidget(comboBox);
    ui->toolBar->addAction(action);
    */

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::importFile() {

}

int mainwindow::readVtkFile(const QString& filePath) {
    auto* model=new XDataModel;
    model->readVTKFile(filePath.toStdString());
    mVtkDataModelList.push_back(model);
    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(mVtkDataModelList[miVtkDataModelListCurIndex]->getActor());
    mRendererList.emplace_back(renderer);
    mRenderWindow->AddRenderer(renderer);
    mRenderWindow->Render();
    return 0;
}

void mainwindow::toolBarRepAction() {
    mVtkDataModelList[miVtkDataModelListCurIndex]->setRepType(XDataModel::REP_TYPE(mToolBarRep->getRepMode()));
    mRenderWindow->Render();
}