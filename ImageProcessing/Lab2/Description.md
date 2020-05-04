Description for Lab2

1. Understand three ideas in operating single elements: Plain C, at, STL.

2. Write own function to achieve the same results as src.copyTo(dst) and dst=src.clone().

3. Understand the difference between copyTo/clone and Mat dst(src).

4. Understand the linear blending of two images. Implement the built-in function addWeighted(src1, alpha, src2, beta, gamma, dst). Don't forget saturate_cast<uchar>(). From now on, pls program in standard style, that specify the aim, input, output of the self-written function.

5. Familiar with arithmetic operations, including:

   remapping: make sure the element values are within data type limit. e.g. 0-255 for Vec3b(uchar), 0-1 for Vec3f(float).
   
   (Project 02-05) multiply(src1, src2, dst, coef),divide, substract, adding
   
6. Homework: halftoning.

   

   

   



Notes(did not implement):

1. Reverse color - bitwise_not(src, dst); is to reverse the color. For CV_8UC1 it's just 255 - original value. Similarly, for CV_8UC3 it's 255 - value in each element.
2. Convert data type - src.convertTo(dst, CV_32F) is to convert Vec3b (uchar) to Vec3f(float). Similar to dst =  double(src) in Matlab.



Legend: What do "understand" and "familiar"  mean?

"Understand": Not only the implementation, but also theory - background, aim, pros, cons, applications, future development.

"Familiar": know the built-in function, call api, and implement.

If "implement" shows up, it means both write it myself and call api.



I was wondering that if I write these documents and explanations to encourage myself lol since there is no one to talk with.



