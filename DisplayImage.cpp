#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>


#include "imProc/Point.h"
#include "imProc/Matrix.h"
#include "imProc/Image.h"

#include <time.h>

using namespace std;

typedef imProc::Image<uchar> Image;


int main(int argc, char** argv ) {
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }


    Image image(argv[1]);
    image.imshow("Original Image");

//
//    Image immersion = image.makeImmersion(10,13,20,30, 0);
//    immersion.imshow("ImmersionTest");
//


    int rows = 6;
    int cols = 6;
    imProc::Matrix<bool> SE(cols, rows, true);

    imProc::Point<int> center( (int)ceil(rows/2), (int)ceil(cols/2));

    Image open(image);
    open.opening(SE, center );

    //namedWindow("Opened Image", WINDOW_AUTOSIZE );
    open.imshow("Opened Image");


    Image close(image);
    close.closure( SE, center );
    //namedWindow("Closed Image", WINDOW_AUTOSIZE );
    close.imshow("Closed Image");

    open.closure(SE, center);
    open.imshow("Closure on Opened Image");

    close.opening(SE, center);
    close.imshow("Opening on Closed Image");

    cv::waitKey(0);

    return 0;
}


