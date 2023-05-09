#include "imagemodel.h"

ImageModel::ImageModel()
{
    _imageIndex = 0;
}

void ImageModel::setImages(const QStringList &paths)
{
    _images = paths;
}

void ImageModel::changeImage()
{
    emit changedImage();
}

void ImageModel::clear()
{
    _images.clear();
}
