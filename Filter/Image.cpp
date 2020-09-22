#include <stdio.h>
#include "stdlib.h"
#include "math.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "Image.h"
#include "Matrix.h"
//#include "opencv2/imgproc/imgproc_c.h"

using namespace std;
using namespace cv;
#include <iostream>

Image::Image(char* ImageName)
{
    Read(ImageName);
}

Image::Image(const Image &im)
{
    this->init(im.height, im.width);

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            this->data[i][j] = im.data[i][j];
        }
    }
}
Image::~Image()
{

}

//从硬盘读入图像文件;
void Image::Read(char* ImageName)
{

    Mat img = imread(ImageName,0);
    this->height = img.rows;
    this->width = img.cols;
    int i = 0,j = 0;
    this->data = new double *[this->height];
    for (i = 0; i < this->height; i++)
        this->data[i] = new double [this->width];
    for(i = 0; i < this->height; i++)
    {
        for(j = 0; j < this->width; j++)
        {
            this->data[i][j] = (double)img.at<uchar>(i, j);
        }
    }
}


//false 左右，true 上下;
void Image::Flip(int code)
{
    if (code)
    {
        int up_line = 0;
        int down_line = this->height - 1;
        int j;
        unsigned char temp;

        while (up_line < down_line)
        {
            for (j = 0; j < this->width; j++)
            {
                temp = this->data[up_line][j];
                this->data[up_line][j] = this->data[down_line][j];
                this->data[down_line][j] = temp;
            }
            up_line++;
            down_line--;
        }
    }
    else
    {
        int left_line = 0;
        int right_line = this->width - 1;
        int i;
        unsigned char temp;

        while (left_line < right_line)
        {
            for (i = 0; i < this->height; i++)
            {
                temp = this->data[i][left_line];
                this->data[i][left_line] = this->data[i][right_line];
                this->data[i][right_line] = temp;
            }

            left_line++;
            right_line--;
        }
    }
}


void Image::Resize(int code)
{
    //write your code here
    if(code == 1)//通过复制图像的行和列实现图像的放大。通过删除偶数行列或者奇数行列实现图像的缩小。没有用临近值法和双线插值法
    {
        double **data_1 = this->data;
        int i,j;
        this->data = new double *[this->height*2];
        for(int i = 0; i < this->height*2; i++)
            this->data[i] = new double [this->width*2];
        for(i = 0; i < this->height*2; i++)
        {
            for(j = 0; j < this->width*2; j++)
            {
                unsigned char temp;
                int m = i/2;
                int n = j/2;
                if(i/2 + 1 >= this->height)
                {
                    m = this->height-1 - 1;
                }
                if(j/2+1>=this->width)
                {
                    n = this->width-1-1;
                }
                if(i/2+1>=this->height && j/2 +1 >= this->width)
                {
                    m = this->height-1-1;
                    n = this->width-1-1;
                }
                if(i%2!=0 && j%2==0)//说明是在偶数行，奇数烈上!
                {
                    temp = (data_1[i/2][j/2]+data_1[m+1][j/2])/2;
                }
                if(j%2!=0&&i%2==0)
                {
                    temp = (data_1[i/2][j/2]+data_1[i/2][n+1])/2;
                }
                if(i%2!=0&&j%2!=0)
                {
                    temp = (data_1[i/2][j/2]+data_1[i/2][n+1]+data_1[n+1][j/2]+data_1[i/2][j/2])/2;
                }
                if(j%2==0&&i%2==0)
                {
                    temp = data_1[i/2][j/2];
                }
                this->data[i][j] = temp;
            }
        }

        for(i = 0; i < height/2; i++)
            delete []data_1[i];
        delete []data_1;
    }
    else if(code == 0)
    {
        int i;
        int j;
        double **original_data = this->data;
        this->data = new double *[this->height / 2];
        for (i = 0; i < this->height / 2; i++)
            this->data[i] = new double[this->width / 2];
        for (i = 0; i < this->height / 2; i++)
        {
            for (j = 0; j < this->width / 2; j++)
            {
                 this->data[i][j] = original_data[2 * i][2 * j];
            }
        }
        this->height /= 2;
        this->width /= 2;

        for (i = 0; i < this->height * 2; i++)
            delete[] original_data[i];
        delete[] original_data;
    }
}

void Image::Cut(int x1, int y1, int x2, int y2)
{
    int i;
    int j;

    double **original_data = this->data;

    this->data = new double *[abs(x1 - x2) + 1];
    for (i = 0; i < abs(x1 - x2) + 1; i++)
        this->data[i] = new double[abs(y1 - y2) + 1];

    for (i = 0; i < abs(x1 - x2) + 1; i++)
    {
        for (j = 0; j < abs(y1 - y2) + 1; j++)
        {
            this->data[i][j] = original_data[x1 + i][y1 + j];
        }
    }

    for (i = 0; i < this->height; i++)
        delete[] original_data[i];
    delete[] original_data;

    this->height = abs(x1 - x2) + 1;
    this->width = abs(y1 - y2) + 1;
}

void Image::Rotate(int degree)
{
    while (degree < 0)
        degree += 360;

    degree = degree % 360;

    int num = degree / 90;
    switch (num)
    {
    case 0:
        break;
    case 1:
    {
        int i;
        int j;

        double **o_data = this->data;

        this->data = new double *[this->width];
        for (i = 0; i < this->width; i++)
            this->data[i] = new double[this->height];

        for (i = 0; i < this->height; i++)
        {
            for (j = 0; j < this->width; j++)
            {
                this->data[j][i] = o_data[i][j];
            }
        }

        int temp;
        temp = this->height;
        this->height = this->width;
        this->width = temp;
    }
    break;
    case 2:
    {
        int i;
        int j;

        double**o_data = this->data;

        this->data = new double *[this->height];
        for (i = 0; i < this->height; i++)
            this->data[i] = new double[this->width];

        for (i = 0; i < this->height; i++)
        {
            for (j = 0; j < this->width; j++)
            {
                this->data[this->height - 1 - i][this->width - 1 - j] = o_data[i][j];
            }
        }
    }
    break;
    case 3:
    {
        int i;
        int j;

        double **o_data = this->data;

        this->data = new double *[this->width];
        for (i = 0; i < this->width; i++)
            this->data[i] = new double[this->height];

        for (i = 0; i < this->height; i++)
        {
            for (j = 0; j < this->width; j++)
            {
                this->data[j][this->height - 1 - i] = o_data[i][j];
            }
        }

        int temp;
        temp = this->height;
        this->height = this->width;
        this->width = temp;
    }
    break;
    }
}

double Image::Mean()
{
    double mean = 0;

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            mean += this->data[i][j];
        }
    }
    mean /= this->height * this->width;

    return mean;
}

double Image::Variance()
{
    double mean = Mean();
    double var = 0;

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            var += (mean - this->data[i][j]) * (mean - this->data[i][j]);
        }
    }
    var /= this->height * this->width;

    return var;
}

Image Image::operator-()
{
    Image img(this->height, this->width);

    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
        {
            img.data[i][j] = 255 - this->data[i][j];
        }

    return img;
}

Image Image::gray2bw(double t)
{
    Image img(this->height, this->width);
    this->Normalize();
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
        {
            if (this->data[i][j] > t)
            {
                img.data[i][j] = 255;
            }
            else
            {
                img.data[i][j] = 0;
            }
        }

    return img;
}
