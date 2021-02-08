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



    initWidget();
    auto& dh = XDataModelHandle::GetInstance();
    dh.setViewUpdateCallback(reinterpret_cast<long *>(this), mainwindow::update);

    //vtkSmartPointer<vtkRenderer> renderer=vtkSmartPointer<vtkRenderer>::New();
    //mRendererList.emplace_back(renderer);
    //miRendererListCurIndex=0;
    //mRenderWindow->AddRenderer(renderer);
    mRenderWindow=dh.getActiveRenderWindow();
    mRendererList=dh.mRendererList;
    ui->centralView->setRenderWindow(mRenderWindow);
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
    auto& dh = XDataModelHandle::GetInstance();
    dh.mMenuBar->setParent(this);
    setMenuBar(dh.mMenuBar);
    dh.mToolBarRep->setParent(this);
    addToolBar(dh.mToolBarRep);
    dh.mToolBarViewSet->setParent(this);
    addToolBar(dh.mToolBarViewSet);
    dh.mXTreeView->setParent(this);
    ui->dockWidgetTree->setWidget(dh.mXTreeView);
}

mainwindow::~mainwindow() {
    delete ui;
}