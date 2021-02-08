//
// Created by xyh on 2021/2/8.
//

#ifndef VTKLEARN_XACTIONVIEWSETRESET_H
#define VTKLEARN_XACTIONVIEWSETRESET_H
#include <QAction>
#include <QIcon>
class XActionViewSetReset final : public QAction{
public:
    XActionViewSetReset(QObject *parent = nullptr);
    ~XActionViewSetReset() =default;
};


#endif //VTKLEARN_XACTIONVIEWSETRESET_H
