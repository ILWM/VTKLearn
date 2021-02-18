//
// Created by xyh on 2021/2/3.
//

#ifndef VTKLEARN_XMENUFILTER_H
#define VTKLEARN_XMENUFILTER_H

#include <QAction>
#include <QMenu>

class XMenuFilter:public QObject {
public:
    XMenuFilter();
    QMenu& get();
    void updateFilterState();
private:
    QMenu menu;
    QMenu* menuAlphabetical;
    QAction* aAlphabeticalMeshQuality;
    int miAlphabeticalMeshQualityIndex{1};

    void actionAlphabeticalMeshQuality();
};


#endif //VTKLEARN_XMENUFILTER_H
