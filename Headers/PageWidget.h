#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include <QVBoxLayout>
#include "InputLineWidget.h"
#include "TasksWidget.h"
#include "DateClass.h"


class PageWidget : public QWidget {
	Q_OBJECT
	QLabel* Datelabel {nullptr};
	TasksWidget* TasksW {nullptr};
	InputLineW* InputW {nullptr};
	QVBoxLayout* v_layout {nullptr};

public:
	PageWidget(char day, char month, int year, QWidget* parent);
	~PageWidget() { }
};


#endif
