//
// Created by xyh on 2021/2/8.
//

#ifndef VTKLEARN_XACTIONVIEWSETREAR_H
#define VTKLEARN_XACTIONVIEWSETREAR_H

#include <QAction>
#include <QIcon>
class XActionViewSetRear final : public QAction{
public:
    XActionViewSetRear(QObject *parent = nullptr);
    ~XActionViewSetRear() =default;
};


#endif //VTKLEARN_XACTIONVIEWSETREAR_H
