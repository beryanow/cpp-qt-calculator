#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_push_button_point_released();
    void on_push_button_change_sign_released();
    void on_push_button_cancel_released();
    void on_push_button_equal_released();
    void on_push_button_percent_released();
    void on_push_button_any_binary_released();
};

#endif // MAINWINDOW_H
