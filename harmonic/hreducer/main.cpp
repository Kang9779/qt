#include "hreducer.h"
#include <QApplication>
#include <login.h>
#include <logindialog.h>
/**
 * @brief qMain
 * @param argc
 * @param argv
 * @return
 *          多窗口切换调用
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HReducer w;
    w.show();
    return a.exec();
//    LoginDialog lg;
//    if(lg.exec()==QDialog::Accepted)//利用Accepted返回值判断按钮是否被按下
//    {
//        w.show();//按钮按下显示主窗口
//        return a.exec();//程序一直执行
//    }
//    else
//        return 0;
}
