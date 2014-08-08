#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QIntValidator>

namespace Ui {
class SettingsWindow;
}

class QIntValidator;

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };

    explicit SettingsWindow(QWidget *parent = 0);

    Settings settingsFun() const;
    ~SettingsWindow();

private slots:
    void showPortInfo(int idx);
    void checkCustomBaudRatePolicy(int idx);
    void apply();

    void on_rescan_clicked();

private:
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();

    Ui::SettingsWindow *ui;
    Settings currentSettings;
    QIntValidator *intValidator;
};

#endif // SETTINGSWINDOW_H
