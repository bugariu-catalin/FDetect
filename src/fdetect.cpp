#include "fdetect.hpp"

FDetect::FDetect() {
	printf("fire constructor\n");
}

FDetect::~FDetect() {
	printf("fire destructor\n");
}

void FDetect::Detect(int real_faces) {
	std::vector<Rect> faces;
	Mat img_gray, img_proc;
	double detect_err = 0;

	cvtColor( this->image, img_gray, CV_BGR2GRAY );

	this->face_cascade.detectMultiScale( img_gray, faces, 1.1, 3, 0|CV_HAAR_DO_CANNY_PRUNING, Size(30, 30) );

	printf("Faces %d, detected %d", real_faces, faces.size());
	if (real_faces!=faces.size()) printf(", error");
	printf("\n");

	for( unsigned int i = 0; i < faces.size(); i++ )
	{
		//printf("face detected\n");
		//printf(">>x=%d\n>>y=%d\nw=%d\nh=%d\n--------\n",faces[i].x,faces[i].y,faces[i].width,faces[i].height);
	    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
	    //for (int j = 0; j < faces[i].width/2; j++)
	    //ellipse( this->image, center, Size( faces[i].width*0.5-j, faces[i].height*0.5-j), 0, 0, 360, Scalar( 255-j*i*2, 0+j*i*2, 255-j*i*2 ), 4, 8, 0 );
	    //rectangle( this->image, Point(faces[i].x , faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height),Scalar(255,i*2,255),1,CV_AA,0);
	    //putText( *img, "Face i", Point(faces[i].x , faces[i].y+ faces[i].height*0.5), 2,1,Scalar( 255, 0, 255 ),1,8,0);
	}
}

void FDetect::Test(String src, int faces) {
	printf("start test\n");

	//Load algo data
	String face_cascade_name = "C:\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt.xml";//best 1

	if( !this->face_cascade.load( face_cascade_name ) ){
		printf("--(!)Error loading face cascade file\n");
		return;
	}

	//read image
	this->image = imread(src, CV_LOAD_IMAGE_COLOR);

	//detect faces
	this->Detect(faces);

}

