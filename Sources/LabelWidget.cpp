#include "LabelWidget.h"

LabelWidget::LabelWidget(QWidget* parent=nullptr) : QWidget(parent)
{
	label = new QLabel("HereIsText", this);
	editbtn = new QPushButton("edit", this);
	delbtn = new QPushButton("del", this);
	chbox = new QCheckBox(this);
	g_layout = new QGridLayout(this);

	//chbox->setSizePolicy(QSizePolicy::Preferred);
	label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	editbtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	delbtn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

	g_layout->addWidget(chbox, 0, 0);
	g_layout->addWidget(label, 0, 1, 1, 3);
	g_layout->addWidget(editbtn, 0, 5);
	g_layout->addWidget(delbtn, 0, 6);
}
