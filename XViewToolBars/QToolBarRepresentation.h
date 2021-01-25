//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_QTOOLBARREPRESENTATION_H
#define VTKLEARN_QTOOLBARREPRESENTATION_H

#include <QToolBar>
#include "QActionRepresentation.h"
#include "../mainwindow.h"
class QToolBarRepresentation final: public QToolBar{
    Q_OBJECT
public:
    explicit QToolBarRepresentation(QWidget* parent);
    ~QToolBarRepresentation() final =default;
    int getRepMode() const;

signals:
    void repModeChanged();

private:
    mainwindow *p;
    QActionRepresentation rep;
    int repMode{2};
 };


#endif //VTKLEARN_QTOOLBARREPRESENTATION_H
