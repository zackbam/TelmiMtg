#include <opencv\cv.h>
#include <opencv\highgui.h>
using namespace std; 
using namespace cv;

void morphOps(Mat &thresh){

	//create structuring element that will be used to "dilate" and "erode" image.
	//the element chosen here is a 3px by 3px rectangle

	Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
    //dilate with larger element so make sure object is nicely visible
	Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));

	erode(thresh,thresh,erodeElement);
	erode(thresh,thresh,erodeElement);

	dilate(thresh,thresh,dilateElement);
	dilate(thresh,thresh,dilateElement);
}

int main(){

	Mat frame1,frame2;
	//their grayscale images (needed f absdiff() function)
	Mat grayImage1,grayImage2;
	//resulting difference image
	Mat differenceImage;
	//thresholded difference image (for use in findContours() function)
	Mat thresholdImage;
	//video capture object.
	VideoCapture capture;
	capture.open(0);
	while(1){
		if(!capture.isOpened()){
				cout<<"Cannot capture Video"<<endl;
				capture.open(0);
		}
		capture.read(frame1);
		cv::imshow("Original image",frame1);
		cv::cvtColor(frame1,grayImage1,COLOR_BGR2GRAY);
		capture.read(frame2);
		cv::cvtColor(frame2,grayImage2,COLOR_BGR2GRAY);
		cv::absdiff(grayImage1,grayImage2,differenceImage);
		cv::imshow("ABSDifference",differenceImage);
		cv::threshold(differenceImage,thresholdImage,30,255,THRESH_BINARY);
		cv::imshow("Thresholded",thresholdImage);
		morphOps(thresholdImage);
		cv::imshow("Erode_Dilate",thresholdImage);

		switch(waitKey(10)){
		case 27:
			return 0;
		}
	}
}