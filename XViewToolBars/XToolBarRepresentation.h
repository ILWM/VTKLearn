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
    explicit XToolBarRepresentation(QWidget* parent);
    ~XToolBarRepresentation() final =default;
    int getRepMode() const;

signals:
    void repModeChanged();

private:
    XActionRepresentation rep;
    int repMode{2};
 };


#endif //VTKLEARN_XTOOLBARREPRESENTATION_H
