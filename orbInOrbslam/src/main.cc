#include<iostream>
#include<ORBextractor.h>
#include<opencv2/opencv.hpp>

int main(){
	//ORB in ORB-SLAM
	cv::Mat img=cv::imread("1.png",1);
	ORB_SLAM::ORBextractor mpORBextractor;
	std::vector<cv::KeyPoint> mvKeys;
	cv::Mat mDescriptors;
	std::vector<cv::Mat> src;

	cv::split(img,src);
	mpORBextractor(src[0],cv::Mat(),mvKeys,mDescriptors);

	std::vector<cv::KeyPoint>::iterator it;
	for(it=mvKeys.begin();it!=mvKeys.end();it++){
		cv::circle(img/*src[0]*/,it->pt,2,cv::Scalar(255,255,0),-1);
	}
	cv::imshow("ORB in ORB-SLAM",img/*src[0]*/);

	//PRB in OpenCV
	cv::Mat img2=cv::imread("1.png",1);
	std::vector<cv::KeyPoint> keypoints;
	cv::Ptr<cv::ORB> orb=cv::ORB::create(1000); 
	orb->detect(img2,keypoints);
	for(it=keypoints.begin();it!=keypoints.end();it++){
		cv::circle(img2,it->pt,2,cv::Scalar(255,255,0),-1);
	}
	cv::imshow("ORB in OpenCV",img2);

	cv::waitKey();
}
