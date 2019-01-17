#include "noter-sound/sound.hpp"
#include "noter/hello.hpp"

#include "main.hpp"
#include <iostream>

HelloWidget::HelloWidget(QMainWindow* parent): QMainWindow(parent), m_ui(std::make_unique<Ui::HelloWindow>()) {
	m_ui->setupUi(this);

	connect(m_ui->trigger, &QPushButton::pressed, this, &HelloWidget::trigger);
}

void HelloWidget::trigger() {
    AudioInitialize init;
    std::cerr << "Has Pa initialized? " << init.initPA() << '\n';

    AudioStream soundStream;


	if (!m_triggered) {
		m_ui->output->setText(QString::fromStdString(hello()));
		soundStream.startStream();
	}
	else {
		m_ui->output->clear();
		soundStream.stopStream();
	}
	m_triggered = !m_triggered;
}

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	HelloWidget hw;
	hw.show();
	return QApplication::exec();
}