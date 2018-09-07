#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QWidget>
#include "drop_shadow_widget.h"
#include "push_button.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>

class LoginDialog : public DropShadowWidget
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = 0);
    
private:
    void initForm();
    void initConnect();
    void translateLanguage();

    void paintEvent(QPaintEvent *event);
signals:
    
private slots:
    void slot_verify();

private:
    QLabel *m_labelIcon;
    QLabel *m_labelTitle;
    QLabel *m_labelName;                //
    QLabel *m_labelPwd;                 //
    QComboBox *m_comboBox_account;      //�û��������
    QLineEdit *m_lineEditPwd;           //���������
    PushButton *m_closeButton;
    QPushButton *m_loginButton;          //��¼��ť

    QHBoxLayout *m_titleLayout;         //����������
    QGridLayout *m_grid_layout;
    QHBoxLayout *m_bottomLayout;        //�ײ�����
    QVBoxLayout *m_mainLayout;          //������
    
};

#endif // LOGINDIALOG_H
