#include "animalistwidget.h"
#include <QDebug>
#include <QPainter>
#include <qlabel.h>
animalistwidget::animalistwidget(QWidget *parent,QList<QWidget *> list, QSize size) :
    QWidget(parent)
{
    setFixedSize(size);
    m_list = list;
    maxshownum = 3;
//    setStyleSheet("background-color:red;");
    if(m_list.count()>=3)
    {
        m_widget_0 = m_list.at(0);
        m_widget_1 = m_list.at(1);
        m_widget_2 = m_list.at(2);
        m_widget_0->setFixedSize(size.width()/3,size.height()/3);
        m_widget_1->setFixedSize(size.width()/3,size.height()/3);
        m_widget_2->setFixedSize(size.width()/3,size.height()/3);

//        m_widget_0->move(size.width()/4-m_widget_0->width()/2+x(),y());
//        m_widget_2->move(size.width()/2-m_widget_1->width()/2+x(),y());
//        m_widget_1->move(size.width()/4*3-m_widget_2->width()/2+x(),y());
    }
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_widget_0);
    layout->addWidget(m_widget_1);
    layout->addWidget(m_widget_2);
    setLayout(layout);

//    connect(m_widget_0,SIGNAL(clicked(bool)),this,SLOT(widget_clicked()));
}



void animalistwidget::mousePressEvent(QMouseEvent *event)
{
    if(!m_isPressed)
    {
        m_isPressed = true;
        m_pos.setX(event->x());
        m_pos.setY(event->y());
    }
}

void animalistwidget::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    QPen pointPen(Qt::red);
//    pointPen.setWidth(6);
//    painter.setPen(pointPen);
//    for(int i=0;i<width();i++)
//    {
//         qDebug()<<i<<line(i);
//        painter.drawPoint(i,line(i));
//    }
}

void animalistwidget::mouseReleaseEvent(QMouseEvent * event)
{
    m_isPressed = false;
}

void animalistwidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed)
    {
        int max_width = width()-m_widget_0->width();
        int move_x ;
        if(event->pos().x()<max_width&&event->pos().x()>0)    //右移
        {
           move_x = event->pos().x();
           m_widget_0->move(move_x,line(move_x));
           move_x += width()/3;
           m_widget_1->move(move_x,line(move_x));
           move_x += width()/3;
           m_widget_2->move(move_x,line(move_x));
        }
    }
    else
    {
        QWidget::mouseMoveEvent(event);
    }
    qDebug()<<event->pos().x();
}

void animalistwidget::widget_clicked()
{
    qDebug()<<"widget_clicked";
}

int animalistwidget::line(int x)
{
    int input_x = x-width()/2;

    return -2*height()*input_x*input_x/(width()*width())+height()-50;
}
