/***************************************************************
 *Copyright(c) 2014-2015 Company By LH Unigress
 *All rights reserved.
 *�ļ����ƣ����ݿ�����ļ�
 *��Ҫ���������ݿ�����ļ�����߷�װ�˳�������sqlite��MySQL�������,
 *        �����ⲿ���е���
 *��ǰ�汾��3.0
 *���ߣ�Kelvin Li
 *�������ڣ�2014/10
 *�޸����ڣ�2015/07
 *˵����
*****************************************************************/
#ifndef SQLHELP_H
#define SQLHELP_H

#include <QObject>

class QComboBox;
class QPushButton;
class QTableView;
class QLabel;
class QSqlQueryModel;

class SqlHelp : public QObject
{
    Q_OBJECT
public:
    explicit SqlHelp(QObject *parent = 0);

    //����ĳһ�����е�ID���ֵ
    QString GetTableMaxId(const QString tableName,
                       const QString IdName);
    //����ĳһ�����е�ĳһ�е�ֵ
    QString GetTableColumnValue(const QString &tableName,
                                const QString &sql);

    //����ĳ��ID�Ƿ����
    bool FindIDiSEist(const QString&,const QString &,const QString &);
    //ɾ��ĳ�����е�ĳһ������
    bool DeleteTableInfo(const QString &tableName,
                         const QString &where);

    //ִ��һ��sql���
    bool ExecuteSql(const QString &sql);

    //�����ݰ󶨵���������
    void BindDataToCombox(const QString &tableName,
                          const QString &tableColumnName,
                          QComboBox *cbox);

    //������Ҫ��ʾ���ݵı��,���ݷ�ҳ��Ӧ�İ�ť
    void SetControlTable(QTableView *tableview,QLabel *labInfo,
                         QPushButton *btnFirst,QPushButton *btnPre,
                         QPushButton *btnNext,QPushButton *btnLast);

    //������,������������������
    void BindData(QString tableName,QString orderColumn,QString orderType,int rowsCount,
                  QString columnNames[], int columnWidths[]);
    void BindDataSelect(QString tableName,QString orderColumn,
                        QString orderType,QString where,int rowsCount,
                        QString columnNames[], int columnWidths[]);

    //�������ݰ���ʾ�����������ģ�ȫ����ʾ���ݱ������ݣ�
    void BindTable(QString tableName, QTableView *tableview,
                   QString columnNames[], int columnWidths[]);
    //���ݰ󶨲���ʾ������ѯ����
    void BindTableWhere(QString sql, QTableView *tableview,
                   QString columnNames[], int columnWidths[]);

    //����ĳ����������һ�е�����
    QStringList getColumnData(const QString &sql);

    //��ѯĳ������ĳ���ֶ����һ����¼
    QString getLastRecord(const QString &tableName,const QString &findValue,
                          const QString &column,const QString &columnValue);

    //�����豸�������һ������
    QStringList getDeviceLastValue(const QString &device_id);
private:
    void BindData(QString sql);     //���ݰ�
private slots:
    void slot_FirstPage();          //��һҳ
    void slot_PreviousPage();       //��һҳ
    void slot_NextPage();           //��һҳ
    void slot_LastPage();           //ĩһҳ

private:
    int StartIndex;                 //��ҳ��ʼ����,ÿ�η�ҳ���䶯
    QString TempSql;                //��ʱSQL���
    QString Sql;

    int RowsCount;                  //ÿҳ��ʾ����
    int RowsCountAll;               //������
    int PageCount;                  //��ҳ��
    int PageCurrent;                //��ǰ�ڼ�ҳ

    QTableView *TableView;          //��ʾ���ݵı�����
    QLabel *LabInfo;                //��ʾ��ҳ��Ϣ
    QPushButton *BtnFirst;          //��һҳ��ť����
    QPushButton *BtnPre;            //��һҳ��ť����
    QPushButton *BtnNext;           //��һҳ��ť����
    QPushButton *BtnLast;           //ĩһҳ��ť����

    QSqlQueryModel *QueryModel;     //��ѯģ��
};

#endif // MYSQLHELP_H
