#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    //禁用表格更改
    ui->TicketsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->DeleteTicketsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_Inquire_clicked()
{
    Inquire(this->ui,TIME_PLACE);

    qDebug()<<"Admin Inquire";
}


void Admin::on_InquireByTime_clicked()
{
    Inquire(this->ui,TIME);

    qDebug()<<"Admin InquireByTime";
}


void Admin::on_InquireByPlace_clicked()
{
    Inquire(this->ui,PLACE);

    qDebug()<<"Admin InquireByPlace";
}


void Admin::on_ADD_clicked()
{
    ERROR_TYPE et = Add(this->ui);
    if(et==ADD_FAILURE)
        QMessageBox::information(this,"警告","添加失败");
    else if(et == INVALID_INPUT)
        QMessageBox::information(this,"警告","输入有误，请检查");
    else
        QMessageBox::information(this, "成功", "添加成功！");
    qDebug() << "Admin Add";
}


void Admin::on_DeleteInquire_clicked()
{
    ERROR_TYPE et = Inquire(this->ui,true);
    if(et==INQUIRE_FAILURE_BLANKET)
    {
        QMessageBox::information(this,"警告","没有符合条件的航班！");
    }
    else if(et==INVALID_INPUT)
    {
        QMessageBox::information(this,"警告","请输入正确的航班号！");
    }

    qDebug()<<"Admin DeleteInquire";
}


void Admin::on_Delete_clicked()
{
    if(Delete(this->ui)==SUCCESS)
        QMessageBox::information(this,"成功","删除成功！");
    else
        QMessageBox::information(this,"失败","删除失败！");
    qDebug()<<"Admin Delete";
}


void Admin::on_ChangeInquire_clicked()
{
    ERROR_TYPE  et = Inquire(this->ui,false);
    if(et==INQUIRE_FAILURE_BLANKET)
    {
        QMessageBox::information(this,"警告","没有符合条件的航班！");
    }
    else if(et == INVALID_INPUT)
    {
        QMessageBox::information(this,"警告","请输入正确的航班号！");
    }

    qDebug()<<"Admin ChangeInquire";
}


void Admin::on_Change_clicked()
{
    if(Change(this->ui)==SUCCESS)
        QMessageBox::information(this,"成功","修改成功！");
    else
        QMessageBox::information(this,"失败","修改失败！");
    qDebug()<<"Admin Change";
}



void Admin::on_SortByPrice_clicked()
{
    sortByPrice();
    WriteInTicketsTable(this->ui);

    qDebug()<<"Admin SortByPrice";
}


void Admin::on_SortByTime_clicked()
{
    sortByStartTime();
    WriteInTicketsTable(this->ui);

    qDebug() << "Admin SortByTime";
}

void Admin::on_Exit_clicked() {
    emit(try_exit());
    this->close();

    qDebug()<<"Admin Exit";
}

void  Admin::on_RemoveNULL_clicked() {
    if(RemoveNULL())
        QMessageBox::information(this,"成功","删除成功！");
    else
        QMessageBox::information(this,"失败","删除失败！");
    qDebug()<<"Admin RemoveNULL";
}