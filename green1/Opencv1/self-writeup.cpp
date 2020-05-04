//自己写一遍，不看范例

#include <opencv2/opencv.hpp>
#include <iostream>
#include <melon_function/mfunc_display.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
    Mat img = imread("F:/lena_std.tif");
//    namedWindow("My first try read image",CV_WINDOW_AUTOSIZE);
    imshow("My first try read image",img);

    Mat cvtedImg;
//    namedWindow("Convert original image to color",WINDOW_AUTOSIZE);
    cvtColor(img,cvtedImg,CV_RGB2GRAY);
    imshow("Convert original image to GRAY",cvtedImg);

    const uchar* first = cvtedImg.ptr<uchar>(0);
//    cout << first <<endl; //Invalid operation
//    cout << *first <<endl; //Output many things
    printf("First element is valued %d.\n", *first);

    Mat dst;
    dst = Mat(img.size(),img.type(),Scalar(0,255,255));
    namedWindow("Lena", CV_WINDOW_AUTOSIZE);
    imshow("Lena",dst);

    string name = "Lena";

    cout << "Standard picture in image processing is named " << name << "."  << endl;

    //What I learned about namedWindow and imshow:
    //If the specified name of two functions are different, the program will generate two window with each name, respectively.
    //It is also ok not to use namedWindow function.

    //What I learned about object.cols and object.size()
    //object.cols is the attribute of object, that the object is a struct, head covers rows, cols, property
    //object.size() is a function of opencv, that acquisite the size of the object.

    //Matlab-style initialization

    Mat matlab = Mat::zeros(img.size(), img.type());
//    cout << "matlab = " <<endl << matlab <<endl;
//    printf("Matlab = \n %d \n",matlab);
    Mat m2 = Mat::eye(2,2,CV_8UC1);

    Mat ims(Size(img.cols*2,img.rows),img.type(),Scalar(0));
    imshowpair_h(img, cvtedImg, ims);

    waitKey(0);
    return 0;
}
