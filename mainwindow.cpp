#include "mainwindow.h"
#include "ui_mainwindow.h"

bool is_binary_operation_in_action = false;
bool is_first_action_after_operation_selection = false;
double previous_number;

QString previous_operation;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->push_button_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->push_button_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->push_button_divide, SIGNAL(released()), this, SLOT(on_push_button_any_binary_released()));
    connect(ui->push_button_sum, SIGNAL(released()), this, SLOT(on_push_button_any_binary_released()));
    connect(ui->push_button_subtract, SIGNAL(released()), this, SLOT(on_push_button_any_binary_released()));
    connect(ui->push_button_multiply, SIGNAL(released()), this, SLOT(on_push_button_any_binary_released()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::digit_pressed() {
    QPushButton * button = (QPushButton*) sender();

    if (is_first_action_after_operation_selection == true) {
        ui->label->setText("");
        is_first_action_after_operation_selection = false;
    }

    if (ui->label->text() == "0") {
        ui->label->setText("");
    }

    ui->label->setText(ui->label->text() + button->text());
}


void MainWindow::on_push_button_point_released() {
    if (!ui->label->text().contains(".")) {
        ui->label->setText(ui->label->text() + ".");
    }
}


void MainWindow::on_push_button_change_sign_released() {
    if (ui->label->text() != "0") {
        if (ui->label->text().contains("-")) {
            ui->label->setText(ui->label->text().remove(0, 1));
        } else {
            ui->label->setText("-" + ui->label->text());
        }
    }
}

void MainWindow::on_push_button_cancel_released() {
    previous_number = 0;
    is_binary_operation_in_action = false;
    is_first_action_after_operation_selection = false;

    ui->label->setText("0");
}

void MainWindow::on_push_button_percent_released() {
    double number = ui->label->text().toDouble();
    number *= 0.01;
    ui->label->setText(QString::number(number));
}

void MainWindow::on_push_button_any_binary_released() {
    QPushButton * button = (QPushButton*) sender();

    QString operation = button->text();
    double current_number = ui->label->text().toDouble();

    if (is_binary_operation_in_action == false) {
        previous_number = current_number;
        previous_operation = operation;
        is_binary_operation_in_action = true;
        is_first_action_after_operation_selection = true;
    }
}

void MainWindow::on_push_button_equal_released() {
    double current_number = ui->label->text().toDouble();

    if (is_binary_operation_in_action == true) {
        if (is_first_action_after_operation_selection == false) {
            double newNumber;

            if (previous_operation == "÷") {
                newNumber = previous_number / current_number;
            } else if (previous_operation == "×") {
                newNumber = previous_number * current_number;
            } else if (previous_operation == "+") {
                newNumber = previous_number + current_number;
            } if (previous_operation == "-") {
                newNumber = previous_number - current_number;
            }

            ui->label->setText(QString::number(newNumber));

            previous_number = 0;
            is_binary_operation_in_action = false;
            is_first_action_after_operation_selection = false;
        }
    }
}
