//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_XMENUBAR_H
#define VTKLEARN_XMENUBAR_H

#include <QMenuBar>
#include "XMenuFile.h"
#include "XMenuFilter.h"
class XMenuBar final : public QMenuBar {
public:
    explicit XMenuBar(QWidget* parent= nullptr);
    ~XMenuBar() final =default;
public:
    XMenuFile menuFile;
    XMenuFilter menuFilter;
};


#endif //VTKLEARN_XMENUBAR_H
