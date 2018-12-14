#include "noter/hello.hpp"

#include "main.hpp"

HelloWidget::HelloWidget(QMainWindow* parent): QMainWindow(parent), m_ui(std::make_unique<Ui::HelloWindow>()) {
	m_ui->setupUi(this);

	connect(m_ui->trigger, &QPushButton::pressed, this, &HelloWidget::trigger);
}

void HelloWidget::trigger() {
	if (!m_triggered) {
		m_ui->output->setText(QString::fromStdString(hello()));
	}
	else {
		m_ui->output->clear();
	}
	m_triggered = !m_triggered;
}

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	HelloWidget hw;
	hw.show();
	return QApplication::exec();
}