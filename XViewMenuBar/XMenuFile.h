//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_XMENUFILE_H
#define VTKLEARN_XMENUFILE_H

#include <QMenu>
#include <QFileDialog>
#include "../XDataModelHandle.h"
class XMenuFile :public QObject{
public:
    XMenuFile();
    ~XMenuFile()=default;
    QMenu& get();
public:
    QMenu menu;
private:
    void actionOpen();
};


#endif //VTKLEARN_XMENUFILE_H
