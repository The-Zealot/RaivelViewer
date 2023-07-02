#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QScreen>
#include <QScrollBar>

#include "imagekeeper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setImage(QString file);

public slots:
    void onChooseFolder();
    void onOpenPage();

    void onPageNext();
    void onPagePrev();

private:
    Ui::MainWindow *ui;
    ImageKeeper* _keeper;
};
#endif // MAINWINDOW_H
