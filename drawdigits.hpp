#pragma once
#include "drawlines.hpp"

#include <unordered_map>


void draw0(cv::Mat& dest, int offset);
void draw1(cv::Mat& dest, int offset);
void draw2(cv::Mat& dest, int offset);
void draw3(cv::Mat& dest, int offset);
void draw4(cv::Mat& dest, int offset);
void draw5(cv::Mat& dest, int offset);
void draw6(cv::Mat& dest, int offset);
void draw7(cv::Mat& dest, int offset);
void draw8(cv::Mat& dest, int offset);
void draw9(cv::Mat& dest, int offset);

namespace draw_digits_engine {
    typedef void (*draw_t)(cv::Mat&, int);
    extern std::unordered_map<int, draw_t> engine;
}
