#include<opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include<iostream>
//using namespace std;
using namespace cv;
int main(int argc,char** argv)
{
	Mat imgOriginal = imread("./images/image.jpg",1);
	const char* pzOriginalImage = "Original Image";
	namedWindow(pzOriginalImage,WINDOW_AUTOSIZE);
	imshow(pzOriginalImage , imgOriginal);
	const char* pzRotatedImage = "Rotated Image";
	namedWindow(pzRotatedImage, WINDOW_AUTOSIZE);
	int iAngle = 180;
	createTrackbar("Angle", pzRotatedImage, &iAngle, 360);
	int iImageHeight = imgOriginal.rows / 2;
	int iImageWidth = imgOriginal.cols / 2;
	while (true)
	{
		Mat matRotation = getRotationMatrix2D(Point(iImageWidth, iImageHeight), (iAngle - 180), 1);
		Mat imgRotated;
		warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size());
		imshow(pzRotatedImage, imgRotated);
		int iRet = waitKey(30);
		if (iRet == 27)
		{
			break;
		}
	}
	return 0;
}

