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
	//QString recieved_data {""};

public:	
	InputLineW(QWidget* parent);
	~InputLineW() { }

	static const char* btnDefaultText;
	static const char* btnEditText;
	static const char* labelDefaultText;
	static const char* labelEditText;

	QString gettext() { return editline->text(); }
	void settext(QString qstr) { editline->setText(qstr); }
	void setLabelText(QString qstr) { label->setText(qstr); }
	void setBtnText(QString qstr) { addbtn->setText(qstr); }

public slots:
	void enable_add_btn();
	void unenable_add_btn();
	void input_clear();

signals:
	void data_recieved();
};

#endif
