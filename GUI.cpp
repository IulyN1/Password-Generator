#include "GUI.h"
#include <qboxlayout.h>
#include <time.h>

void GUI::initGui() {
	QVBoxLayout* ly = new QVBoxLayout;
	setLayout(ly);
	ly->addWidget(title);
	ly->addWidget(btnGen);
	QHBoxLayout* lyRez = new QHBoxLayout;
	lyRez->addWidget(passwd);
	lyRez->addWidget(btnCopy);
	ly->addLayout(lyRez);
}

QString GUI::generate() {
	srand(time(NULL));
	QString characters = "0123456789!@#$%^&*-+?.ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	QString password = "";
	for (int i = 0; i < 10; i++) {
		password.append(characters.at(rand() % characters.size()));
	}
	return password;
}

void GUI::connectSignals() {
	connect(btnGen, &QPushButton::clicked, this, [=]() {
		auto text = generate();
		passwd->setText(text);
		});
	connect(btnCopy, &QPushButton::clicked, this, [=]() {
		auto password = passwd->text();
		clip->setText(password);
		});
}

void GUI::setInitialState() {
	title->setStyleSheet("QLabel{font-size: 25px; display: block; margin: auto;}");
	passwd->setStyleSheet("QLabel{background-color: yellow; padding-left: 10px;}");
	setWindowTitle("Password generator");
	resize(100, 100);
}