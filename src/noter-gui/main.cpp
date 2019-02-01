#include "noter-sound/sound.hpp"
#include "noter/hello.hpp"

#include "main.hpp"

#include <iostream>
#include <portaudio.h>
#include <vector>


NRWindow::NRWindow(QMainWindow* parent):
    QMainWindow(parent),
    m_ui(std::make_unique<Ui::HelloWindow>())
{
	m_ui->setupUi(this);



	aw = new AudioWidget(this,
						 m_ui->audioListQ,
						 m_ui->paInitTrigger,
						 m_ui->paPopulateTrigger);

	connect(m_ui->trigger, &QPushButton::pressed, this, &NRWindow::trigger);

}

void NRWindow::trigger() {

    //AudioStream soundStream;


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


AudioWidget::AudioWidget(QMainWindow* parent,
						 QComboBox* audio_list,
						 QPushButton* init_trigger,
						 QPushButton* populate_trigger):
    QWidget(parent),
	m_audio_list(audio_list),
	m_init_trigger(init_trigger),
	m_populate_trigger(populate_trigger)
{
    connect(m_init_trigger, &QPushButton::clicked, this, &AudioWidget::paInitTrigger);
    connect(m_populate_trigger, &QPushButton::clicked, this, &AudioWidget::paPopulateTrigger);
}

void AudioWidget::paInitTrigger() {

	if(!m_init_triggered){

		std::cerr << "Has Pa initialized? " << init.initPA() << '\n';
		m_init_triggered = !m_init_triggered;
	}

	if(m_init_triggered){
		std::cerr << "Wow you already triggered me\n";
	}
}

void AudioWidget::paPopulateTrigger() {

    if(!m_populate_triggered){
        populateAudioList();
        m_populate_triggered= !m_populate_triggered;
    }
    if(m_populate_triggered){
        std::cerr << "Wow you already triggered me\n";
    }
}

void AudioWidget::populateAudioList(){

    int numDevices = Pa_GetDeviceCount();
    std::cout<<numDevices<<'\n';

    for(int i=0; i<numDevices; i++){
        std::cout<<"Device "<< numDevices<<'\n';
    	m_device_list.push_back(Pa_GetDeviceInfo(i));
    	m_audio_list->addItem(m_device_list[i]->name);
    }

}


int main(int argc, char** argv) {
	QApplication app(argc, argv);
	NRWindow nrw;
	nrw.show();



	return QApplication::exec();
}