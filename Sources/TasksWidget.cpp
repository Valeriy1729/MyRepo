#include "TasksWidget.h"
#include <iostream>

TasksWidget::TasksWidget(QWidget* parent=nullptr) : QWidget(parent)
{
	LArray = new LabelWidget*[LINES_COUNT];
	for(int i{}; i < LINES_COUNT; i++)
		LArray[i] = new LabelWidget(this);


	g_layout = new QGridLayout(this);
	
	for(int i{}; i < LINES_COUNT; i++)
		g_layout->addWidget(LArray[i], i, 0);
}

void TasksWidget::addData(QString qstr)
{
	if(currentLine >= LINES_COUNT) return;
	LArray[currentLine++]->setText(qstr);
}

