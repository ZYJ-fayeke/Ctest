#include "MediaFilter.h"
#include <algorithm>

MedianFilter::MedianFilter(int size) : Filter(size)
{}
MedianFilter::~MedianFilter()
{}
//取以目标象素为中心的一个子矩阵窗口，这个窗口可以是3*3 ，5*5 等根据需要选取，对窗口内的象素灰度排序，取中间一个值作为目标象素的新灰度值。
Matrix MedianFilter::Filtering(const Matrix &input)//中值非线性，是将一点的值用各店值得中值代换！
{
    int height = input.Height();
    int width = input.Width();

    Matrix m(height, width);
    double* data = new double[this->filterSize*this->filterSize];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int p = 0;
            for (int a_x = i - (this->filterSize - 1) / 2; a_x - i < (this->filterSize - 1) / 2 + 1; a_x++)
            {
                for (int a_y = j - (this->filterSize - 1) / 2;a_y - j < (this->filterSize - 1) / 2 + 1; a_y++)
                {
                    data[p] = input.At(a_x, a_y);
                     p++;
                }
            }
            std::sort(data, data + this->filterSize*this->filterSize);//就是为了小于滤波器一半面积明暗都会被xiao'chu1！
            m.Set(i, j, data[(this->filterSize*this->filterSize) / 2]);//！！
        }
    }
    delete[] data;
    return m;
}
