#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//Mat bgimg;//global variable makes it easier to transfer parameters, that I do not have to specify Mat& bgimg in function
//Content: Shape and text; Histogram equalization; Zooming and Shrinking images by bilinear interpolation, and hierachy;
void My_line(Mat& bgimg);
void My_shape(Mat& bgimg);
void Random_line(Mat& bgimg);
void My_shrink_image_bilinear(Mat& img, int dpi_dst);

int main(int argc, char *argv[])
{
//    Mat bgimg = imread("f:/qt/lena_std.tif");
//    namedWindow("Background image",CV_WINDOW_AUTOSIZE);
//    imshow("Background image",bgimg);
//// 1. Draw shapes and text: https://docs.opencv.org/2.4/doc/tutorials/core/random_generator_and_text/random_generator_and_text.html
//    My_line(bgimg);
//    My_shape(bgimg);
//    putText(bgimg, "Hello OpenCV",Point(200,200),CV_FONT_HERSHEY_COMPLEX,1.0,Scalar(150,200,100),1,LINE_8);
//    Random_line(bgimg);
//    namedWindow("Draw shapes and texts",CV_WINDOW_AUTOSIZE);
//    imshow("Draw shapes and texts",bgimg);
//    2.Histogram equalization


//    3.Zooming and Shrinking images by bilinear interpolation, and hierachy
    Mat img = imread("f:/qt/a.tif");
//    Shrink img from 1250 dpi to 100 dpi
    My_shrink_image_bilinear(img, 100);
    namedWindow("Shrinking image by bilinear interpolation",CV_WINDOW_AUTOSIZE);
    imshow("Draw shapes and texts",img);


    waitKey(0);
    return 0;
}


void My_shrink_image_bilinear(Mat& img, int dpi_dst){
//Shrinking the image by bilinear interpolation
//Input
//        img - the source img
//        dpi_dst - the desired dpi that the source will be shrinked to
//Output
//        img - the shrinked source img

}
















//Corresponding built-in function: line, rectangle, ellipse, circle, fillPoly(polygon多边形)
void My_line(Mat& bgimg){
    Point pt1 = Point(20,30);
    Point pt2;
    pt2.x = 200;
    pt2.y = 300;
    Scalar color = Scalar(0,0,255);
    line(bgimg,pt1, pt2, color, 1, LINE_AA);
}

void My_shape(Mat &bgimg){
    Rect rect = Rect(200,100,200,150);//they are: init position(upperleft)200 100, the width of rectangle 200 150
    Scalar color = Scalar(0,255,0);
    rectangle(bgimg, rect, color, 2, LINE_AA);
}

void Random_line(Mat& bgimg){
    RNG rng(0xFFFFFFFB);
    Point pt1, pt2;
//    for(int i=0; i<1000; i++){
    pt1.x = rng.uniform(0, bgimg.cols);
    pt2.x = rng.uniform(0, bgimg.cols);
    pt1.y = rng.uniform(9, bgimg.rows);
    pt2.y = rng.uniform(0, bgimg.rows);
    Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));

    line(bgimg, pt1, pt2, color, 1, LINE_8);
//    }
}
