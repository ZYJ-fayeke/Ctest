#include "MeanFilter.h"

MeanFilter::MeanFilter(int size) : Filter(size)
{

}

MeanFilter::~MeanFilter()
{

}
//均值滤波器很容易理解，即把邻域内的平均值赋给中心元素。
Matrix MeanFilter::Filtering(const Matrix &input)//均值就是包含xy领域的几个像素的灰度级的平均值所决定，效果是和所用的领域半径有关
{
    int height = input.Height();
    int width = input.Width();

    Matrix m(height, width);
    double mean = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int area_x = i - (this->filterSize - 1) / 2; area_x - i < (this->filterSize - 1) / 2 + 1; area_x++)
            {
                for (int area_y = j - (this->filterSize - 1) / 2; area_y - j < (this->filterSize - 1) / 2 + 1; area_y++)
                {
                    mean += input.At(area_x, area_y);
                }
            }
            mean /= this->filterSize * this->filterSize;
            m.Set(i, j, mean);
        }
    }
    return m;
}
