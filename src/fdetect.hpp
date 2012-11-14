
#ifndef DETECT_H_
#define DETECT_H_

#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class FDetect {

public:
	FDetect();
	virtual ~FDetect();
	void Test(String src, int faces);
	void Detect(int real_faces);
private:
	CascadeClassifier face_cascade;

protected:
	Mat image;
};

#endif /* DETECT_H_ */
