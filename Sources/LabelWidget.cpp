#include "LabelWidget.h"
#include <iostream>

int LabelWidget::_delete_ind {-1};
int LabelWidget::_edit_ind {-1};

LabelWidget::LabelWidget(QWidget* parent=nullptr) : QWidget(parent)
{
	label = new QLabel(SPACES, this);
	numlabel = new QLabel(QString("Task №%1:").arg(globalNumber++), this);
	editbtn = new QPushButton("edit", this);
	delbtn = new QPushButton("delete", this);
	chbox = new QCheckBox(this);
	g_layout = new QGridLayout(this);

	QWidget* WidgetArr[] {numlabel, chbox, label, editbtn, delbtn};
	int ind {1}, _arrind {0};
	int lengths[] {2, 1, 7, 1, 1};

	for(QWidget* W : WidgetArr) {
		W->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
		g_layout->addWidget(W, 0, ind, 1, lengths[_arrind]);
		ind += lengths[_arrind++];
	}
	
	connect(delbtn, SIGNAL(clicked()), this, SLOT(set_del_index()));
	connect(editbtn, SIGNAL(clicked()), this, SLOT(set_edit_index()));
	setEnable(false);
}

int LabelWidget::globalNumber {0};

void LabelWidget::setText(QString qstr)
{
	label->setText(qstr);
	setEnable(true);
}

QString LabelWidget::getText() { return label->text(); }

void LabelWidget::set_del_index()
{
	_delete_ind = locNumber;
	emit del();
}

void LabelWidget::set_edit_index()
{
	_edit_ind = locNumber;
	emit edit();	
}

void LabelWidget::setEnable(bool var)
{
	editbtn->setEnabled(var);
	delbtn->setEnabled(var);
	chbox->setEnabled(var);
}

