#include "PageWidget.h"
#include <iostream>
#include <QDebug>

PageWidget::PageWidget(char day, char month, int year, QWidget* parent=nullptr) : QWidget(parent)
{
	Datelabel = new QLabel(DateClass(day, month, year).qstr(), this);
	TasksW = new TasksWidget(this);
	InputW = new InputLineW(this);
	v_layout = new QVBoxLayout(this);

	QWidget* WidgetArr[] {Datelabel, TasksW, InputW};
	for(QWidget* W : WidgetArr) v_layout->addWidget(W);

	connect(InputW, SIGNAL(data_recieved()), this, SLOT(data_processing()));
	connect(TasksW, SIGNAL(data_adding_finished()), InputW, SLOT(input_clear()));
	connect(TasksW, SIGNAL(call_page_edit_func()), this, SLOT(call_edit_func()));
	connect(TasksW, SIGNAL(edit_mode_finished()), this, SLOT(finish_edit_mode()));
	connect(this, SIGNAL(clear_input_line()), InputW, SLOT(input_clear()));
}

QString PageWidget::strdata {""};

void PageWidget::data_processing()
{
	TasksW->dataProcessing(InputW->gettext());	
}

void PageWidget::call_edit_func()
{
	TasksW->setEditMode(true);
	InputW->setLabelText(QString(InputLineW::labelEditText).arg(TasksW->getEditInd()));
	InputW->setBtnText(InputLineW::btnEditText);
	InputW->settext(TasksW->getEditingText());
}

void PageWidget::finish_edit_mode()
{	
	TasksW->setEditMode(false);
	InputW->setLabelText(InputLineW::labelDefaultText);
	InputW->setBtnText(InputLineW::btnDefaultText);
	emit clear_input_line();
}



