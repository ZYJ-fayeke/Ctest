#ifndef MEDIAFILTER_H
#define MEDIAFILTER_H

#include "Filter.h"

class MedianFilter : public Filter
{
public:
    MedianFilter(int size);
    virtual ~MedianFilter();
    virtual Matrix Filtering(const Matrix &input);  //
};

#endif // MEDIAFILTER_H
