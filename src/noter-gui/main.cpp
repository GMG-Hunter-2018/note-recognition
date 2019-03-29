#include "noter-sound/sound.hpp"
#include "noter/hello.hpp"

#include "main.hpp"

#include <iostream>
#include <vector>

#include <QDoubleValidator>
#include <portaudio.h>

NRWindow::NRWindow(QMainWindow* parent) :
    QMainWindow(parent),
    m_ui(std::make_unique<Ui::HelloWindow>()) {
	m_ui->setupUi(this);

	aw = new AudioWidget(this, m_ui->audioListQ, m_ui->paInitTrigger, m_ui->paPopulateTrigger,
	                     m_ui->paPlay, m_ui->paFrequency);

	connect(m_ui->trigger, &QPushButton::pressed, this, &NRWindow::trigger);
}

void NRWindow::trigger() {
	// AudioStream soundStream;

	if (!m_triggered) {
		m_ui->output->setText(QString::fromStdString(hello()));
		// soundStream.startStream();
	}
	else {
		m_ui->output->clear();
		// soundStream.stopStream();
	}
	m_triggered = !m_triggered;
}

AudioWidget::AudioWidget(QMainWindow* parent,
                         QComboBox* audio_list,
                         QPushButton* init_trigger,
                         QPushButton* populate_trigger,
                         QPushButton* play_trigger,
                         QLineEdit* frequency_text) :
    QWidget(parent),
    m_audio_list(audio_list),
    m_init_trigger(init_trigger),
    m_populate_trigger(populate_trigger),
    m_play_trigger(play_trigger),
    m_frequency_text(frequency_text) {
	connect(m_init_trigger, &QPushButton::clicked, this, &AudioWidget::paInitTrigger);
	connect(m_populate_trigger, &QPushButton::clicked, this, &AudioWidget::paPopulateTrigger);
	connect(m_play_trigger, &QPushButton::clicked, this, &AudioWidget::paPlayTrigger);

	m_frequency_text->setPlaceholderText("Frequency?");
	auto dv = new QDoubleValidator(0.0, m_stream.data.sampleRate, 5);
	m_frequency_text->setValidator(dv);

	connect(m_frequency_text, &QLineEdit::returnPressed, this, &AudioWidget::paChangeFreq);
}

void AudioWidget::paInitTrigger() {
	if (!m_init_triggered) {
		std::cerr << "Has Pa initialized? " << init.initPA() << '\n';
		m_init_triggered = !m_init_triggered;

		return;
	}

	if (m_init_triggered) {
		std::cerr << "Wow you already triggered me\n";
	}
}

void AudioWidget::paPopulateTrigger() {
	if (!m_populate_triggered) {
		populateAudioList();
		m_populate_triggered = !m_populate_triggered;
		return;
	}
	if (m_populate_triggered) {
		std::cerr << "Wow you already triggered me\n";
		// We may want to move this user-side.
	}
}

void AudioWidget::paPlayTrigger() {
	if (!m_play_triggered) {
		m_stream.openStream();
		m_stream.startStream();
		// TODO: Make visual feedback of start and stop.

		m_play_triggered = !m_play_triggered;
		return;
	}

	if (m_play_triggered) {
		m_stream.stopStream();

		m_play_triggered = !m_play_triggered;
		return;
	}
}

void AudioWidget::paChangeFreq() {
	m_stream.data.intendedFreq = m_frequency_text->text().toFloat();
}

void AudioWidget::populateAudioList() {
	int numDevices = Pa_GetDeviceCount();

	for (int i = 0; i < numDevices; i++) {
		m_device_list.push_back(Pa_GetDeviceInfo(i));
		m_audio_list->addItem(
		    m_device_list[static_cast<std::vector<PaDeviceInfo const*>::size_type>(i)]->name);
	}
}

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	NRWindow nrw;
	nrw.show();

	return QApplication::exec();
}