//
// Created by xyh on 2021/1/24.
//

#include "QActionRepresentation.h"

QComboBox &QActionRepresentation::get() {
    return comboBox;
}

QActionRepresentation::QActionRepresentation() {
    comboBoxItem<<"Points"<<"Outline"<<"Surface"<<"Surface With Edges"<<"WireFrame";
    comboBox.addItems(comboBoxItem);
    comboBox.setCurrentIndex(2);
}
