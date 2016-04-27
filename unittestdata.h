#ifndef UNITTESTDATA_H
#define UNITTESTDATA_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>

namespace Ui {
class UnitTestData;
}

class UnitTestData : public QMainWindow
{
    Q_OBJECT

public:
    explicit UnitTestData(QWidget *parent = 0);
    ~UnitTestData();

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void updateCurrentFile(QString filePath);

    void on_listView_clicked(const QModelIndex &index);
    QString read_Current_File(QString filePath);

    void on_btnFilter_clicked();

private:
    Ui::UnitTestData *ui;
    QFileSystemModel * dirModel;
    QFileSystemModel * fileModel;
};

#endif // UNITTESTDATA_H
