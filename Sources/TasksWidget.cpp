#include "TasksWidget.h"
#include <iostream>

TasksWidget::TasksWidget(QWidget* parent=nullptr) : QWidget(parent)
{
	LArray = new LabelWidget*[LINES_COUNT];
	for(int i{}; i < LINES_COUNT; i++)
		LArray[i] = new LabelWidget(this);


	g_layout = new QGridLayout(this);
	
	for(int i{}; i < LINES_COUNT; i++) {
		g_layout->addWidget(LArray[i], i, 0);
		connect(LArray[i], SIGNAL(del()), this, SLOT(call_del_func()));
	}

}

void TasksWidget::addData(QString qstr)
{
	if(currentLine >= LINES_COUNT) return;
	LArray[currentLine++]->setText(qstr);
	emit data_adding_finished();
}

void TasksWidget::delData(int lineind)
{	
	if(currentLine >= LINES_COUNT) currentLine = LINES_COUNT - 1;
	for(int i {lineind}; i < currentLine - 1; i++)
		LArray[i]->setText(LArray[i + 1]->getText());

	LArray[currentLine - 1]->setText(SPACES);
	LArray[currentLine - 1]->setEnable(false);
	currentLine--;
}
