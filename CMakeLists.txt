cmake_minimum_required(VERSION 3.17)
project(VTKLearn)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "/home/xyh/Qt/5.15.2/gcc_64/lib/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(/usr/local/vtk-9.0.1/include/vtk-9.0)
include_directories(/home/xyh/MyLIBS/VTK-9.0.1/Build/lib)

include_directories(XViewToolBars)
include_directories(XViewActions)
include_directories(../)

add_executable(${PROJECT_NAME} main.cpp mainwindow.cpp mainwindow.h mainwindow.ui XViewActions/QActionRepresentation.cpp XViewActions/QActionRepresentation.h XViewToolBars/QToolBarRepresentation.cpp XViewToolBars/QToolBarRepresentation.h VTKDataModel.cpp VTKDataModel.h XViewMenuBar/XViewQMenuBar.cpp XViewMenuBar/XViewQMenuBar.h XViewMenuBar/QMenuFile.cpp XViewMenuBar/QMenuFile.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

file(GLOB_RECURSE VTKSO_LIST /home/xyh/MyLIBS/VTK-9.0.1/Build/lib/libvtk*.so)
foreach(it ${VTKSO_LIST})
    message(${it})
    target_link_libraries(${PROJECT_NAME} ${it})
endforeach()