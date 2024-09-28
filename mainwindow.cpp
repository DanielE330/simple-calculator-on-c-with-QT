#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //УКАЗЫВАЕМ, ЧТО МЫ РАБОТАЕМ С pushButton_0
                           //считываем сигнал   работаем с этим классом
    //                                              указываем какой слот срабатывает
    connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plusMinus,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_procent,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multi,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mines,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_share,SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_mines->setCheckable(true);
    ui->pushButton_multi->setCheckable(true);
    ui->pushButton_share->setCheckable(true);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){
    //создание переменной  приводим к данному классу
    //                                  принимаем значение
    QPushButton* button = (QPushButton*)sender();

    double allNumbers;
    QString result;

    if(ui->result_show->text().contains(".") && button->text()==0){
        result = ui->result_show->text() + button->text();
    }
    else{
        allNumbers = (ui->result_show->text() + button->text()).toDouble();
        result = QString::number(allNumbers, 'g', 15);

    }
    ui->result_show->setText(result);

}

void MainWindow::operations(){
    QPushButton* button = (QPushButton*)sender();

    double allNumbers;
    QString result;

    if(button->text()=="+/-"){
        allNumbers = (ui->result_show->text() + button->text()).toDouble();
        allNumbers *= -1;
        result = QString::number(allNumbers, 'g', 15);


    }

    else if(button->text()=="%"){
        allNumbers = (ui->result_show->text() + button->text()).toDouble();
        allNumbers *= 0.01;
        result = QString::number(allNumbers, 'g', 15);


    }

    ui->result_show->setText(result);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_mines->setChecked(false);
    ui->pushButton_multi->setChecked(false);
    ui->pushButton_share->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::math_operations()
{
    QPushButton* button = (QPushButton*)sender();

    firstNum = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);

}

void MainWindow::on_pushButton_result_clicked()
{
    double labelNum, secondNum;
    QString result;
    secondNum = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNum = firstNum + secondNum;
        result = QString::number(labelNum, 'g', 15);

        ui->result_show->setText(result);

        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_mines->isChecked()){
        labelNum = firstNum - secondNum;
        result = QString::number(labelNum, 'g', 15);

        ui->result_show->setText(result);

        ui->pushButton_mines->setChecked(false);
    }
    else if(ui->pushButton_multi->isChecked()){
        labelNum = firstNum * secondNum;
        result = QString::number(labelNum, 'g', 15);

        ui->result_show->setText(result);

        ui->pushButton_multi->setChecked(false);
    }
    else if(ui->pushButton_share->isChecked()){
        if(secondNum == 0){
            ui->result_show->setText("0");
        }
        else{
            labelNum = firstNum / secondNum;
            result = QString::number(labelNum, 'g', 15);

            ui->result_show->setText(result);
        }
            ui->pushButton_share->setChecked(false);


    }


}
