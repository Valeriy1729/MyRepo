#include "InputLineWidget.h"

InputLineW::InputLineW(QWidget* parent=nullptr) : QWidget(parent)
{
	label = new QLabel("Enter new task: ", this);		
	editline = new QLineEdit(this);
	addbtn = new QPushButton("add", this);
	g_layout = new QGridLayout(this);

	QWidget* WidgetArr[] {label, editline, addbtn};
	int ind {1}, _arrind {0};
	int lengths[] {2, 9, 1};

	for(QWidget* W : WidgetArr) {
		W->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
		g_layout->addWidget(W, 0, ind, 1, lengths[_arrind]);
		ind += lengths[_arrind++];
	}
}
