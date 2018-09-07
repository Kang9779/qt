#include "myswitchbutton.h"

/* ˵��:�Զ��忪�ذ�ť�ؼ�ʵ���ļ�
 * ����:�������������ļ��Ŀ�������
 */
mySwitchButton::mySwitchButton(QWidget *parent): QPushButton(parent)
{    
    setCursor(QCursor(Qt::PointingHandCursor));
    isCheck = false;

    styleOn = "border-image: url(:/images/switch/btncheckon.png); border: 0px;";
    styleOff = "border-image: url(:/images/switch/btncheckoff.png); border: 0px;";

    setFixedSize(80,30);            //������仯��С
    setStyleSheet(styleOff);        //���õ�ǰ��ʽ
    connect(this,SIGNAL(clicked()),this,SLOT(ChangeOnOff()));
    this->setFlat(true);
}

void mySwitchButton::ChangeOnOff()
{
    if (isCheck){
        setStyleSheet(styleOff);
        isCheck = false;
    }else{
        setStyleSheet(styleOn);
        isCheck = true;
    }
}

//���õ�ǰѡ��״̬
void mySwitchButton::SetCheck(bool isCheck)
{
    if (this->isCheck != isCheck)
    {
        this->isCheck = !isCheck;
        ChangeOnOff();
    }
}
