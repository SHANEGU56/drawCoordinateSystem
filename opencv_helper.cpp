#include "opencv_helper.h"

using namespace cv;
using namespace std;

void AxisDrawer::drawAxis(float yaw, float pitch, float roll, int center_x, int center_y, int size){
    Mat image;
    image = imread("screenshot.bmp", 1);
    const float pi = 3.141592653;
    float p = pitch * pi / 180;
    float y = -(yaw * pi / 180);
    float r = roll * pi / 180;
    // X-Axis pointing out of the screen, drawn in blue
    float x1 = size * (sin(y)) + center_x;
    float y1 = size * (-cos(y) * sin(p)) + center_y;
    
    // Y-Axis pointing to the right side, drawn in red
    float x2 = size * (cos(y) * cos(r)) + center_x;
    float y2 = size * (cos(p) * sin(r) + cos(r) * sin(p) * sin(y)) + center_y;
    
    // Z-Axis pointing to the down side, drawn in green
    float x3 = size * (-cos(y) * sin(r)) + center_x;
    float y3 = size * (cos(p) * cos(r) - sin(p) * sin(y) * sin(r)) + center_y;
    
    cv::Point p0, p1, p2, p3;
    p0.x = center_x;
    p0.y = center_y;
    p1.x = x1;
    p1.y = y1;
    p2.x = x2;
    p2.y = y2;
    p3.x = x3;
    p3.y = y3;
    
    line(image, p0, p1, cvScalar(255,0,0),2);
    line(image, p0, p2, cvScalar(0,0,255),3);
    line(image, p0, p3, cvScalar(0,255,0),3);
}
