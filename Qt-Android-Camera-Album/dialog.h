#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtWidgets>
#ifdef Q_OS_ANDROID
#include <QtAndroidExtras>
#endif
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QButtonGroup>
#include <QStackedWidget>
#include "tiffimg.h"

class Dialog : public tiffImg
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QButtonGroup* btnGroup;
    QPushButton* captureBtn;
    QPushButton* albumBtn;
    QPushButton* processBtn;

protected slots:
#ifdef Q_OS_ANDROID
    void btnClicked(int);
#endif
};

#endif // MAINWINDOW_H
