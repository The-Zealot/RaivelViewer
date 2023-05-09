#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QObject>

class ImageModel
{
    Q_OBJECT
public:
    ImageModel();
    void setImages(const QStringList &paths);
    void changeImage();
    void clear();

signals:
    void changedImage();

private:
    QStringList _images;
    quint32 _imageIndex;
};

#endif // IMAGEMODEL_H
