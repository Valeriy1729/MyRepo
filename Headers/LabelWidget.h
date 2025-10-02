#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QGridLayout>
#include <QPushButton>
#include <QSizePolicy>


class LabelWidget : public QWidget {
	Q_OBJECT
	static int globalNumber;
	int locNumber {globalNumber};
	QLabel* label {nullptr};
	QLabel* numlabel {nullptr};
	QPushButton* editbtn {nullptr};
	QPushButton* delbtn {nullptr};
	QCheckBox* chbox {nullptr};
	QGridLayout* g_layout {nullptr};

public:
	LabelWidget(QWidget* parent);
	~LabelWidget() { }

	void setText(QString qstr);
};

#endif
