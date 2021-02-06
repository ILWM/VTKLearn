//
// Created by xyh on 2021/1/24.
//

#include "XMenuBar.h"

XMenuBar::XMenuBar(QWidget *parent) : QMenuBar(parent) {
    setParent(parent);
    addMenu(&menuFile.get());
}
