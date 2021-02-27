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

    ui->centralView->setRenderWindow(dh.getActiveRenderWindow());
    dh.mRenderWindowInteractList.emplace_back(dynamic_cast<vtkGenericRenderWindowInteractor*>(ui->centralView->renderWindow()->GetInteractor()));
    dh.addAxes();
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