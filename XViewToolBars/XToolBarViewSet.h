//
// Created by xyh on 2021/2/8.
//

#ifndef VTKLEARN_XTOOLBARVIEWSET_H
#define VTKLEARN_XTOOLBARVIEWSET_H

#include <QToolBar>
#include "XActionViewSetMain.h"
#include "XActionViewSetRear.h"
#include "XActionViewSetRight.h"
#include "XActionViewSetLeft.h"
#include "XActionViewSetTop.h"
#include "XActionViewSetBottom.h"
#include "XActionViewSetReset.h"
#include "XActionViewSetRotateCW.h"
#include "XActionViewSetRotateCCW.h"
class XToolBarViewSet final: public QToolBar{
Q_OBJECT
public:
    explicit XToolBarViewSet(QWidget* parent= nullptr);
    ~XToolBarViewSet() final =default;

public:
    XActionViewSetReset mXActionViewSetReset;
    XActionViewSetMain mXActionViewSetMain;
    XActionViewSetRear mXActionViewSetRear;
    XActionViewSetRight mXActionViewSetRight;
    XActionViewSetLeft mXActionViewSetLeft;
    XActionViewSetTop mXActionViewSetTop;
    XActionViewSetBottom mXActionViewSetBottom;
    XActionViewSetRotateCW mXActionViewSetRotateCw;
    XActionViewSetRotateCCW mXActionViewSetRotateCCw;
};


#endif //VTKLEARN_XTOOLBARVIEWSET_H
