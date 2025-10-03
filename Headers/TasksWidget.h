#ifndef MAINWIDGET_H
#define MANIWIDGET_H

#include "LabelWidget.h"


class TasksWidget : public QWidget {
	Q_OBJECT
	enum { LINES_COUNT = 5 };
	int currentLine {0};
	bool _edit_mode {false};
	LabelWidget** LArray {nullptr};
	QGridLayout* g_layout {nullptr};	
public:
	TasksWidget(QWidget* parent);
	~TasksWidget() { }

	int getcount() { return LINES_COUNT; }
	int getEditInd() { return LArray[0]->getEditInd(); }
	void addData(QString qstr);
	void delData(int lineind);
	void setEditMode(bool var);
	void dataProcessing(QString qstr);
	bool isEditMode() { return _edit_mode; }
	QString getEditingText();

public slots:
	void call_del_func() { delData(LArray[0]->getDelInd()); }
	void call_tasks_edit_func() { emit call_page_edit_func(); }

signals:
	void data_adding_finished();
	void call_page_edit_func();
	void edit_mode_finished();
};


#endif
