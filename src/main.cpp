//============================================================================
// Name        : fdetect.cpp
// Author      : Bugariu Catalin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "main.hpp"

String face_cascade_name = "C:\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt.xml";//best 1
//String face_cascade_name = "C:\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";//best 2
//String face_cascade_name = "C:\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt_tree.xml";//best 3
//String face_cascade_name = "C:\\opencv\\data\\haarcascades\\haarcascade_profileface.xml";//poor
//String face_cascade_name = "C:\\opencv\\data\\lbpcascades\\lbpcascade_frontalface.xml";//poor




CascadeClassifier face_cascade;

int main( int argc, char* argv[] ) {

	FDetect detector;
	detector.Test("test.jpg",18);
	detector.Test("test2.jpg",13);
	//CvCapture* capture;
	/*Mat frame;
	Mat image;
	cv::namedWindow("win1");

	if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

	image = imread("test2.jpg", CV_LOAD_IMAGE_COLOR);
	detect(&image);
	imshow( "win1", image );
	//imwrite("out_nohist.jpg", image);

	while ( true ) {
	       int c = waitKey(10);
	       if( (char)c == 'c' ) {
			   break;
		   }
	}*/

/*
	capture = cvCaptureFromCAM( 1 );
	   if( capture )
	   {
	     while( true )
	     {
	       frame = cvQueryFrame( capture );

	       //-- 3. Apply the classifier to the frame
	       if( !frame.empty() )
	       {
			   detect( frame );
		   }
	       else
	       {
			   printf(" --(!) No captured frame -- Break!"); break;
		   }

	       int c = waitKey(10);
	       if( (char)c == 'c' ) {
			   break;
		   }
	      }
	   }
	   cvReleaseCapture(&capture);
*/
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//help( argv[0] );
	return 0;
}

void help(const char* exec)
{
	printf("Usage: %s [options]\n", exec);
	printf("	   %s -s FILE -d FILE\n", exec);
	printf("	   %s --source=FILE --destination=FILE\n", exec);
	printf("	   %s -s FILE -d FILE -f xml\n", exec);
	printf("	   %s -s FILE -d FILE -f image -o image --overlay-source=FILE\n", exec);
	printf("	   %s -s FILE -d FILE -f image -o shape --overlay-shape=triangle\n", exec);
	printf("\n");
	printf("Options:\n");
	printf("  -s, --source=FILE        Image FILE to be processed\n");
	printf("  -d, --destination=FILE   Where to save the result\n");
	printf("  -f, --output-format=[image|json|xml|csv] In wath format to save the image\n");
	printf("  -o, --overlay=[image|shape] Add overlay to detected faces\n");
	printf("  --overlay-source=FILE    Image FILE to be used for overlay\n");
	printf("  --overlay-shape=[triangle|square|pentagon|hexagon|octagon|circle|rectangle|elipse] Wath type of shape to use for overlay\n");
	printf("  --overlay-alpha=[0-255]  Specify overlay transparency\n");
	printf("  --shape-fill-color=COLOR Specify overlay shape fill color\n");
	printf("  --shape-line-color=COLOR Specify overlay shape line color\n");
	printf("\n");
	printf("  -v, --version            Print the version number and exit\n");
	printf("  -h, --help               Show this message and exit\n");
	printf("\n");
	printf("\n");
	printf("For bug reporting instructions, please see:\n");
	printf("<https://github.com/bugariu-catalin/FDetect>.\n");
}

void detect(Mat *img)
{
	std::vector<Rect> faces;
	Mat img_gray, img_proc;

	cvtColor( *img, img_gray, CV_BGR2GRAY );

	//equalizeHist( img_gray, img_gray );

	//imshow( "win1", *img );

	face_cascade.detectMultiScale( img_gray, faces, 1.1, 3, 0|CV_HAAR_DO_CANNY_PRUNING, Size(30, 30) );

	printf("Faces detected:%d\n", faces.size());

	for( unsigned int i = 0; i < faces.size(); i++ )
	{
		printf("face detected\n");
		printf(">>x=%d\n>>y=%d\nw=%d\nh=%d\n--------\n",faces[i].x,faces[i].y,faces[i].width,faces[i].height);
	    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
	    ellipse( *img, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
	    rectangle( *img, Point(faces[i].x , faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),Scalar(255,0,255),10,CV_AA,0);
	    //putText( *img, "Face i", Point(faces[i].x , faces[i].y+ faces[i].height*0.5), 2,1,Scalar( 255, 0, 255 ),1,8,0);
	}

}
