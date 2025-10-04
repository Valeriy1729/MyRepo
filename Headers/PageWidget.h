#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include <QVBoxLayout>
#include <QFont>
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

	void load() { TasksW->loadFromSettings(); }
	void save() { TasksW->saveList(); }
	void clearMem() { TasksW->clearSaves(); }

public slots:
	void data_processing();
	void call_edit_func();
	void finish_edit_mode();

signals:
	void clear_input_line();
};


#endif
