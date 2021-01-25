//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_XVIEWQMENUBAR_H
#define VTKLEARN_XVIEWQMENUBAR_H

#include <QMenuBar>
#include "QMenuFile.h"
class XViewQMenuBar final : public QMenuBar {
public:
    explicit XViewQMenuBar(QWidget* parent);
    ~XViewQMenuBar() final =default;
public:
    QMenuFile menuFile;
};


#endif //VTKLEARN_XVIEWQMENUBAR_H
