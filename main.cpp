//
// Created by duke on 2022/6/29.
//

#include <iostream>
#include "dqcg/bmpimage.h"

const BMPColor white = BMPColor(255, 255, 255);
const BMPColor red   = BMPColor(0, 0,   255);

void line(int x0, int y0, int x1, int y1, BMPImage &image, BMPColor color) {
    bool steep = false;
    if (std::abs(x0-x1)<std::abs(y0-y1)){
        steep = true;
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    if (x0 > x1){
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1-x0;
    int dy = y1-y0;
    int derror2dx = std::abs(dy) * 2;//derror2dx and error2dx means multiple 2*dx
    int error2dx = 0;
    int y = y0;
    for (int x = x0; x <= x1; ++x) {
        if (steep){
            image.set(y, x , color);
        } else{
            image.set(x, y , color);
        }
        error2dx += derror2dx;
        if (error2dx > dx){
            y1-y0 > 0?y++:y--;//up or down
            error2dx -= dx*2;
        }
    }
}


int main() {
    BMPImage image(100, 100);
    line(13, 20, 80, 40, image, white);
    line(20, 13, 40, 80, image, red);
    image.write_bmp_file("output.bmp");
    return 0;
}