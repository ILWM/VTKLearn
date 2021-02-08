//
// Created by xyh on 2021/2/8.
//

#ifndef VTKLEARN_XACTIONVIEWSETMAIN_H
#define VTKLEARN_XACTIONVIEWSETMAIN_H

#include <QAction>
#include <QIcon>
class XActionViewSetMain final : public QAction{
public:
    XActionViewSetMain(QObject *parent = nullptr);
    ~XActionViewSetMain() =default;
};


#endif //VTKLEARN_XACTIONVIEWSETMAIN_H
