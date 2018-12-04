#ifndef TIFFIMG_H
#define TIFFIMG_H

#include <QWidget>
#include <QGestureEvent>
#include <QPinchGesture>
#include <QImage>
#include <QWheelEvent>
#include <QPanGesture>
#include <QMouseEvent>

class tiffImg : public QWidget
{
    Q_OBJECT

public:
    tiffImg(QWidget *parent);
    tiffImg(QWidget *parent, QString path);
    ~tiffImg();

    void    loadImg(QString path);

private:
    ///// image /////
    QImage image;
    QImage scaleImage;
    ////mouse position////
    bool mousePress;
//    bool m_bMovble;
    QPoint start;
    ///// image position and scale /////
    float imgX;
    float imgY;
    float scaleFactor;
    int horizontalOffset;
    int verticalOffset;

    int m_iXRange;
    int m_iYRange;

protected:
    void paintEvent(QPaintEvent *);
    /////Gesture////
#ifdef ANDROID
    bool event(QEvent *event);
    void pinchTriggered(QPinchGesture *); //缩放
    bool gestureEvent(QGestureEvent *);
#endif
    /////mouse events/////
#ifdef WIN32
    void wheelEvent(QWheelEvent *);
#endif
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // TIFFIMG_H
