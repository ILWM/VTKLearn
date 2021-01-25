//
// Created by xyh on 2021/1/24.
//

#include "XViewQMenuBar.h"

XViewQMenuBar::XViewQMenuBar(QWidget *parent) : QMenuBar(parent) {
    setParent(parent);
    addMenu(&menuFile.get());
}
