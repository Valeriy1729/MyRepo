#include "LabelWidget.h"

LabelWidget::LabelWidget(QWidget* parent=nullptr) : QWidget(parent)
{
	label = new QLabel("_______________________________________", this);
	numlabel = new QLabel(QString("Task №%1:").arg(globalNumber++), this);
	editbtn = new QPushButton("edit", this);
	delbtn = new QPushButton("delete", this);
	chbox = new QCheckBox(this);
	g_layout = new QGridLayout(this);

	editbtn->setEnabled(false);
	delbtn->setEnabled(false);
	chbox->setEnabled(false);

	QWidget* WidgetArr[] {numlabel, chbox, label, editbtn, delbtn};
	int ind {1}, _arrind {0};
	int lengths[] {2, 1, 7, 1, 1};

	for(QWidget* W : WidgetArr) {
		W->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
		g_layout->addWidget(W, 0, ind, 1, lengths[_arrind]);
		ind += lengths[_arrind++];
	}
}

int LabelWidget::globalNumber {0};

void LabelWidget::enable()
{
	editbtn->setEnabled(true);
	delbtn->setEnabled(true);
	chbox->setEnabled(true);
}
