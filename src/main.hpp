/*
 * FDetect.hpp
 *
 *  Created on: May 12, 2012
 *      Author: user1
 */

#ifndef FDETECT_HPP_
#define FDETECT_HPP_

#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "fdetect.hpp"

using namespace std;
using namespace cv;

void help(const char* exec);
void detect(Mat *img);

#endif /* FDETECT_HPP_ */
