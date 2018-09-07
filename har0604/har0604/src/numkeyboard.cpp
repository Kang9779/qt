#include "numkeyboard.h"
#include <QDebug>
NumKeyboard::NumKeyboard(QWidget *parent) :
    QDialog(parent)

{
        okButton = new QPushButton(this);
        okButton->setText(" OK");
        okButton->setGeometry(QRect(190, 250, 110, 50));
//        okButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0)"));
        okButton->setStyleSheet("border-style:outset;border-width:2px;");
//        okButton->setFlat(false);
        QFont font1;
        font1.setPointSize(14);
        okButton->setFont(font1);

        okButton->setStyleSheet("border-width:1px solid #999;border-color: rgb(255, 255, 255);");
//        okButton->setFlat(true);
//        okButton->setStyleSheet("outline:1px;");

        backspaceButton = new QPushButton(this);
        backspaceButton->setText(" backspace");
        backspaceButton->setGeometry(QRect(190, 130, 110, 50));
        backspaceButton->setFont(font1);

        num6Button = new QPushButton(this);
        num6Button->setText("6");
        num6Button->setGeometry(QRect(130, 130, 50, 50));
        QFont font;
        font.setPointSize(22);
        num6Button->setFont(font);

        num4Button = new QPushButton(this);
        num4Button->setText(" 4");
        num4Button->setGeometry(QRect(10, 130, 50, 50));
        num4Button->setFont(font);

        leftButton = new QPushButton(this);
        leftButton->setText("<-");
        leftButton->setGeometry(QRect(190, 190, 50, 50));
        leftButton->setFont(font);
//        leftButton->setAutoFillBackground(false);
      //  leftButton->setStyleSheet(QString::fromUtf8("background-color:rgb(202, 202, 202)"));

        num1Button = new QPushButton(this);
        num1Button->setText("1");
        num1Button->setGeometry(QRect(10, 70, 50, 50));
        num1Button->setFont(font);

        cancelButton = new QPushButton(this);
        cancelButton->setText("Esc");
        cancelButton->setGeometry(QRect(190, 70, 110, 50));
        cancelButton->setFont(font1);

        rightButton = new QPushButton(this);
        rightButton->setText("->");
        rightButton->setGeometry(QRect(250, 190, 50, 50));
        rightButton->setFont(font);

        num9Button = new QPushButton(this);
        num9Button->setText("9");
        num9Button->setGeometry(QRect(130, 190, 50, 50));
        num9Button->setFont(font);

        num8Button = new QPushButton(this);
        num8Button->setText("8");
        num8Button->setGeometry(QRect(70, 190, 50, 50));
        num8Button->setFont(font);

        num2Button = new QPushButton(this);
        num2Button->setText("2");
        num2Button->setGeometry(QRect(70, 70, 50, 50));
        num2Button->setFont(font);

        num7Button = new QPushButton(this);
        num7Button->setText("7");
        num7Button->setGeometry(QRect(10, 190, 50, 50));
        num7Button->setFont(font);

        dotButton = new QPushButton(this);
        dotButton->setText(".");
        dotButton->setGeometry(QRect(130, 250, 50, 50));
        dotButton->setFont(font);


        num3Button = new QPushButton(this);
        num3Button->setText("3");
        num3Button->setGeometry(QRect(130, 70, 50, 50));
        num3Button->setFont(font);

        num0Button = new QPushButton(this);
        num0Button->setText("0");
        num0Button->setGeometry(QRect(10, 250, 50, 50));
        num0Button->setFont(font);

        num5Button = new QPushButton(this);
        num5Button->setText("5");
        num5Button->setGeometry(QRect(70, 130, 50, 50));
        num5Button->setFont(font);

        signButton = new QPushButton(this);
        signButton->setText("+/-");
        signButton->setGeometry(QRect(70, 250, 50, 50));
        QFont font2;
        font2.setPointSize(20);
        signButton->setFont(font2);

        lineEdit = new QLineEdit(this);
        lineEdit->setGeometry(QRect(10, 10, 290, 50));
        QFont font3;
     //   font3.setFamily(QString::fromUtf8("Ubuntu"));
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        lineEdit->setFont(font3);
        lineEdit->setText(QString());
//        lineEdit->setFrame(QFrame::Box);
//        lineEdit->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");


    connect(num1Button, SIGNAL(clicked()), this, SLOT(on_num1Button_clicked()));
    connect(num2Button, SIGNAL(clicked()), this, SLOT(on_num2Button_clicked()));
    connect(num3Button, SIGNAL(clicked()), this, SLOT(on_num3Button_clicked()));
    connect(num4Button, SIGNAL(clicked()), this, SLOT(on_num4Button_clicked()));
    connect(num5Button, SIGNAL(clicked()), this, SLOT(on_num5Button_clicked()));
    connect(num6Button, SIGNAL(clicked()), this, SLOT(on_num6Button_clicked()));
    connect(num7Button, SIGNAL(clicked()), this, SLOT(on_num7Button_clicked()));
    connect(num8Button, SIGNAL(clicked()), this, SLOT(on_num8Button_clicked()));
    connect(num9Button, SIGNAL(clicked()), this, SLOT(on_num9Button_clicked()));
    connect(num0Button, SIGNAL(clicked()), this, SLOT(on_num0Button_clicked()));
    connect(dotButton, SIGNAL(clicked()), this, SLOT(on_dotButton_clicked()));

    connect(leftButton, SIGNAL(clicked()), this, SLOT(on_leftButton_clicked()));
    connect(rightButton, SIGNAL(clicked()), this, SLOT(on_rightButton_clicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(on_cancelButton_clicked()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(on_okButton_clicked()));
    connect(signButton, SIGNAL(clicked()), this, SLOT(on_signButton_clicked()));
    connect(backspaceButton, SIGNAL(clicked()), this, SLOT(on_backspaceButton_clicked()));

}

NumKeyboard::~NumKeyboard()
{

}

void NumKeyboard::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        break;
    default:
        break;
    }
}

bool NumKeyboard::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (obj == lineEdit)
            {
                if(keyEvent->key() >= 0x20 && keyEvent->key()<= 0x0ff)  //屏蔽所有按键输入
                    return true;
                else
                    return false;
            }
            else
            {
                return false;
            }
    }
    else
    {
            // standard event processing
        return QObject::eventFilter(obj, event);
    }
}

//***********************按键*****************************//
void NumKeyboard::on_num1Button_clicked()       //1
{
    int idx = lineEdit->cursorPosition();  //根据光标的位置索引
    if(strContent.left(idx) == "0")       //除了小数外，第一个数不为0
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
   //  字符串的存储有引用计数，当一个 QString 对象被复制为另一个 QString 对象时，它们实际上指向相同的存储空间，仅仅是增加一个引用计数
    strContent.insert(idx, '1');  //插入字符串str在给定的索引位置对这个字符串,并返回一个引用。 //数据存入strContent
    lineEdit->setText(strContent); //strContent中的内容显示在lineEdit
    lineEdit->setCursorPosition(idx+1); //设置光标的位置 ??不设置好像也可以使用设定光标的位置
    lineEdit->setFocus();  //存在光标
    qDebug()<<"strContent"<<strContent;
    qDebug()<<"idx"<<idx;
}

void NumKeyboard::on_num2Button_clicked()       //2
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '2');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num3Button_clicked()       //3
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '3');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num4Button_clicked()       //4
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '4');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num5Button_clicked()       //5
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '5');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num6Button_clicked()       //6
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '6');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num7Button_clicked()       //7
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '7');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num8Button_clicked()       //8
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '8');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num9Button_clicked()       //9
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '9');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_dotButton_clicked()        //.
{
    int idx = lineEdit->cursorPosition();

    if(idx==0 || strContent.contains('.'))
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '.');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_num0Button_clicked()       //0
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(idx) == "0" || (idx==0 &&strContent!=""))
    {
        lineEdit->setCursorPosition(idx);
        qDebug()<<"idx"<<idx;
        lineEdit->setFocus();
        return;
    }
    strContent.insert(idx, '0');
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_signButton_clicked()       //+/-
{
    int idx = lineEdit->cursorPosition();
    if(strContent.left(1) == "-")
    {
        strContent.remove(0, 1);
        lineEdit->setText(strContent);
        lineEdit->setCursorPosition(idx-1);
        lineEdit->setFocus();
    }
    else
    {
        if(strContent=="0" || strContent=="")
        {
            lineEdit->setCursorPosition(idx);
            lineEdit->setFocus();
        }
        else
        {
            strContent.insert(0, '-');
            lineEdit->setText(strContent);
            lineEdit->setCursorPosition(idx+1);
            lineEdit->setFocus();
        }
    }
}

void NumKeyboard::on_leftButton_clicked()       //left
{
    int idx = lineEdit->cursorPosition();
    if(idx == 0)
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    lineEdit->setCursorPosition(idx-1);
    lineEdit->setFocus();
}

void NumKeyboard::on_rightButton_clicked()      //right
{
    int idx = lineEdit->cursorPosition();
    if(idx == strContent.length()) //返回此字符串的字符数
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    lineEdit->setCursorPosition(idx+1);
    lineEdit->setFocus();
}

void NumKeyboard::on_backspaceButton_clicked()      //backspace
{
    int idx = lineEdit->cursorPosition();
    if(idx == 0)
    {
        lineEdit->setCursorPosition(idx);
        lineEdit->setFocus();
        return;
    }
    strContent.remove(idx-1,1);
    lineEdit->setText(strContent);
    lineEdit->setCursorPosition(idx-1);
    lineEdit->setFocus();
}

void NumKeyboard::on_cancelButton_clicked()     //cancel
{
    this->close();
    valid = false;
}

void NumKeyboard::on_okButton_clicked()         //ok
{
    this->close();
    valid = true;
}

void NumKeyboard::setText(QString str)      //设置文本内容
{
    strContent = str;
    lineEdit->setText(strContent);
    lineEdit->setFocus();
}

QString NumKeyboard::getText()              //获取内容
{
    return strContent;
}
