/*
 #include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;

int main()
{
    //读取文件，首先创建一个Mat类，名字叫image，然后用imread读取图片
    Mat image=imread("f:/a.tif");

    if(image.empty()){
        printf("Could not load image...\n");
        return -1;
    }

    //创建图像显示窗口叫"My Image",WINDOW_NORMAL允许修改窗口大小，而WINDOW_AUTOSIZE根据图像大小自动确定窗口大小，不可修改
    namedWindow("My Image",CV_WINDOW_NORMAL);
    //利用imshow函数显示图片
    imshow("My Image",image);
    //等待直到用户相应，waitKey函数是等待函数，可以设定窗口显示的时间。若为0，则是等待用户相应。
    waitKey(0);
    //返回1
    return 0;
}
*/
