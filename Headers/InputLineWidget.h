#ifndef INPUTLINE_H
#define INPUTLINE_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSizePolicy>


class InputLineW : public QWidget {
	Q_OBJECT
	QLabel* label {nullptr};
	QLineEdit* editline {nullptr};
	QPushButton* addbtn {nullptr};
	QGridLayout* g_layout {nullptr};

public:	
	InputLineW(QWidget* parent);
	~InputLineW() { }
};

#endif
