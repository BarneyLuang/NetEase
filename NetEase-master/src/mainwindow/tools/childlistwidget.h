#ifndef CHILDLISTWIDGET_H
#define CHILDLISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
class childlistwidget : public QWidget
{
    Q_OBJECT
public:

    void addItem();
    explicit childlistwidget(QWidget *parent, QLabel *label, QWidget *toolwidget, QListWidget *listwidget);
signals:

public slots:

};

#endif // CHILDLISTWIDGET_H
