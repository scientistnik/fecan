#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rs232.h"

//#define __linux__

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int open_port = 0;

void MainWindow::on_pushButton_clicked()
{
    int i, n,
          cport_nr=2,        /* /dev/ttyS0 (COM1 on windows) */
          bdrate=115200;       /* 115200 baud */

      unsigned char buf[4096];

      if(!open_port)
      if(RS232_OpenComport(cport_nr, bdrate))
      {
        ui->plainTextEdit->setPlainText("Can not open comport\n");
        open_port++;
        return;
      }

      ui->plainTextEdit->setPlainText("...");
      //while(1)
      {
          n = RS232_PollComport(cport_nr, buf, 4095);

          if(n > 0)
        {
          buf[n] = 0;   /* always put a "null" at the end of a string! */

          for(i=0; i < n; i++)
          {
            if(buf[i] < 32)  /* replace unreadable control-codes by dots */
            {
              buf[i] = '.';
            }
          }

          printf("received %i bytes: %s\n", n, (char *)buf);
          ui->plainTextEdit->setPlainText("received %i bytes: %s\n");
        }
        //printf("pusto...\n");
        //ui->plainTextEdit->setPlainText("pusto...\n");
          /*
    #ifdef _WIN32
        Sleep(100);
    #else
        usleep(100000);  /// sleep for 100 milliSeconds /
    #endif
          */
      }
    return;
}
