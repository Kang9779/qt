
#include "softkeylineedit.h"

SoftKeyLineEdit::SoftKeyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{

}

void SoftKeyLineEdit::mousePressEvent(QMouseEvent *e)
{
    numkeyboard = new NumKeyboard(this);
    if(e->button() == Qt::LeftButton)
    {
        numkeyboard->setText(this->text());  //当前的文本框的内容，this->指向的是SoftKeyLineEdit
        numkeyboard->exec();
        if(numkeyboard->valid)
        {
            this->setText(numkeyboard->getText());  //此处的setText是继承QLineEdit的，numkeyboard->setTex是自定义的，目的是获取当前的文本
        }
    }
}
