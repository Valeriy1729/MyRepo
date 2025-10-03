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
		connect(LArray[i], SIGNAL(edit()), this, SLOT(call_tasks_edit_func()));
	}

}

void TasksWidget::delData(int lineind)
{	
	if(currentLine >= LINES_COUNT) currentLine = LINES_COUNT;
	for(int i {lineind}; i < currentLine - 1; i++)
		LArray[i]->setText(LArray[i + 1]->getText());

	LArray[currentLine - 1]->setText(SPACES);
	LArray[currentLine - 1]->setEnable(false);
	currentLine--;
}

void TasksWidget::setEditMode(bool var)
{
	for(int i{}; i < LINES_COUNT; i++) {
		if(var == true) {
			if(i == LArray[0]->getEditInd()) continue;
			LArray[i]->setEnable(false);
		} else {
			if(LArray[i]->getText() != QString(SPACES))
				LArray[i]->setEnable(true);
		}
	}
	_edit_mode = var;
}

QString TasksWidget::getEditingText() { return LArray[getEditInd()]->getText(); }

void TasksWidget::dataProcessing(QString qstr)
{
	if(isEditMode()) {
		LArray[getEditInd()]->setText(qstr);
		emit edit_mode_finished();
	} else {
		if(currentLine >= LINES_COUNT) return;
		LArray[currentLine++]->setText(qstr);
		emit data_adding_finished();
	}

}








