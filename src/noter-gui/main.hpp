#pragma once

#include "ui_hello.h"
#include <memory>

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
    AudioWidget(QMainWindow* parent, QComboBox* audio_list);
/*
public slots:
    void paInitTrigger();
    void paPopulateTrigger();
*/
private:
    QComboBox* m_audio_list;
    void populateAudioList();
};
