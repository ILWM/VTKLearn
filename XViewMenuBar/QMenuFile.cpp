//
// Created by xyh on 2021/1/24.
//

#include "QMenuFile.h"

QMenuFile::QMenuFile() {
    menu.setTitle("File");
    menu.addAction("Open");
}

QMenu &QMenuFile::get() {
    return menu;
}
