#pragma once

#include "ui_hello.h"
#include <memory>

class HelloWidget : public QMainWindow {
	Q_OBJECT

public:
	explicit HelloWidget(QMainWindow* parent = nullptr);

public slots:
	void trigger();

private:
	// private pointer to your ui
	bool m_triggered = false;
	std::unique_ptr<Ui::HelloWindow> m_ui;
};
