#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#define SPACES			"_______________________________"

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
	static int _edit_ind;
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
	QPushButton* getEditBtn() { return editbtn; }

	int getDelInd() { return _delete_ind; }
	int getEditInd() { return _edit_ind; }
	bool getChecked() { return chbox->isChecked(); }
	bool getEnabled() { return delbtn->isEnabled(); }

	void setEditMode(bool var);
	void setText(QString qstr);
	void setCheckBox(bool var);
	QString getText();

	void setEnable(bool var);

signals:
	void del();
	void edit();

public slots:
	void set_del_index();
	void set_edit_index();
	void change_task_color();
};

#endif
