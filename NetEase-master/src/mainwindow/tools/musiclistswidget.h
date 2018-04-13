#ifndef MUSICLISTSWIDGET_H
#define MUSICLISTSWIDGET_H

#include <QWidget>

class QListWidget;
class QListWidgetItem;

class MusicListsWidget : public QWidget
{
	Q_OBJECT
public:
	explicit MusicListsWidget(QWidget *parent = 0);
	~MusicListsWidget();

	QMultiHash<int, QString> listCreatorId() const;

	QString currentList();			//	当前歌单..
	int currentRow();				//	当前row..

	void adjustItem();

    void childList(QWidget *parent);
signals:

public slots:
	void addItem(const QString &item);
	void rmAllItem();

	void setCurrentItem(int index = -1);
	void itemDoubleClicked(QListWidgetItem*);
	void itemDoubleClicked();

private slots:
	void musicListInfo(const QStringList &);

private:
	bool regexp(QString &);

private:
	QListWidget *m_musicList;
    QListWidget *m_recommendList;
    QListWidget *m_createdmusicList;
    int m_currentList;
    QListWidget *initList(QString name);
};

#endif // MUSICLISTSWIDGET_H
