#include "Dialog.h"
#include <QDebug>
#include <QDesktopWidget>

QString selectedFileName;

#ifdef Q_OS_ANDROID
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_com_amin_QtAndroidGallery_QtAndroidGallery_fileSelected(JNIEnv */*env*/,
                                                             jobject /*obj*/,
                                                             jstring results)
{
    selectedFileName = QAndroidJniObject(results).toString();
}

#ifdef __cplusplus
}
#endif
#endif

Dialog::Dialog(QWidget *parent) :
    tiffImg(parent)
{
    QDesktopWidget * deskTop = qApp->desktop();
    QRect rect = deskTop->availableGeometry();
    this->setFixedSize(rect.width(), rect.height());
    this->loadImg(":/img/src/background.jpg");

    QVBoxLayout* mainl = new QVBoxLayout(this);
    QGridLayout* mainLay = new QGridLayout();

    captureBtn = new QPushButton("拍照");
    captureBtn->setChecked(true);
    albumBtn = new QPushButton("相册");
    processBtn = new QPushButton("处理");
    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(captureBtn,0);
    btnGroup->addButton(albumBtn,1);
    btnGroup->addButton(processBtn,2);
    btnGroup->setExclusive(true);

    mainLay->addWidget(captureBtn    ,1,0,1,1);
    mainLay->addWidget(albumBtn      ,1,1,1,1);
    mainLay->addWidget(processBtn    ,1,2,1,1);
    mainLay->setRowStretch(0,9);
    mainLay->setRowStretch(1,1);

    mainl->addStretch();
    mainl->addLayout(mainLay);

#ifdef Q_OS_ANDROID
    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(btnClicked(int)));
#endif
}

Dialog::~Dialog()
{

}

#ifdef Q_OS_ANDROID
void Dialog::btnClicked(int btnID)
{
    if(btnID == 0)
    {
        selectedFileName = "#";
        QAndroidJniObject::callStaticMethod<void>("com/amin/QtAndroidGallery/QtAndroidGallery",
                                                  "captureAnImage",
                                                  "()V");
        while(selectedFileName == "#")
            qApp->processEvents();

        if(selectedFileName != "#")
        {
            if(QFile(selectedFileName).exists())
                this->loadImg(selectedFileName);
        }
    }
    else if(btnID == 1)
    {
        selectedFileName = "#";
        QAndroidJniObject::callStaticMethod<void>("com/amin/QtAndroidGallery/QtAndroidGallery",
                                                  "openAnImage",
                                                  "()V");

        while(selectedFileName == "#")
            qApp->processEvents();

        if(QFile(selectedFileName).exists())
            this->loadImg(selectedFileName);
    }
    else if(btnID == 2)
    {
        //处理图片
    }
}
#endif
