#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "packagesdialog.h"
#include "updatescriptsdialog.h"
#include <QMessageBox>

///////////////////////PACKAGES TAB///////////////////////

QString MainWindow::returnMainRepo(){
    QString text = ui->lineRepoMain->toPlainText();
    qDebug() << " El contenido de texto es" + text;
    QMessageBox::information(this,"Title",ui->lineRepoMain->toPlainText());
    return text;
}

void MainWindow::on_restoreToDefaultsButton_clicked()
{
    ui->remoteRepoButton->setChecked(true);
    ui->lineRemoteRepo->setText("https://github.com/adgellida/ubuntupackages");
    ui->lineRepoMain->setText("~/.ubunsys/downloads/ubuntupackages-master/apps1");
    ui->lineRepoCat->setText("~/.ubunsys/downloads/ubuntupackages-master/apps1-categories");

    ui->localRepoButton->setCheckable(false);
    ui->lineRemoteRepo->setEnabled(false);
    ui->lineRepoMain->setEnabled(false);
    ui->lineRepoCat->setEnabled(false);

    system("rm ~/.ubunsys/configurations/reposRemote.cfg");
    system("echo https://github.com/adgellida/ubuntupackages > ~/.ubunsys/configurations/reposRemote.cfg");

    system("rm ~/.ubunsys/configurations/reposMainFolder.cfg");
    system("echo ~/.ubunsys/downloads/ubuntupackages-master/apps1 > ~/.ubunsys/configurations/reposMainFolder.cfg");

    system("rm ~/.ubunsys/configurations/reposCategoriesFolder.cfg");
    system("echo ~/.ubunsys/downloads/ubuntupackages-master/apps1-categories > ~/.ubunsys/configurations/reposCategoriesFolder.cfg");
}

void MainWindow::on_enterUnofficialReposButton_clicked()
{

    //MainWindow testObject;
    //QString location = testObject.returnMainRepo();

    QString text2 = returnMainRepo();
qDebug() << " El contenido de texto FINAL es" + text2;

    ui->localRepoButton->setCheckable(true);
    ui->lineRemoteRepo->setEnabled(true);
    ui->lineRepoMain->setEnabled(true);
    ui->lineRepoCat->setEnabled(true);

    ui->remoteRepoButton->setChecked(true);
    ui->lineRemoteRepo->clear();
    ui->lineRepoMain->clear();
    ui->lineRepoCat->clear();

    //system("rm ~/.ubunsys/configurations/reposRemote.cfg");
    //system("rm ~/.ubunsys/configurations/reposMainFolder.cfg");
    //system("rm ~/.ubunsys/configurations/reposCategoriesFolder.cfg");

    //system("touch ~/.ubunsys/configurations/reposRemote.cfg");
    //system("touch ~/.ubunsys/configurations/reposMainFolder.cfg");
    //system("touch ~/.ubunsys/configurations/reposCategoriesFolder.cfg");

    QFile file1 (QDir::homePath() + "/.ubunsys/configurations/reposRemote.cfg");
    if(!file1.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in1(&file1);
    ui->lineRemoteRepo->setText(in1.readAll());


    QFile file2 (QDir::homePath() + "/.ubunsys/configurations/reposMainFolder.cfg");
    if(!file2.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in2(&file2);
    ui->lineRepoMain->setText(in2.readAll());


    QFile file3 (QDir::homePath() + "/.ubunsys/configurations/reposCategoriesFolder.cfg");
    if(!file3.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in3(&file3);
    ui->lineRepoCat->setText(in3.readAll());
}

void MainWindow::on_saveReposButton_clicked()
{

    QString text1 = ui->lineRemoteRepo->toPlainText();

    system("rm ~/.ubunsys/configurations/reposRemote.cfg");
    //system("echo https://github.com/adgellida/ubuntupackages > ~/.ubunsys/configurations/reposRemote.cfg");

    QFile file1 (QDir::homePath() + "/.ubunsys/configurations/reposRemote.cfg");
    if ( file1.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file1 );
        stream << text1 << endl;
    }



    QString text2 = ui->lineRepoMain->toPlainText();

    system("rm ~/.ubunsys/configurations/reposMainFolder.cfg");
    //system("echo https://github.com/adgellida/ubuntupackages > ~/.ubunsys/configurations/reposRemote.cfg");

    QFile file2 (QDir::homePath() + "/.ubunsys/configurations/reposMainFolder.cfg");
    if ( file2.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file2 );
        stream << text2 << endl;
    }


    QString text3 = ui->lineRepoCat->toPlainText();

    system("rm ~/.ubunsys/configurations/reposCategoriesFolder.cfg");
    //system("echo https://github.com/adgellida/ubuntupackages > ~/.ubunsys/configurations/reposRemote.cfg");

    QFile file3 (QDir::homePath() + "/.ubunsys/configurations/reposCategoriesFolder.cfg");
    if ( file3.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file3 );
        stream << text3 << endl;
    }



}

