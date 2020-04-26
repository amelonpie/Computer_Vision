//Only rewrite the mask part
#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    //Load image
    Mat src = imread("f:/a.tif");
    //Find size
    int rows = src.rows;
    int cols = src.cols * src.channels();
    int offsetx = src.channels();
    //Create new object
    Mat dst(src.rows, src.cols, src.type(), Scalar(0));
    //Loop to mask
    for(int row = 1; row<rows-1; row++){
        const uchar* current = src.ptr<uchar>(row);
        const uchar* previous = src.ptr<uchar>(row-1);
        const uchar* next = src.ptr<uchar>(row+1);
        uchar* output = dst.ptr<uchar>(row);
        for(int col = offsetx; col<cols; col++){
            output[col] = saturate_cast<uchar>(5*current[col] - (previous[col] + current[col-offsetx] + current[col+offsetx] + next[col]));
        }
    }
    //Display
    namedWindow("Source",WINDOW_AUTOSIZE);
    imshow("Source",src);
    namedWindow("Destination",WINDOW_AUTOSIZE);
    imshow("Destination",dst);
    //waitKey
    waitKey(0);
    return 0;
}
