#ifndef SOFTKEYLINEEDIT_H
#define SOFTKEYLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>
#include "numkeyboard.h"

class SoftKeyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit SoftKeyLineEdit(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    NumKeyboard *numkeyboard;

signals:

public slots:

};

#endif // SOFTKEYLINEEDIT_H
