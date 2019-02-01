#pragma once

#include "ui_hello.h"
#include "noter-sound/sound.hpp"
#include "noter/hello.hpp"

#include <memory>
#include <vector>

#include <portaudio.h>
#include <QDialog>

class AudioWidget;

class NRWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit NRWindow(QMainWindow* parent = nullptr);

public slots:
	void trigger();

private:
	// private pointer to your ui
    std::unique_ptr<Ui::HelloWindow> m_ui;
	bool m_triggered = false;
	AudioWidget* aw;

};


class AudioWidget : public QWidget {
    Q_OBJECT

public:
    AudioWidget(QMainWindow* parent,
                QComboBox* audio_list,
                QPushButton* init_trigger,
                QPushButton* populate_trigger,
                QPushButton* play_trigger);

public slots:
    void paInitTrigger();
    void paPopulateTrigger();
    void paPlayTrigger();

private:

    QComboBox* m_audio_list;
    void populateAudioList();

    QPushButton* m_init_trigger;
    QPushButton* m_populate_trigger;
    QPushButton* m_play_trigger;


    bool m_init_triggered = false;
    bool m_populate_triggered = false;
    bool m_play_triggered = false;

    AudioInitialize init;
    AudioStream m_stream;
    std::vector<PaDeviceInfo const*> m_device_list;
};
