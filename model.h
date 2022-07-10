//
// Created by duke on 2022/7/10.
//

#ifndef MINI3DRENDER_MODEL_H
#define MINI3DRENDER_MODEL_H

#include <vector>
#include "geometry.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

class Model{
private:
    std::vector<Vec3f> verts_;
    std::vector<std::vector<int> > faces_;
public:
    Model(const char* filename);
    int nverts();
    int nfaces();
    Vec3f vert(int i);
    std::vector<int> face(int i);
};

Model::Model(const char* filename){
    std::ifstream in;
    in.open(filename, std::ifstream::in);
    if(in.fail()) return;
    std::string line;
    while (in.eof() == 0){
        std::getline(in, line);
        std::istringstream iss(line);
        std::string s;
        if (line.compare(0, 2, "v ") == 0){
            iss >> s;
            Vec3f v;
            for (int i = 0; i < 3; ++i) {
                iss >> v.raw[i];
            }
            verts_.push_back(v);
        } else if(line.compare(0, 2, "f ") == 0){
            iss >> s;
            std::vector<int> f;
            while (iss >> s){
                s = s.substr(0, s.find("/"));
                int idx = std::stoi(s);
                idx--;//in wavefront obj all indices start at 1, not zero
                f.push_back(idx);
            }
            faces_.push_back(f);
        }
    }
    in.close();
    std::cerr << "# v#" << verts_.size() << "# f#" << faces_.size() << std::endl;
}
int Model::nverts(){
    return (int) verts_.size();
}
int Model::nfaces(){
    return (int) faces_.size();
}
Vec3f Model::vert(int i){
    return verts_[i];
}
std::vector<int> Model::face(int i){
    return faces_[i];
}
#endif //MINI3DRENDER_MODEL_H
