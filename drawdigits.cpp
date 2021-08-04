#include "drawdigits.hpp"

std::unordered_map<int, draw_digits_engine::draw_t>
draw_digits_engine::engine {
    {0, draw0},
    {1, draw1},
    {2, draw2},
    {3, draw3},
    {4, draw4},
    {5, draw5},
    {6, draw6},
    {7, draw7},
    {8, draw8},
    {9, draw9},
};


void draw0(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(77,22,188);
    drawUpper(dest, offset, color);
    drawRightUpper(dest, offset, color);
    drawLeftUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
    drawLeftBottom(dest, offset, color);
    drawBottom(dest, offset, color);
}

void draw1(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(22,22,220);
    drawRightUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
}

void draw2(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(22,220,22);
    drawCentral(dest, offset, color);
    drawUpper(dest, offset, color);
    drawRightUpper(dest, offset, color);
    drawLeftBottom(dest, offset, color);
    drawBottom(dest, offset, color);
}

void draw3(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(22,220,220);
    drawCentral(dest, offset, color);
    drawUpper(dest, offset, color);
    drawRightUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
    drawBottom(dest, offset, color);
}

void draw4(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(220,22,22);
    drawCentral( dest, offset, color);
    drawRightUpper( dest, offset, color);
    drawLeftUpper( dest, offset, color);
    drawRightBottom( dest, offset, color);
}

void draw5(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(220,22,220);
    drawCentral(dest, offset, color);
    drawUpper(dest, offset, color);
    drawLeftUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
    drawBottom(dest, offset, color);
}

void draw6(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(220,220,22);
    drawCentral(dest, offset, color);
    drawUpper(dest, offset, color);
    drawLeftUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
    drawLeftBottom(dest, offset, color);
    drawBottom(dest, offset, color);
}

void draw7(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(220,220,220);
    drawUpper(dest, offset, color);
    drawRightUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
}

void draw8(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(35,156,220);
    drawCentral(dest, offset, color);
    drawUpper(dest, offset, color);
    drawRightUpper(dest, offset, color);
    drawLeftUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
    drawLeftBottom(dest, offset, color);
    drawBottom(dest, offset, color);
}

void draw9(cv::Mat& dest, int offset)
{
    const cv::Vec3b color(156,56,220);
    drawCentral(dest, offset, color);
    drawUpper(dest, offset, color);
    drawRightUpper(dest, offset, color);
    drawLeftUpper(dest, offset, color);
    drawRightBottom(dest, offset, color);
    drawBottom(dest, offset, color);
}
