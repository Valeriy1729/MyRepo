#include "InputLineWidget.h"
#include <iostream>

const char* InputLineW::btnDefaultText {"add"};
const char* InputLineW::btnEditText {"done"};
const char* InputLineW::labelDefaultText {"Enter new task: "};
const char* InputLineW::labelEditText {"Edit Task№%1: "};

InputLineW::InputLineW(QWidget* parent=nullptr) : QWidget(parent)
{
	label = new QLabel(labelDefaultText, this);		
	editline = new QLineEdit(" ", this);
	addbtn = new QPushButton(btnDefaultText, this);
	g_layout = new QGridLayout(this);

	addbtn->setObjectName("addbtn");
	label->setObjectName("inputLabel");

	addbtn->setEnabled(false);

	QWidget* WidgetArr[] {label, editline, addbtn};
	int ind {1}, _arrind {0};
	int lengths[] {2, 8, 1};

	for(QWidget* W : WidgetArr) {
		W->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
		g_layout->addWidget(W, 0, ind, 1, lengths[_arrind]);
		ind += lengths[_arrind++];
	}

	connect(editline, SIGNAL(editingFinished()), this, SLOT(enable_add_btn()));
	connect(addbtn, SIGNAL(clicked()), this, SLOT(unenable_add_btn()));
}

void InputLineW::enable_add_btn()
{
	addbtn->setEnabled(true);	
}

void InputLineW::unenable_add_btn()
{
	if(editline->text() == QString(" ")) return;
	std::cout << "unable btn" << std::endl;
	addbtn->setEnabled(false);	
	emit data_recieved();
}

void InputLineW::input_clear() { editline->setText(" "); std::cout << "inpclear" << std::endl; }


