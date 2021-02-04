//
// Created by xyh on 2021/1/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStyleFactory>
#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    ui->centralView->setRenderWindow(mRenderWindow);

    initWidget();


    XDataModelHandle::GetInstance().setViewUpdateCallback(reinterpret_cast<long *>(this), mainwindow::update);

    vtkSmartPointer<vtkRenderer> renderer=vtkSmartPointer<vtkRenderer>::New();
    mRendererList.emplace_back(renderer);
    miRendererListCurIndex=0;
    mRenderWindow->AddRenderer(renderer);

    /*
    auto model=new QStandardItemModel(ui->treeView);
    // hide header
    QTreeView *treeView=new QTreeView(this);
    //ui->treeView->setHeaderHidden(true);
    auto rootItem=new QStandardItem();
    rootItem->setText("builtin");
    rootItem->setCheckable(false);
    model->appendRow(rootItem);
    //ui->treeView->setModel(model);
    treeView->setModel(model);
    //ui->treeView->setStyle(QStyleFactory::create("windows"));
    treeView->setStyle(QStyleFactory::create("windows"));
    //ui->dockWidgetTree->setWidget(treeView);
     */

    /*
    auto *comboBox = new QComboBox(ui->toolBar);
    comboBox->addItems(comboBoxItem);
    auto *action = new QWidgetAction(ui->toolBar);
    action->setDefaultWidget(comboBox);
    ui->toolBar->addAction(action);
    */

}


void mainwindow::initWidget() {
    mMenuBar=new XViewQMenuBar(this);
    setMenuBar(mMenuBar);

    mToolBarRep=new XToolBarRepresentation(this);
    addToolBar(mToolBarRep);

    mTreeView=XDataModelHandle::GetInstance().mXTreeView;
    ui->dockWidgetTree->setWidget(mTreeView);
}

mainwindow::~mainwindow() {
    delete ui;
}