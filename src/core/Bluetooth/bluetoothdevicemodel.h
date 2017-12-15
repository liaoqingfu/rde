#ifndef BLUETOOTHDEVICEMODEL_H
#define BLUETOOTHDEVICEMODEL_H
/*                                                                                               */
#include "Model.h"
#include "scanner.h"
/*                                                                                               */
class BluetoothDeviceModel : public Model
{
    Q_OBJECT
    Q_PROPERTY(QString address READ address NOTIFY addressChanged)

public:
    BluetoothDeviceModel();
    void setCurrentIndex(const int &index);
    QString address(){return Scanner::devices.at(m_currentIndex).address().toString();}

private:
    enum Roles{Name,IconName,SignalStrength};
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    //int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return 1;}
    int rowCount(const QModelIndex &parent)const{Q_UNUSED(parent);return Scanner::devices.count();}
    //QString getIconName(const QBluetoothDeviceInfo &info)const;
    int m_currentIndex;

signals:
    void addressChanged();
};
#endif