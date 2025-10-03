#ifndef MAINWIDGET_H
#define MANIWIDGET_H

#include "LabelWidget.h"


class TasksWidget : public QWidget {
	Q_OBJECT
	enum { LINES_COUNT = 5 };
	int currentLine {0};
	LabelWidget** LArray {nullptr};
	QGridLayout* g_layout {nullptr};	
public:
	TasksWidget(QWidget* parent);
	~TasksWidget() { }

	int getcount() { return LINES_COUNT; }
	void addData(QString qstr);
	void delData(int lineind);

public slots:
	void call_del_func() { delData(LArray[0]->getdelind()); }
};


#endif
