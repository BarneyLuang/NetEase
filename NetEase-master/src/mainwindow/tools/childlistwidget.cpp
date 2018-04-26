#include "childlistwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QDebug>
childlistwidget::childlistwidget(QWidget *parent,QLabel *label,QWidget *toolwidget,QListWidget *listwidget) :
    QWidget(parent)
{


    QWidget *mainweidget = new QWidget(this);
    QWidget *title_widget = new QWidget(this);

    title_widget->setFixedWidth(240);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainweidget);

    QHBoxLayout *titleLayout = new QHBoxLayout(title_widget);
    titleLayout->addWidget(label,0,Qt::AlignLeft );

    if(toolwidget!=NULL)
    {
      titleLayout->addWidget(toolwidget,0,Qt::AlignRight );
    }
    listwidget->setContentsMargins(20,0,0,0);
    mainLayout->addWidget(title_widget,0,Qt::AlignLeft);
    mainLayout->addWidget(listwidget,0,Qt::AlignRight );
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addStretch(0);

//    setStyleSheet("background-color:red;");
}



