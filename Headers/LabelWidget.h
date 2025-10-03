#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#define SPACES			"_______________________________________"

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QGridLayout>
#include <QPushButton>
#include <QSizePolicy>


class LabelWidget : public QWidget {
	Q_OBJECT
	static int globalNumber;
	static int _delete_ind;
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

	QPushButton* getDelBtn() { return delbtn; }
	void setText(QString qstr);
	int getdelind() { return _delete_ind; }
	void setEnable(bool var);
	QString getText();

signals:
	void del();

public slots:
	void set_del_index();
};

#endif
