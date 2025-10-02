#ifndef MAINWIDGET_H
#define MANIWIDGET_H

#include "LabelWidget.h"


class TasksWidget : public QWidget {
	Q_OBJECT
	enum { LINES_COUNT = 5 };
	LabelWidget** LArray {nullptr};
	QGridLayout* g_layout {nullptr};	
public:
	TasksWidget(QWidget* parent);
	~TasksWidget() { }
};


#endif
