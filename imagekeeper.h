#ifndef IMAGEKEEPER_H
#define IMAGEKEEPER_H

#include <QObject>
#include <QDir>

class ImageKeeper
{
public:
    ImageKeeper(const char* path = nullptr);

    bool openFolder(const char* path);
    QString getImageName(int index);
    int getImageCount();

protected:
    void loadImages();

private:
    QString _path;
    QVector<QString> _images;
};

#endif // IMAGEKEEPER_H
