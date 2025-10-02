#include "InputLineWidget.h"

InputLineW::InputLineW(QWidget* parent=nullptr) : QWidget(parent)
{
	label = new QLabel("Enter new task: ", this);		
	editline = new QLineEdit(this);
	addbtn = new QPushButton("add", this);
	g_layout = new QGridLayout(this);

	addbtn->setEnabled(false);

	QWidget* WidgetArr[] {label, editline, addbtn};
	int ind {1}, _arrind {0};
	int lengths[] {2, 8, 1};

	for(QWidget* W : WidgetArr) {
		W->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
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
	addbtn->setEnabled(false);	
	emit data_recieved();
}

QString InputLineW::gettext()
{
	return editline->text();	
}

