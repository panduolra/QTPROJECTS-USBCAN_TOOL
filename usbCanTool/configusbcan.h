#ifndef CONFIGUSBCAN_H
#define CONFIGUSBCAN_H

#include "libusb.h"
#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QList>

namespace Ui {
class ConfigUsbCan;
}

class ConfigUsbCan : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigUsbCan(QWidget *parent = 0);
    ~ConfigUsbCan(void);

private:
    Ui::ConfigUsbCan *ui;

//added by me
public:
    struct Settings
    {
        libusb_device_descriptor currentUsbDesc;
        QStringList currentUsbDevExInfo;
    };
    const unsigned short USBCAN_VID = 0x4348;
    const unsigned short USBCAN_PID = 0x5537;
    const unsigned int USB_INFO_MAX_LEN = 256;
public:
    Settings settings() const;
private:
    QList<libusb_device_descriptor> libusbDevsDescs;
    QList<QStringList> usbDevExInfos;
    Settings currentSettings;

    QComboBox *usbDevList;
    QPushButton *okBtn;
    QTableWidget *usbDevDescTbl;

private:
    void componentsAndLayoutInit(void);

private slots:
    int getUsbDeviceInfo(void);
    void applyBtnPressed(void);
    void updateUsbInfo(void);
};

#endif // CONFIGUSBCAN_H
