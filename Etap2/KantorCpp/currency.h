#ifndef CURRENCY_H
#define CURRENCY_H

#include <QObject>

class Currency : public QObject
{
    Q_OBJECT
public:
    explicit Currency(QObject *parent = nullptr) : QObject(parent) {}

signals:

};

#endif // CURRENCY_H
