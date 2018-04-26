#include "musiclistswidget.h"
#include "../../configure/configure.h"
#include "../../network/networkmanage.h"
#include "../../mediaplayer/mediaplayer.h"
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollBar>
#include <QRegExp>
#include "childlistwidget.h"
#include "QPushButton"
#include "QtDebug"
MusicListsWidget::MusicListsWidget(QWidget *parent) : QWidget(parent)
{
	setFixedSize(musicListWidgetSize);
    //setAttribute(Qt::WA_TranslucentBackground);
//    setStyleSheet("background-color:red;");
    m_musicList = initList("MusicsList");
    m_musicList->addItem(new QListWidgetItem(QIcon(":/menu_icon/netease"),"发现"));
    m_musicList->addItem(new QListWidgetItem(QIcon(":/menu_icon/netease"),"MV"));
    m_musicList->setFixedHeight(m_musicList->count()*25+20);
    qDebug()<<m_musicList->count();


    m_recommendList = initList("MineList");
    m_recommendList->addItem(new QListWidgetItem(QIcon(":/menu_icon/netease"),"本地"));
    m_recommendList->addItem(new QListWidgetItem(QIcon(":/menu_icon/netease"),"Mine"));
    m_recommendList->setFixedHeight(m_musicList->count()*25+20);

    QLabel *recommend_title = new QLabel("推荐");
    recommend_title->setObjectName("RecommendTitle");

    QLabel *mymusic_title = new QLabel("我的");
    mymusic_title->setObjectName("MusicTitle");

    QPushButton *button = new QPushButton("button");

    childlistwidget *recommend_list = new childlistwidget(this,recommend_title,button,m_recommendList);
    childlistwidget *mine_list  = new childlistwidget(this,mymusic_title,NULL,m_musicList);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(recommend_list);
    mainLayout->addWidget(mine_list);

    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
//    mainLayout->addStretch(0);
	connect(NetworkManage::sharedNetworkManage(), SIGNAL(musicListInfo(QStringList)),
			this, SLOT(musicListInfo(QStringList)));

	m_currentList = 0;

}

MusicListsWidget::~MusicListsWidget()
{

}

QString MusicListsWidget::currentList()
{
	return m_musicList->item(m_currentList)->text();
}

int MusicListsWidget::currentRow()
{
	return m_currentList;
}

void MusicListsWidget::addItem(const QString &item)
{
	m_musicList->addItem(item);
}

void MusicListsWidget::rmAllItem()
{
	for (int i = m_musicList->count() - 1; i > 2; i--)
	{
		QListWidgetItem *item = m_musicList->takeItem(i);
		delete item;
		item = Q_NULLPTR;
	}
}


void MusicListsWidget::setCurrentItem(int index)
{
	m_musicList->setCurrentRow(index);
}




void MusicListsWidget::adjustItem()
{
	QListWidgetItem *currentItem = m_musicList->currentItem();
	for (int i = m_musicList->count() - 1; i >= 0; i--)
	{
		QListWidgetItem *item = m_musicList->item(i);
		QString text = item->text();
		if (regexp(text))
			item->setText(text);
		if (currentItem == item)
		{
			item->setText(">>> " + item->text());
			m_currentList = i;
		}
	}
}

bool MusicListsWidget::regexp(QString &text)
{
	QRegExp rx(">>> (.*)");
	if (rx.indexIn(text, 0) == -1)
		return false;
	text = rx.cap(1);
	return true;
}

void MusicListsWidget::itemDoubleClicked()
{
	itemDoubleClicked(m_musicList->currentItem());
}

void MusicListsWidget::itemDoubleClicked(QListWidgetItem */*item*/)
{
	adjustItem();
	int index = m_musicList->currentRow();
	if (0 == index)
	{
		//	获取每日推荐...
		NetworkManage::sharedNetworkManage()->recommed();
	}
	else if (1 == index)
	{
		// 私人FM..
		NetworkManage::sharedNetworkManage()->randioFM();
	}
	else if (2 == index)
	{
		//	搜索结果...
		NetworkManage::sharedNetworkManage()->search("");
	}
	else
	{
		QVector<int> vector = MediaPlayer::sharedMediaPlayer()->musicListId();
		NetworkManage::sharedNetworkManage()->musicListDetails(vector[index - 3]);
	}
}

void MusicListsWidget::musicListInfo(const QStringList &list)
{
	QStringList::const_iterator it = list.begin();
	while (it != list.end())
	{
		addItem(*it);
		++it;
	}
	m_musicList->setCurrentRow(0);
	NetworkManage::sharedNetworkManage()->userHeadImage();
	adjustItem();
}



QListWidget *MusicListsWidget::initList(QString name)
{
    QListWidget * listwidget = new QListWidget;
    listwidget->setObjectName(name);
    listwidget->horizontalScrollBar()->setVisible(false);
    listwidget->verticalScrollBar()->setVisible(false);


    listwidget->setContentsMargins(0, 0, 0, 0);
    listwidget->setSpacing(0);

    connect(listwidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(itemDoubleClicked(QListWidgetItem*)));

    return listwidget;
}






