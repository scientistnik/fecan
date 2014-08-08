/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *rescan;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_2;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *dataBitsLabel;
    QLabel *flowControlLabel;
    QComboBox *parityBox;
    QCheckBox *localEchoCheckBox;
    QComboBox *flowControlBox;
    QComboBox *stopBitsBox;
    QLabel *stopBitsLabel;
    QComboBox *dataBitsBox;
    QLabel *parityLabel;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(466, 249);
        buttonBox = new QDialogButtonBox(SettingsWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 210, 441, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        rescan = new QPushButton(SettingsWindow);
        rescan->setObjectName(QStringLiteral("rescan"));
        rescan->setGeometry(QRect(20, 50, 75, 23));
        selectBox = new QGroupBox(SettingsWindow);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        selectBox->setGeometry(QRect(120, 20, 341, 91));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        parametersBox = new QGroupBox(SettingsWindow);
        parametersBox->setObjectName(QStringLiteral("parametersBox"));
        parametersBox->setGeometry(QRect(10, 110, 451, 91));
        gridLayout_2 = new QGridLayout(parametersBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));

        gridLayout_2->addWidget(dataBitsLabel, 1, 0, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));

        gridLayout_2->addWidget(flowControlLabel, 0, 4, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        gridLayout_2->addWidget(parityBox, 0, 3, 1, 1);

        localEchoCheckBox = new QCheckBox(parametersBox);
        localEchoCheckBox->setObjectName(QStringLiteral("localEchoCheckBox"));
        localEchoCheckBox->setChecked(true);

        gridLayout_2->addWidget(localEchoCheckBox, 1, 4, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));

        gridLayout_2->addWidget(flowControlBox, 0, 5, 1, 1);

        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        gridLayout_2->addWidget(stopBitsBox, 1, 3, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));

        gridLayout_2->addWidget(stopBitsLabel, 1, 2, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        gridLayout_2->addWidget(dataBitsBox, 1, 1, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        gridLayout_2->addWidget(parityLabel, 0, 2, 1, 1);


        retranslateUi(SettingsWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "Dialog", 0));
        rescan->setText(QApplication::translate("SettingsWindow", "ReScan", 0));
        selectBox->setTitle(QApplication::translate("SettingsWindow", "Select Serial Port", 0));
        descriptionLabel->setText(QApplication::translate("SettingsWindow", "Description:", 0));
        parametersBox->setTitle(QApplication::translate("SettingsWindow", "Select Parameters", 0));
        baudRateLabel->setText(QApplication::translate("SettingsWindow", "BaudRate:", 0));
        dataBitsLabel->setText(QApplication::translate("SettingsWindow", "Data bits:", 0));
        flowControlLabel->setText(QApplication::translate("SettingsWindow", "Flow control:", 0));
        localEchoCheckBox->setText(QApplication::translate("SettingsWindow", "Local echo", 0));
        stopBitsLabel->setText(QApplication::translate("SettingsWindow", "Stop bits:", 0));
        parityLabel->setText(QApplication::translate("SettingsWindow", "Parity:", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
