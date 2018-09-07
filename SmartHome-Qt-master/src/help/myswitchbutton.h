#ifndef MYSWITCHBUTTON_H
#define MYSWITCHBUTTON_H

#include <QPushButton>

/* ˵��:�Զ��忪�ذ�ť�ؼ�ͷ�ļ�
 * ����:�������������ļ��Ŀ�������
 */
class mySwitchButton : public QPushButton
{
    Q_OBJECT    
public:
    explicit mySwitchButton(QWidget *parent = 0);

    //��ȡ��ǰѡ��״̬
    bool GetCheck() const {return isCheck;}

    //���õ�ǰѡ��״̬
    void SetCheck(bool isCheck);

private:    
    bool isCheck;
    QString styleOn;
    QString styleOff;
    
signals:
    
private slots:    
    void ChangeOnOff();
    
};

#endif //MYSWITCHBUTTON_H
