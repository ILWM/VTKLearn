//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_QACTIONREPRESENTATION_H
#define VTKLEARN_QACTIONREPRESENTATION_H

#include <QStringList>
#include <QComboBox>
class QActionRepresentation {
public:
    QActionRepresentation();
    ~QActionRepresentation()=default;
    QComboBox& get();
private:
    QComboBox comboBox;
    QStringList comboBoxItem;
};


#endif //VTKLEARN_QACTIONREPRESENTATION_H
