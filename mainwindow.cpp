#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _keeper = new ImageKeeper();

    connect(ui->toolButtonChooseFolder, &QAbstractButton::clicked, this, &MainWindow::onChooseFolder);
    connect(ui->buttonOpenPage, &QAbstractButton::clicked, this, &MainWindow::onOpenPage);
    connect(ui->buttonPageNext, &QAbstractButton::clicked, this, &MainWindow::onPageNext);
    connect(ui->buttonPagePrev, &QAbstractButton::clicked, this, &MainWindow::onPagePrev);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _keeper;
}

void MainWindow::setImage(QString file)
{
    QPixmap pixmap(file);
    ui->image->setPixmap(pixmap);

    if (!ui->checkBoxFixedSize->isChecked())
    {
        this->showNormal();
        QSize screenSize = qApp->screens()[0]->size();

        int s_width = screenSize.width();
        int s_height = screenSize.height();

        int p_width = pixmap.width() > s_width ? s_width : pixmap.width();
        this->setGeometry((s_width - p_width) / 2, 150, p_width, s_height * 0.7f);
    }

    ui->statusBar->showMessage(file);
}

void MainWindow::onChooseFolder()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Choose folder with images", QDir::currentPath() + "/source");
    ui->editFolderPath->setText(dir);

    bool keeperIsEmpty = _keeper->openFolder(ui->editFolderPath->text().toUtf8());

    ui->buttonOpenPage->setEnabled(keeperIsEmpty);
    ui->buttonPageNext->setEnabled(keeperIsEmpty);
    ui->buttonPagePrev->setEnabled(keeperIsEmpty);

    ui->spinBoxPageNumber->setMaximum(_keeper->getImageCount());
    ui->spinBoxPageNumber->setMinimum(1);

    if (_keeper->getImageCount() != 0)
    {
        onOpenPage();
    }
}

void MainWindow::onOpenPage()
{
    QString image = _keeper->getImageName(ui->spinBoxPageNumber->value() - 1);
    setImage(image);
}

void MainWindow::onPageNext()
{
    ui->spinBoxPageNumber->stepUp();
    onOpenPage();
}

void MainWindow::onPagePrev()
{
    ui->spinBoxPageNumber->stepDown();
    onOpenPage();
}

