#include "TasksWidget.h"

TasksWidget::TasksWidget(QWidget* parent=nullptr) : QWidget(parent)
{
	LArray = new LabelWidget*[LINES_COUNT];
	for(int i{}; i < LINES_COUNT; i++)
		LArray[i] = new LabelWidget(this);

	g_layout = new QGridLayout(this);
	
	for(int i{}; i < LINES_COUNT; i++)
		g_layout->addWidget(LArray[i]);
}
