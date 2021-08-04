#include "dialog.hpp"
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <opencv2/highgui/highgui.hpp>

#include "drawdigits.hpp"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    numInput = new QLineEdit();
    saveBtn = new QPushButton("save");
    saveBtn->setFixedSize(50, 30);
    imgLbl = new QLabel();
    imgLbl->setFixedSize(COLUMNS, ROWS);
    this->setFixedSize(300, 150);

    lblDraw(cv::Mat(ROWS, COLUMNS, CV_8UC3, BLACK));

    connect(numInput, SIGNAL(textChanged(const QString&)),
            this, SLOT(numInputChanged(const QString&)));
    connect(saveBtn, SIGNAL(clicked(bool)), this, SLOT(saveBtnClicked()));
    mainLay = new QVBoxLayout(this);
        mainLay->addWidget(numInput);
        mainLay->addWidget(imgLbl);
        mainLay->addWidget(saveBtn);
}

void Dialog::numInputChanged(const QString& inp)
{
    const int len = inp.size();
    QVector<int> digits;
    digits.reserve(len);
    for (int i = 0; i < len; ++i)
        digits.append(QString(inp[i]).toInt());
    img = cv::Mat(ROWS, COLUMNS, CV_8UC3, BLACK);

    if (digits.empty() || digits.size() > DIGITS_NUMBER - 1) {
        numInput->clear();
        lblDraw(img);
        return;
    }

    for (int i = 0; i < digits.size(); ++i) {
        int ofs = DIGIT_OFFSET * i + DIGIT_SPACING;
        auto handler = draw_digits_engine::engine.find(digits[i]);
        if (handler == draw_digits_engine::engine.end()) {
            return;
        }
        (handler->second)(img, ofs);
    }
    lblDraw(img);

}

void Dialog::lblDraw(const cv::Mat &source)
{
    QImage img = QImage(static_cast<const unsigned char*>(source.data),
                         source.cols,
                         source.rows,
                         static_cast<int>(source.step),
                         QImage::Format_RGB888);
    QPixmap pixmap(COLUMNS, ROWS);
    pixmap.convertFromImage(img.rgbSwapped());
    imgLbl->setPixmap(pixmap);
}

void Dialog::saveBtnClicked()
{
    const QString initialPath = QDir::currentPath() + "/new.jpg";
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save"),
                                                          initialPath,
                                                          tr("Images (*.png *.jpg)"));
    if (fileName.isEmpty())
        return;

    QByteArray ba = fileName.toLocal8Bit();
    char *charFileName = static_cast<char *>(strdup(ba.constData()));

    if(!this->img.empty())
        cv::imwrite(charFileName, this->img);
}

Dialog::~Dialog()
{

}
