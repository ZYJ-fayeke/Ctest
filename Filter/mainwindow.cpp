#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Image.h"
#include "Matrix.h"
#include "MeanFilter.h"
#include "Filter.h"
#include "MediaFilter.h"
#include <QFileDialog>
#include <QString>
using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QImage image;
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    if( filename != "" )
    {
        if( image.load(filename) )
        {
            ui->label->setPixmap(QPixmap::fromImage(image));
        }
    }
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    //Image img;
    //img.Read(ch);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    img.Flip(1);
    //将img所指的data里面的数据读到mat中？然后显示
    Mat img2 = Mat(img.height, img.width, CV_8UC1);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img));
}

void MainWindow::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    img.Flip(0);
    //将img所指的data里面的数据读到mat中？然后显示
    Mat img2 = Mat(img.height, img.width, CV_8UC1);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    double mean;
    mean = img.Mean();
    ui->text->append("均值："+QString::number(mean));
   /* int x = ui->lineEdit->text().toInt();
    int y = ui->lineEdit_2->text().toInt();
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    //img.Resize(x,y);
    //将img所指的data里面的数据读到mat中？然后显示
    Mat img2 = Mat(x, y, CV_8UC1);
    uchar *ptr = NULL;
    for(int i = 0; i < x;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < y; j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img));*/
}
void MainWindow::on_pushButton_5_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    img.Resize(1);
    Mat img2 = Mat(img.height*2, img.width*2, CV_8UC1);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height*2;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width*2; j++)
        {

            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img));
}

void MainWindow::on_pushButton_6_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    img.Resize(0);
    Mat img2 = Mat(img.height, img.width, CV_8UC1);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {

            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img));
}

void MainWindow::on_pushButton_8_clicked()
{
    int x1 = ui->line1_x->text().toInt();
    int y1 = ui->line1_y->text().toInt();
    int x2 = ui->line2_x->text().toInt();
    int y2 = ui->lineEdit_3->text().toInt();

    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    img.Cut(x1,y1,x2,y2);
    Mat img2 = Mat(abs(x2-x1), abs(y2-y1), CV_8UC1);
    uchar *ptr = NULL;
    for(int i = 0; i < abs(x2-x1);i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < abs(y2-y1); j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img));
}

void MainWindow::on_pushButton_7_clicked()
{
    Image img4("Word1.bmp");
    Image img5("Fruits.bmp");

    Mat img2 = Mat(img4.height, img4.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img4.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img4.width; j++)
        {
            ptr[j] = img4.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Mat img1 = Mat(img5.height, img5.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img5.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img5.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = img5.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_9->setPixmap(QPixmap::fromImage(Img5));

    Image t(Add(img4,img5));
    Mat imgt = Mat(t.height, t.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < t.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < t.width; j++)
        {
            ptrt[j] = t.data[i][j];
        }
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));
}


void MainWindow::on_pushButton_11_clicked()
{
    Image img4("Lena1.bmp");
    Image img5("Fruits.bmp");


    Mat img2 = Mat(img4.height, img4.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img4.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img4.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr[j] = img4.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Mat img1 = Mat(img5.height, img5.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img5.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img5.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = img5.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_9->setPixmap(QPixmap::fromImage(Img5));

    img4.Cat(img5,1);
    Mat imgt = Mat(img4.height, img4.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < img4.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < img4.width; j++)
        {
            ptrt[j] = img4.data[i][j];
        }
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));
}

void MainWindow::on_pushButton_12_clicked()
{
    Image img4("Lena1.bmp");
    Image img5("Fruits.bmp");

    Mat img2 = Mat(img4.height, img4.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img4.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img4.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr[j] = img4.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Mat img1 = Mat(img5.height, img5.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img5.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img5.width; j++)
        {
            ptr5[j] = img5.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_9->setPixmap(QPixmap::fromImage(Img5));

    img4.Cat(img5,2);
    Mat imgt = Mat(img4.height, img4.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < img4.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < img4.width; j++)
        {
            ptrt[j] = img4.data[i][j];
        }
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));
}

void MainWindow::on_pushButton_9_clicked()
{
    Image img4("Word1.bmp");
    Image img5("Fruits.bmp");

    Mat img2 = Mat(img4.height, img4.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img4.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img4.width; j++)
        {
            ptr[j] = img4.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Mat img1 = Mat(img5.height, img5.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img5.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img5.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = img5.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_9->setPixmap(QPixmap::fromImage(Img5));

    Image t(Sub(img4,img5));
    Mat imgt = Mat(t.height, t.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < t.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < t.width; j++)
            ptrt[j] = t.data[i][j];
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));
}

void MainWindow::on_pushButton_13_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    img.Transpose();

    Mat imgt = Mat(img.height, img.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
            ptrt[j] = img.data[i][j];
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));
}

void MainWindow::on_pushButton_14_clicked()
{
    //打开高斯白噪！
    Image img("Lena_gaussian.bmp");
    Mat img2 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Filter *filter = NULL;
    filter = new MeanFilter(5);
    Image result;
    result = filter->Filtering(img);
        //result_mean.Show("Mean");

    Mat img1 = Mat(result.height, result.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < result.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < result.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = result.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img5));
    delete filter;
}

void MainWindow::on_pushButton_15_clicked()
{
    Image img("Lena_salt_and_pepper.bmp");
    Mat img2 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Filter *filter = NULL;
    filter = new MeanFilter(5);
    Image result;
    result = filter->Filtering(img);
        //result_mean.Show("Mean");

    Mat img1 = Mat(result.height, result.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < result.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < result.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = result.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img5));
    delete filter;
}


void MainWindow::on_pushButton_16_clicked()
{
    Image img("Lena_gaussian.bmp");
    Mat img2 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Filter *filter = NULL;
    filter = new MedianFilter(5);
    Image result;
    result = filter->Filtering(img);

    Mat img1 = Mat(result.height, result.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < result.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < result.width; j++)
        {
            ptr5[j] = result.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img5));
    delete filter;
}
void MainWindow::on_pushButton_17_clicked()
{
    Image img("Lena_salt_and_pepper.bmp");
    Mat img2 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Filter *filter = NULL;
    filter = new MedianFilter(5);
    Image result;
    result = filter->Filtering(img);

    Mat img1 = Mat(result.height, result.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < result.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < result.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = result.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img5));
    delete filter;
}
void MainWindow::on_pushButton_18_clicked()
{
    Image img("scene2_bg.bmp");
    img.Read("scene2_bg.bmp");
    Mat img1 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = img.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img5));

    int num = ui->num1->text().toInt();
    Image t(img+num);
    Mat imgt = Mat(t.height, t.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < t.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < t.width; j++)
            ptrt[j] = t.data[i][j];
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));

}

void MainWindow::on_pushButton_20_clicked()
{
    Image img("scene2_bg.bmp");
    img.Read("scene2_bg.bmp");
    /*Mat img2 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));*/

    img++;
    Mat img1 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = img.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img5));

}

void MainWindow::on_pushButton_21_clicked()
{
    Image img("scene2_bg.bmp");
    img.Read("scene2_bg.bmp");
    /*Mat img2 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));*/

    img--;
    Mat img1 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = img.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Img5));
}

void MainWindow::on_pushButton_19_clicked()
{
    Image img2("scene2_fg.bmp");
    img2.Read("scene2_fg.bmp");
    /*Mat img_2 = Mat(img2.height, img2.width, CV_8UC3);
    uchar *ptr_2 = NULL;
    for(int i = 0; i < img2.height;i++)
    {
        ptr_2 = img_2.ptr<uchar>(i);
        for(int j = 0; j < img2.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr_2[j] = img2.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img_2.data), img_2.cols, img_2.rows, img_2.cols*img_2.channels(), QImage::Format_Indexed8);
    ui->label_9->setPixmap(QPixmap::fromImage(Img));*/

    int num = ui->num2->text().toInt();
    Image t(img2-num);

    Mat imgt = Mat(t.height, t.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < t.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < t.width; j++)
            ptrt[j] = t.data[i][j];
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));


}

void MainWindow::on_pushButton_10_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    Mat img2 = Mat(img.height, img.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {
            ptr[j] = img.data[i][j];
        }
     }
     QImage Img;
     Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
     ui->label->setPixmap(QPixmap::fromImage(Img));
}

void MainWindow::on_pushButton_22_clicked()
{
    Image img4("Word1.bmp");
    Image img5("Fruits.bmp");

    Mat img2 = Mat(img4.height, img4.width, CV_8UC3);
    uchar *ptr = NULL;
    for(int i = 0; i < img4.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img4.width; j++)
        {
            ptr[j] = img4.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));

    Mat img1 = Mat(img5.height, img5.width, CV_8UC3);
    uchar *ptr5 = NULL;
    for(int i = 0; i < img5.height;i++)
    {
        ptr5 = img1.ptr<uchar>(i);
        for(int j = 0; j < img5.width; j++)
        {
            //img.data[i][j] = img2.at<uchar>(i,j);
            ptr5[j] = img5.data[i][j];
        }
    }
    QImage Img5;
    Img5 = QImage((const uchar*)(img1.data), img1.cols, img1.rows, img1.cols*img1.channels(), QImage::Format_Indexed8);
    ui->label_9->setPixmap(QPixmap::fromImage(Img5));

    Image t(Sub(img5,img4));
    Mat imgt = Mat(t.height, t.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < t.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < t.width; j++)
            ptrt[j] = t.data[i][j];
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));
}

void MainWindow::on_pushButton_23_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    double val;
    val = img.Variance();
    ui->text->append("方差："+QString::number(val));
}

void MainWindow::on_pushButton_24_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        "C:/dev/",
                                                        tr("Image file(*.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);

    double t = ui->t->text().toInt();
    img.gray2bw(t);
    Mat imgt = Mat(img.height, img.width, CV_8UC3);
    uchar *ptrt = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptrt = imgt.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
            ptrt[j] = img.data[i][j];
    }
    QImage Imgt;
    Imgt = QImage((const uchar*)(imgt.data), imgt.cols, imgt.rows, imgt.cols*imgt.channels(), QImage::Format_Indexed8);
    ui->label_2->setPixmap(QPixmap::fromImage(Imgt));
}

void MainWindow::on_pushButton_25_clicked()
{
    int degree = ui->deg->value();
    QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("open image"),
                                                        ".",
                                                        tr("Image file(*.png *.jpg *.bmp)"));
    char*  ch;
    QByteArray ba = filename.toLatin1(); // must
    ch=ba.data();//这几步都是将Qstring转换为char *

    Image img;
    img.Read(ch);
    img.Rotate(degree);
    Mat img2 = Mat(img.height, img.width, CV_8UC1);
    uchar *ptr = NULL;
    for(int i = 0; i < img.height;i++)
    {
        ptr = img2.ptr<uchar>(i);
        for(int j = 0; j < img.width; j++)
        {

            ptr[j] = img.data[i][j];
        }
    }
    QImage Img;
    Img = QImage((const uchar*)(img2.data), img2.cols, img2.rows, img2.cols*img2.channels(), QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(Img));
}
