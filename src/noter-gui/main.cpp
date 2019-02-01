#include "noter-sound/sound.hpp"
#include "noter/hello.hpp"

#include "main.hpp"
#include <iostream>

NRWindow::NRWindow(QMainWindow* parent):
    QMainWindow(parent),
    m_ui(std::make_unique<Ui::HelloWindow>())
{
	m_ui->setupUi(this);

	aw = new AudioWidget(this, m_ui->audioListQ);

	connect(m_ui->trigger, &QPushButton::pressed, this, &NRWindow::trigger);

}

void NRWindow::trigger() {
    AudioInitialize init;
    std::cerr << "Has Pa initialized? " << init.initPA() << '\n';

    AudioStream soundStream;


	if (!m_triggered) {
		m_ui->output->setText(QString::fromStdString(hello()));
		//soundStream.startStream();
	}
	else {
		m_ui->output->clear();
		//soundStream.stopStream();
	}
	m_triggered = !m_triggered;
}


AudioWidget::AudioWidget(QMainWindow* parent, QComboBox* audio_list):
    QWidget(parent),
	m_audio_list(audio_list)
{
    populateAudioList();
}

void AudioWidget::populateAudioList(){

    m_audio_list->addItem("Hello Test");

}


int main(int argc, char** argv) {
	QApplication app(argc, argv);
	NRWindow nrw;
	nrw.show();



	return QApplication::exec();
}