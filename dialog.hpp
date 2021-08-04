#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <opencv2/imgproc/imgproc.hpp>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    QLineEdit *numInput;
    QLabel *imgLbl;
    QVBoxLayout *mainLay;
    QPushButton *saveBtn;
    cv::Mat img;
    void lblDraw(const cv::Mat &source);    
private slots:
    void numInputChanged(const QString& inp);
    void saveBtnClicked();
};
