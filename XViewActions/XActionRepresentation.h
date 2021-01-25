//
// Created by xyh on 2021/1/24.
//

#ifndef VTKLEARN_XACTIONREPRESENTATION_H
#define VTKLEARN_XACTIONREPRESENTATION_H

#include <QStringList>
#include <QComboBox>
#include "../XDataModelHandle.h"
typedef void (*RepCallback)(long*);
class XActionRepresentation : public QObject{
public:
    XActionRepresentation();
    ~XActionRepresentation()=default;
    QComboBox& get();
private:
    QComboBox comboBox;
    QStringList comboBoxItem;
};


#endif //VTKLEARN_XACTIONREPRESENTATION_H
