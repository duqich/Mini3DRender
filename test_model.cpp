#include <iostream>
#include "dqcg/bmpimage.h"
#include "geometry.h"
#include "model.h"

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
void test_line(){
    const BMPColor white = BMPColor(255, 255, 255);
    const BMPColor red   = BMPColor(0, 0,   255);
    BMPImage image(100, 100);
    line(13, 20, 80, 40, image, white);
    line(20, 13, 40, 80, image, red);
    image.write_bmp_file("output_test_line.bmp");
}

void test_load_model_wireframe(){
    const BMPColor white = BMPColor(255, 255, 255);
    const int width  = 800;
    const int height = 800;
    Model model("../obj/african_head/african_head.obj");
    BMPImage image(width, height);
    for (int i=0; i<model.nfaces(); i++) {
        std::vector<int> face = model.face(i);
        for (int j=0; j<3; j++) {
            Vec3f v0 = model.vert(face[j]);
            Vec3f v1 = model.vert(face[(j+1)%3]);
            int x0 = (v0.x+1.)*(width-1)/2.;
            int y0 = (v0.y+1.)*(height-1)/2.;
            int x1 = (v1.x+1.)*(width-1)/2.;
            int y1 = (v1.y+1.)*(height-1)/2.;
            line(x0, y0, x1, y1, image, white);
        }
    }
    image.write_bmp_file("output_load_model_wireframe.bmp");
}

int main() {
    test_line();
    test_load_model_wireframe();
    return 0;
}