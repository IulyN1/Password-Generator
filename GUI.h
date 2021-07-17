#pragma once
#include <qwidget.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qclipboard.h>
#include <qapplication.h>

class GUI: public QWidget
{
	Q_OBJECT
private:
	QLabel* title = new QLabel{ "Password generator" };
	QPushButton* btnGen = new QPushButton{ "Generate" };
	QLabel* passwd = new QLabel;
	QPushButton* btnCopy = new QPushButton{ "Copy" };
	QClipboard* clip = QApplication::clipboard();

	// Function that initializes the GUI components
	void initGui();

	// Function that connects the signals of the GUI components
	void connectSignals();

	// Function that sets the initial state of the GUI application
	void setInitialState();

	// Function that generates a random password of 10 characters long
	QString generate();
public:
	GUI() {
		initGui();
		connectSignals();
		setInitialState();
	}
};

