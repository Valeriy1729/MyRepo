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
	QLabel* label {nullptr};
	QPushButton* editbtn {nullptr};
	QPushButton* delbtn {nullptr};
	QCheckBox* chbox {nullptr};
	QGridLayout* g_layout {nullptr};

public:
	LabelWidget(QWidget* parent);
	~LabelWidget() { }
};


#endif
