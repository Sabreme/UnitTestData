#include "unittestdata.h"
#include "ui_unittestdata.h"

UnitTestData::UnitTestData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UnitTestData)
{
    ui->setupUi(this);

    QString sPath = "F:/";

    dirModel = new QFileSystemModel();
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(sPath);


    ui->treeView->setModel(dirModel);

    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    fileModel = new QFileSystemModel();
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    QStringList filters;
    filters << "*.txt";
    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);



    ui->listView->setModel(fileModel);

}

UnitTestData::~UnitTestData()
{
    delete ui;
}

void UnitTestData::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(sPath));

}

void UnitTestData::updateCurrentFile(QString filePath)
{
    this->ui->currentFile->setText(read_Current_File(filePath));
}



void UnitTestData::on_listView_clicked(const QModelIndex &index)
{
    QString sPath = fileModel->fileInfo(index).absoluteFilePath();
    updateCurrentFile(sPath);
}

QString UnitTestData::read_Current_File(QString filePath)
{
    QString firstLine = "";
    QFile currentFile(filePath);
    if (!currentFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", currentFile.errorString());
        return "";
    }

    QTextStream text(&currentFile);

    while (!text.atEnd())
    {
        QString line = text.readLine();
        firstLine = line;
    }

    currentFile.close();

    return firstLine;
}

void UnitTestData::on_btnFilter_clicked()
{
    QString expression = this->ui->filterEdit->text();
    if (!expression.isNull())
    {
        QRegExp rx(expression);


}
