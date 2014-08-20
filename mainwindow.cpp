/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Copyright (C) 2014 Nikolay Nozdrin-Plotnitsky <nozdrin.plotnitsky@gmail.com>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"

#include <QMessageBox>
#include <QtSerialPort/QSerialPort>

#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    console = new Console;
    console->setEnabled(false);

    ui->central_lay->addWidget(console);
    serial = new QSerialPort(this);
    set_win = new SettingsWindow(this);

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);
    raw_data = "";
    can_message = NULL;

    initActionsConnections();

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(console, SIGNAL(getData(QByteArray)), this, SLOT(writeData(QByteArray)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSerialPort()
{
    SettingsWindow::Settings p = set_win->settingsFun();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
            console->setEnabled(true);
            console->setLocalEchoEnabled(p.localEchoEnabled);
            ui->actionConnect->setEnabled(false);
            ui->actionDisconnect->setEnabled(true);
            ui->actionConfigure->setEnabled(false);
            ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                       .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                       .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        ui->statusBar->showMessage(tr("Open error"));
    }
}

void MainWindow::closeSerialPort()
{
    serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->statusBar->showMessage(tr("Disconnected"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About FECAN"),
                       tr("The <b>FECAN</b> founded by "
                          "QSerialPort."));
}

void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    console->putData(data);

    raw_data += data;
    ProcessRawData();
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    //connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(ui->actionClear, SIGNAL(triggered()), console, SLOT(clear()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
}

//******************************************************************************************
//                                          SETTINGS
//******************************************************************************************

void MainWindow::on_ButtonConnect_clicked()
{
    if (ui->actionConnect->isEnabled()) {
        ui->ButtonConnect->setText("Disconnect");
        openSerialPort();
    }
    else {
        ui->ButtonConnect->setText("Connect");
        closeSerialPort();
    }
}

void MainWindow::on_applyButton_clicked()
{
    set_win->show();
}

void MainWindow::on_clearScreen_clicked()
{
    console->clear();
}

void MainWindow::ProcessRawData()
{
    int position;
    int num_row = 0;
    struct Can_Message * index_message = can_message;

    if ( (position = raw_data.indexOf("\u000D")) != -1) {
        QString id = raw_data.mid(1,8);


        if (index_message == NULL) {
            index_message = new struct Can_Message;
            index_message->next = NULL;

            index_message->id = new QTableWidgetItem(raw_data.mid(1,8));
            index_message->dlc = new QTableWidgetItem(raw_data.mid(9,1));
            index_message->data = new QTableWidgetItem(raw_data.mid(10,16));
            index_message->time = new QTableWidgetItem(raw_data.mid(26,4));

            ui->table_reseive->setItem(num_row,0, index_message->id);
            ui->table_reseive->setItem(num_row,1, index_message->dlc);
            ui->table_reseive->setItem(num_row,2, index_message->data);
            ui->table_reseive->setItem(num_row,3, index_message->time);
        }

        while(index_message != NULL) {
            if (id.compare(index_message->id->text())) {
                //can_message->id->setText(raw_data.mid(1,8));
                can_message->dlc->setText(raw_data.mid(9,1));
                can_message->data->setText(raw_data.mid(10,16));
                can_message->time->setText(raw_data.mid(26,4));
                break;
            }
            num_row++;
            if (index_message->next == NULL) {
                index_message->next = new struct Can_Message;
                index_message = index_message->next;
                index_message->next = NULL;

                index_message->id = new QTableWidgetItem(raw_data.mid(1,8));
                index_message->dlc = new QTableWidgetItem(raw_data.mid(9,1));
                index_message->data = new QTableWidgetItem(raw_data.mid(10,16));
                index_message->time = new QTableWidgetItem(raw_data.mid(26,4));

                ui->table_reseive->setItem(num_row,0, index_message->id);
                ui->table_reseive->setItem(num_row,1, index_message->dlc);
                ui->table_reseive->setItem(num_row,2, index_message->data);
                ui->table_reseive->setItem(num_row,3, index_message->time);
                break;
            }
            index_message = index_message->next;
        }

        raw_data.remove(0, position+2);
    }

}
