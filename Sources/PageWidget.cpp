#include "PageWidget.h"

PageWidget::PageWidget(char day, char month, int year, QWidget* parent=nullptr) : QWidget(parent)
{
	Datelabel = new QLabel(DateClass(day, month, year).qstr(), this);
	TasksW = new TasksWidget(this);
	InputW = new InputLineW(this);
	v_layout = new QVBoxLayout(this);

	QWidget* WidgetArr[] {Datelabel, TasksW, InputW};
	for(QWidget* W : WidgetArr) v_layout->addWidget(W);

}
