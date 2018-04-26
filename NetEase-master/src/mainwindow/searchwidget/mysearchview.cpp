#include "mysearchview.h"
#include "QLineEdit"
#include "../../toolwidgets/funcbutton.h"
mysearchview::mysearchview(QWidget *parent) :
    QLineEdit(parent)
{
    FuncButton *searchButton = new FuncButton(":/buttons/search_btn", this);
   // connect(searchButton, SIGNAL(clicked()), this, SLOT(searchClicked()));

    searchButton->setCapturEnterEvent(false);
    searchButton->setToolTip(tr("搜索"));

    setPlaceholderText(tr("搜索"));
    setTextMargins(15,0,0,0);
    QHBoxLayout *searLayout = new QHBoxLayout;

    searLayout->addStretch();
    searLayout->addWidget(searchButton);
    setFixedHeight(searchButton->height()+15);

    setLayout(searLayout);
    setStyleSheet("height:35px;border:1px solid #eaeaea;border-radius:14px;");
}
