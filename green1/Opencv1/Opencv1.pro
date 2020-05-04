#-------------------------------------------------
#
# Project created by QtCreator 2020-04-21T14:17:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Opencv1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    self-writeup.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
INCLUDEPATH +=D:\qt\OpenCV\opencv_use\include_use\
              D:\qt\OpenCV\opencv_use\include_use\opencv\
              D:\qt\OpenCV\opencv_use\include_use\opencv2\
              D:\qt\OpenCV\opencv_use\include_use\arithmetic_headfiles\
              D:\qt\OpenCV\opencv_use\include_use\arithmetic_headfiles\C\
              D:\qt\OpenCV\opencv_use\include_use\arithmetic_headfiles\C++\
              D:\qt\OpenCV\opencv_use\include_use\melon_function\


LIBS +=D:\qt\OpenCV\opencv_use\lib\libopencv_core300.dll.a\
D:\qt\OpenCV\opencv_use\lib\libopencv_highgui300.dll.a\
D:\qt\OpenCV\opencv_use\lib\libopencv_imgcodecs300.dll.a\
D:\qt\OpenCV\opencv_use\lib\libopencv_imgproc300.dll.a\
