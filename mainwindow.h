//
// Created by xyh on 2021/1/22.
//

#ifndef VTKLEARN_MAINWINDOW_H
#define VTKLEARN_MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QToolBar>
#include <QComboBox>
#include <QWidgetAction>

#include <vtkNew.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkDataSetReader.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>

#include "QToolBarRepresentation.h"
#include "VTKDataModel.h"
#include "XViewMenuBar/XViewQMenuBar.h"

#ifdef Debug
#define mLog(...) std::cout<<"mLog: "<<__VA_ARGS__<<" "<<__FILE__<<":"<<__LINE__<<std::endl;
#else
#define mLog(...)
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;
    void importFile();
    int readVtkFile(const QString& filePath);

    void toolBarRepAction();

private:
    Ui::mainwindow *ui;
    QString mFilePath;
    QString mFileFolder;
    QString mFilePathWithoutSuffix;

    int mVtkDataModelListCurIndex{0};
    std::vector<VTKDataModel*> mVtkDataModelList;
    int mRendererListCurIndex{0};
    std::vector<vtkSmartPointer<vtkRenderer>> mRendererList;
    vtkNew<vtkGenericOpenGLRenderWindow> mRenderWindow;

    // menubar
    //XViewQMenuBar *mMenuBar;
    // toolbars
    //QToolBarRepresentation *mToolBarRep;
};

#endif //VTKLEARN_MAINWINDOW_H
