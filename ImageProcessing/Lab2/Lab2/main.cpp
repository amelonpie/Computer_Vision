//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include<iostream>
//using namespace cv;
//using namespace std;

//int My_copyimage_plainc(Mat& img1, Mat& img2);
//int My_copyimage_at(Mat& img1, Mat& img2);
//int My_copyimage_STL(Mat& img1, Mat& img2);
////void My_incContrast(Mat& src, Mat &dst);
//int My_remapping(Mat& src, Mat& dst);
//int My_multiply(Mat& src1, Mat& src2, double scale, Mat& dst);

//int main(int argc, char *argv[])

//{
//    Mat img0=imread("f:/qt/a.tif",0);//载入图像，0为灰度图像，1为彩色图像
//    imshow("sources image",img0);
//////    Mat img1,img2,img3;
//////    img1.create(img0.rows,img0.cols,img0.type());
//////    img2.create(img0.rows,img0.cols,img0.type());
//////    img3.create(img0.rows,img0.cols,img0.type());
//////    img0.copyTo(img1);//调用opencv库函数，实现图像拷贝
//////    imshow("result of opencv function_copyto",img1);//显示图像
//////    img2=img0.clone();//调用opencv库函数，实现图像拷贝
//////    imshow("result of opencv function_clone",img2);//显示图像
//////    My_copyimage_at(img0,img3);//调用My_copyimage函数，实现图像拷贝
//////    My_copyimage_STL(img0,img3);
//////    imshow("result of my function",img3);//显示图像

////    //练习图像的掩模操作：提高对比度，用一个3x3的掩模提高对比度，行列分别为 [0 -1 0] [-1 5 0] [0 -1 0]
//////    Mat img4;
//////    img4.create(img0.rows,img0.cols,img0.type());
////    Mat img4(img0.rows,img0.cols,img0.type(), Scalar(0));
////    My_incContrast(img0, img4);
////    namedWindow("My increased contrast",WINDOW_AUTOSIZE);
////    imshow("My increased contrast",img4);

////    //用filter2D自带函数实现这个功能
////    Mat img5(img0.rows,img0.cols,img0.type(), Scalar(0));
////    Mat kernel = (Mat_<char>(3,3) << 0,-1,0, -1,5,-1, 0,-1,0);
////    //Learn Mat_ in the Lab3
////    filter2D(img0,img5,img0.depth(),kernel);  // img0.depth() is equivalent to -1;
////    namedWindow("filter2D",WINDOW_AUTOSIZE);
////    imshow("filter2D",img5);

////   自己实现remapping并且比较remapping和clipping的区别
////   remapping:将图像最大值重映射到255，最小值到0，按比例将结果图像的像素值缩放，使得结果图像的像素值全部在[0,255]范围内. (注意，OpenCVC API remap( src, dst, other argin);是用来搞翻转的，所以要自己写)
////   clipping:将大于255和小于0的值通通设成255或者0，使得结果图像的像素值全部在[0,255]范围内,API是dst=saturate_cast<uchar>(src);
////   什么时候选哪种：一般都用clipping而不去管remapping，比如通过灰度线性变化调整了亮度有个0(假设最小值)变成了50，而225(假设最大值)变成了500，那么remapping会把500变成(500-50)*(255/(500-50)=450*0.566=254.999四舍五入就是255了，而200变成了227
////  对比一下：0,200,225 - 0,227,255，重映射。而clipping - 50, 255,255。
////  remapping的结果是比较正常的，保留了细节，而clipping就很粗暴了，丢失了细节
////  问题：为什么OpenCV库函数不提供remapping这个功能呢？
////    猜测1：可能是因为，好多内置函数自带了saturate_cast，比如multiply()函数，超出范围了自动cut，那么remapping就没有用武之地了。
////  验证想法：四则运算的备注Saturation is not applied when the output array has the depth CV_32S. You may even get result of an incorrect sign in the case of overflow.意思是我们的32B直接就saturate了(CV_32S就等同于CV_32SC1，32位有符号整型)
////  并且，用imshow来观察是有失偏颇的，因为imshow会自动clipping。因此在my_remapping里添加console输出看看multiply的结果
////    猜测2：remapping可以通过直方图均衡来实现，并且直方图调整更加通用
////  验证想法：TBD.
//    Mat dst(img0.size(),img0.type(),Scalar(0));
//    Mat src(img0.size(),img0.type(),Scalar(0));
//    Mat ones(img0.size(),img0.type(),Scalar(1));
////    multiply(img0, img0, src, 0.05, -1 );
//    My_multiply(img0,ones,0.3,src);
//    imshow("multiply()", src);
//    My_remapping(src, dst);
//    imshow("remapping", dst);

//    waitKey(0);//等待结束，任意键结束
//    return 0;
//}






/////*使用多重循环的方法，实现遍历像素，并将每一个像素点复制到另外的图像的相应位置上
////分别通过Plain C思想、at思想、STL迭代器思想实现图像的复制
////Plain C思想:数组思想,利用C语言中的操作符[]访问像素。这种方法最快，但是较为抽象。
////at思想，即ObjectArray思想：利用成员函数at(int y,int x)存取图像的像素，需要注意的是，一定要确保数据类型和矩阵中的数据类型相符合，因为at()本身不会进行数据转换。这种方法十分简洁明了，符合大家对像素的直观认识。但是效率低
////STL迭代器思想，即容器思想：在迭代法中，我们所需要做的仅仅是获得图像矩阵的begin和end，然后增加迭代直至begin到end。相比于指针直接访问可能出现的越界问题，迭代器绝对是非常安全的方法。
////*/



////PlainC实现
//int My_copyimage_plainc(Mat& img1, Mat& img2)
//{
//    int row = img1.rows;
//    int col = img1.cols;
//    int channel = img1.channels();
///*
//    Know(图像的存储)：图像，可以是灰度图像，也可以是彩色图像。彩色图像（这里仅考虑RGB）在MATLAB里是作为多维数组存储的，例如m*n*c，其中c为通道。RGB图像即是c=3
//    在Opencv里，图像都是作为二维数组存储的。对于灰度图像m*n，存储为m*n的二维数组。对于彩色图像m*n*c，则存储为m*(n*c)的二维数组，具体如下
//    行数与我们设置的相同，每行用封号隔开；
//    在每行内，逐元素按照通道依次输出，
//    例如，对于一个3x2x3的三维图像，实际存储为一个3x6的二维矩阵，其中
//    第一行第一个元素的通道1的值、通道2的值、通道3的值；第一行第二个元素的通道1的值、通道2的值、通道3的值；
//    第二行第一个元素的通道1的值、通道2的值、通道3的值…以此类推
//    非常详细的介绍 m5: http://zhaoxuhui.top/blog/2019/08/24/OpenCV-Mat-Note.html#1mat%E5%88%9B%E5%BB%BA

//    Know(MAT类的数据类型)：Mat数据结构里矩阵的每个元素代表一个像素，用8位无符号数来表示（uchar）,CV_8UC3

//    Know(MAT数组的操作通过指针进行)：在Mat里，对数组的操作通过指针进行。Mat 提供了 ptr 函数可以得到图像任意行的首地址
//    首先取得数组某一行的首地址，例如第一行，即为第一个字节（第一行第一列）的地址，再索引列。
//    用法为 uchar* data = image.ptr<uchar>(row)

//    因此，该函数的思路应该是：
//    不断取得数组的行地址，循环操作该行的每一列
//*/

//    int maxRow = row;
//    int maxCol = col*channel;

//    for(int i=0; i<maxRow; i++)
//    {
//        uchar* data1 = img1.ptr<uchar>(i);
//        uchar* data2 = img2.ptr<uchar>(i);

//        for(int j=0; j<maxCol; j++)
//        {
//            data2[j] = data1[j];
//        }
//    }

//}



////at实现
////at的语法为：
////赋值 image.at<uchar>(row,col) = value;
////读取 uchar value = image.at<uchar>(row,col);
//int My_copyimage_at(Mat& img1, Mat& img2)
//{
//    int row = img1.rows;
//    int col = img1.cols * img1.channels();

//    for(int i=0; i<row; i++)
//    {
//        for(int j=0; j<col; j++)
//            img2.at<uchar>(i,j) = img1.at<uchar>(i,j);
//    }
//}


////STL实现
////STL的语法为：
////声明一个迭代器 Mat_<Vec3b>::iterator it; 如果指向一个const图像则 Mat_<Vec3b>::const_iterator it;
////如果是单通道则为uchar
//int My_copyimage_STL(Mat& img1, Mat& img2)
//{
//    /*
//    Know(Mat的子类Mat_的使用)：
//    Mat_<Vec3b> src_;  // 创建Mat_对象
//    src_ = src; //赋值  此时 src 与 src_ 共享矩阵的数据内存空间
//    Vec3b value(99,99,99);
//    src_(10,10) = value; //Mat_ 类的对象 可以通过operator() 来访问矩阵数据
//    */
//    Mat_<uchar>::const_iterator it;
//    Mat_<uchar>::iterator it2;
//    it2 = img2.begin<uchar>();
//    it = img1.begin<uchar>();
//    while(it != img1.end<uchar>())
//    {
//    (*it2) = (*it);//通过指针赋值，属于深拷贝，操作img2不会改变原img1
//    it2++;
//    it++;
//    /*如果是三通道图像则为
//        (*it)[0] = 255;
//        (*it)[1] = 255;
//        (*it)[2] = 255;
//        it++;
//    */
//    }
//}

/////*
////https://www.cnblogs.com/liu-jun/archive/2012/08/12/jackyliu.html
////学习体会：

////当Mat为多通道时，如3通道，如果我们将其内容输出到终端，则可以看出其列数为Mat::cols的n倍，当然n为Mat的通道数。虽是如此，但是Mat::cols的数值并没有随之改变。
////当复制一副图像时，利用函数cv::Mat::clone()，则将在内存中重新开辟一段新的内存存放复制的图像（图像数据也将全部复制），而如果利用cv::Mat::copyTo()复制图像，则不会在内存中开辟一段新的内存块，同时也不会复制图像数据，复制前后的图像的指针指向同一个内存块。使用的时候需注意两个函数的区别。
////为了避免函数参数传递时出现复制情况，函数的形参多采用传递reference，如cv::Mat &image，传递输入图像的引用，不过这样函数可能会对输入图像进行修改，并反映到输出结果上；如果想避免修改输入图像，则函数形参可传递const reference，这样输入图像不会被修改，同时可以创建一个输出图像Mat，将函数处理的结果保存到输出图像Mat中，例如：void colorReduce4(const cv::Mat &image, cv::Mat &result,int div = 64)。
////采用迭代器iterator来遍历图像像素，可简化过程，比较安全，不过效率较低；如果想避免修改输入图像实例cv::Mat，可采用const_iterator。
////遍历图像时，不要采用.at()方式，这种效率最低。
////进行图像像素压缩时，利用位操作的算法效率最高，其次是利用整数除法中向下取整，效率最低的是取模运算。
////设计函数时，需要检查计算效率来提高程序的性能，不过以牺牲程序的可读性来提高代码执行的效率并不是一个明智的选择。
////执行效率情况见程序运行结果。
////参考资料：《OpenCV 2 Computer Vision Application Programming Cookbook》
//// */


////增强图像对比度
//void My_incContrast(Mat& src, Mat& dst){
////  获取大小
//    int cols = src.cols * src.channels();
//    int rows = src.rows;
//    int offsetx = src.channels();//参见plain C，是对单通道操作滤波

////  开始循环
//    for(int row = 1; row < (rows-1); row++){
//        const uchar* current = src.ptr<uchar>(row);
//        const uchar* previous = src.ptr<uchar>(row-1);
//        const uchar* next = src.ptr<uchar>(row+1);
//        uchar* output = dst.ptr<uchar>(row);//注意不是对dst直接操作。我们总是通过定义指针来操作数据
//        for(int col = offsetx; col < cols; col++){
//            //注意图像uchar数值边界，用saturate_cast<>()来限定值在0-255之间
//            output[col] = saturate_cast<uchar>(5*current[col] - (previous[col] + current[col-offsetx] + current[col+offsetx] + next[col]));
//        }
//        }

//}


//int My_multiply(Mat& src1, Mat& src2,double scale, Mat& dst){
//    int rows = src1.rows;
//    int cols = src1.cols*src1.channels();
//    for(int row=0; row<rows; row++){
//        uchar* src1address = src1.ptr<uchar>(row);
//        uchar* src2address = src2.ptr<uchar>(row);
//        uchar* dstaddress = dst.ptr<uchar>(row);
//        for(int col=0; col<cols; col++){
//            dstaddress[col] = scale * src1address[col] * src2address[col];
//        }
//    }
//    return 0;
//}


////重映射
//    int My_remapping(Mat& src, Mat& dst){
//        int rows = src.rows;
//        int cols = src.cols*src.channels();
//        int maxPixel = 1;
//        int minPixel = 0;

//        //寻找src最大最小值
//        for(int row=0; row<rows; row++){
//            uchar* rowaddress = src.ptr<uchar>(row);
//            for(int col=0; col<cols; col++){
//              if(rowaddress[col]<minPixel){
//                    minPixel = rowaddress[col];
//                }
//                else if(rowaddress[col]>maxPixel){
//                    maxPixel = rowaddress[col];
//                }
//            }
//        }
//        cout << "Previous maximal pixel value is " << maxPixel << ", and min is "  << minPixel << endl;
//        //计算映射系数
//        int r = 255 / ( maxPixel - minPixel );
//        //映射src每个元素到dst
//        for(int row=0; row<rows; row++){
//            uchar* srcaddress = src.ptr<uchar>(row);
//            uchar* dstaddress = dst.ptr<uchar>(row);
//            for(int col=0; col<cols; col++){
//                dstaddress[col] = r * (srcaddress[col]-minPixel);
//            }
//        }
//        return 0;
//    }
