#ifndef ANIMALISTWIDGET_H
#define ANIMALISTWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QList>
#include <QSize>
#include <QHBoxLayout>
class animalistwidget : public QWidget
{
    Q_OBJECT
public:
    explicit animalistwidget(QWidget *parent, QList<QWidget *> list, QSize size);
private:
    bool m_isPressed;
    QPoint m_pos;
    QList<QWidget *> m_list;
    int src_x;
    int maxshownum;
    QWidget *m_widget_0;
    QWidget *m_widget_1;
    QWidget *m_widget_2;
    int line(int x);
signals:


public slots:

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
private slots:
    void widget_clicked();
};

#endif // ANIMALISTWIDGET_H
