/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloWindow
{
public:
    QAction *actionQuit;
    QAction *actionChoose_Audio_Device;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QPushButton *trigger;
    QLineEdit *output;
    QWidget *tab_6;
    QComboBox *audioListQ;
    QPushButton *paInitTrigger;
    QPushButton *paPopulateTrigger;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAudio;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HelloWindow)
    {
        if (HelloWindow->objectName().isEmpty())
            HelloWindow->setObjectName(QString::fromUtf8("HelloWindow"));
        HelloWindow->resize(409, 243);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HelloWindow->sizePolicy().hasHeightForWidth());
        HelloWindow->setSizePolicy(sizePolicy);
        HelloWindow->setMinimumSize(QSize(271, 128));
        HelloWindow->setMaximumSize(QSize(3000, 3000));
        HelloWindow->setAnimated(true);
        actionQuit = new QAction(HelloWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionChoose_Audio_Device = new QAction(HelloWindow);
        actionChoose_Audio_Device->setObjectName(QString::fromUtf8("actionChoose_Audio_Device"));
        centralwidget = new QWidget(HelloWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        trigger = new QPushButton(tab_5);
        trigger->setObjectName(QString::fromUtf8("trigger"));
        trigger->setGeometry(QRect(0, 20, 381, 34));
        output = new QLineEdit(tab_5);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(0, 80, 381, 32));
        output->setAlignment(Qt::AlignCenter);
        output->setReadOnly(true);
        output->setClearButtonEnabled(false);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        audioListQ = new QComboBox(tab_6);
        audioListQ->setObjectName(QString::fromUtf8("audioListQ"));
        audioListQ->setGeometry(QRect(90, 20, 211, 41));
        paInitTrigger = new QPushButton(tab_6);
        paInitTrigger->setObjectName(QString::fromUtf8("paInitTrigger"));
        paInitTrigger->setGeometry(QRect(30, 80, 88, 34));
        paPopulateTrigger = new QPushButton(tab_6);
        paPopulateTrigger->setObjectName(QString::fromUtf8("paPopulateTrigger"));
        paPopulateTrigger->setGeometry(QRect(140, 70, 121, 51));
        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addWidget(frame);

        HelloWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HelloWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 409, 30));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAudio = new QMenu(menubar);
        menuAudio->setObjectName(QString::fromUtf8("menuAudio"));
        HelloWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HelloWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setSizeGripEnabled(false);
        HelloWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAudio->menuAction());
        menuFile->addAction(actionQuit);
        menuAudio->addAction(actionChoose_Audio_Device);

        retranslateUi(HelloWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), HelloWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(HelloWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HelloWindow)
    {
        HelloWindow->setWindowTitle(QApplication::translate("HelloWindow", "MainWindow", nullptr));
        actionQuit->setText(QApplication::translate("HelloWindow", "&Quit", nullptr));
        actionChoose_Audio_Device->setText(QApplication::translate("HelloWindow", "&Choose Audio Device", nullptr));
        trigger->setText(QApplication::translate("HelloWindow", "Hello?", nullptr));
        output->setPlaceholderText(QApplication::translate("HelloWindow", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("HelloWindow", "Tab 1", nullptr));
        audioListQ->setCurrentText(QString());
        paInitTrigger->setText(QApplication::translate("HelloWindow", "Initialize PA", nullptr));
        paPopulateTrigger->setText(QApplication::translate("HelloWindow", "Detect Audio\n"
"Devices", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("HelloWindow", "Tab 2", nullptr));
        menuFile->setTitle(QApplication::translate("HelloWindow", "Fi&le", nullptr));
        menuAudio->setTitle(QApplication::translate("HelloWindow", "A&udio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelloWindow: public Ui_HelloWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
