//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_QMENUFILE_H
#define VTKLEARN_QMENUFILE_H

#include <QMenu>
class QMenuFile {
public:
    QMenuFile();
    ~QMenuFile()=default;
    QMenu& get();
public:
    QMenu menu;
};


#endif //VTKLEARN_QMENUFILE_H
