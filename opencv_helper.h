#ifndef _OPENCV_HELPER_H
#define _OPENCV_HELPER_H

#include <opencv2/opencv.hpp>
#include <cmath>

class AxisDrawer{
public:
    AxisDrawer();
    ~AxisDrawer();
    
    void drawAxis(float yaw, float pitch, float roll, int center_x, int center_y, int size);
};

#endif /* opencv_helper_h */
