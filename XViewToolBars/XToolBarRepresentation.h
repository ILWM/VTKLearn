//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_XTOOLBARREPRESENTATION_H
#define VTKLEARN_XTOOLBARREPRESENTATION_H

#include <QToolBar>
#include "XActionRepresentation.h"
class XToolBarRepresentation final: public QToolBar{
    Q_OBJECT
public:
    explicit XToolBarRepresentation(QWidget* parent= nullptr);
    ~XToolBarRepresentation() final =default;
public:
    XActionRepresentation rep;
 };


#endif //VTKLEARN_XTOOLBARREPRESENTATION_H
