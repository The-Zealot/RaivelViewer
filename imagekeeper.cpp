#include "imagekeeper.h"

ImageKeeper::ImageKeeper(const char *path)
{
    _path = path;

    loadImages();
}

bool ImageKeeper::openFolder(const char *path)
{
    _path = path;

    loadImages();
    if (_images.isEmpty())
    {
        return false;
    }
    return true;
}

QString ImageKeeper::getImageName(int index)
{
    if (index >= _images.size() or index < 0)
    {
        return "";
    }
    return _path + "/" + _images[index];
}

int ImageKeeper::getImageCount()
{
    return _images.size();
}

void ImageKeeper::loadImages()
{
    QDir dir(_path);
    dir.setNameFilters({"*.png", "*.jpg", "*.jpeg", "*.bmp"});
    _images = dir.entryList(QDir::Files);
}
