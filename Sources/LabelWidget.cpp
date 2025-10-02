#include "LabelWidget.h"

LabelWidget::LabelWidget(QWidget* parent=nullptr) : QWidget(parent)
{
	label = new QLabel("...                              ...", this);
	numlabel = new QLabel(QString("Task №%1:").arg(globalNumber++), this);
	editbtn = new QPushButton("edit", this);
	delbtn = new QPushButton("del", this);
	chbox = new QCheckBox(this);
	g_layout = new QGridLayout(this);

	label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	editbtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	delbtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	numlabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

	int ind {1};
	g_layout->addWidget(numlabel, 0, ind);		ind += 2;
	g_layout->addWidget(chbox, 0, ind);		ind += 1;
	g_layout->addWidget(label, 0, ind, 1, 7); 	ind += 7;
	g_layout->addWidget(editbtn, 0, ind); 		ind += 1;
	g_layout->addWidget(delbtn, 0, ind);		ind += 1;
}

int LabelWidget::globalNumber {0};

