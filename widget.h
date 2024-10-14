#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void RGB_to_XYZ();
    double rgb_f(double x);
    double xyz_lab_f(double x);
    double lab_xyz_f(double x);
    double xyz_rgb_f(double x);
    void XYZ_to_RGB();
    void XYZ_TO_LAB();
    void LAB_TO_XYZ();
    void Change_color(int r, int g, int b);
    bool updating=false;
    void showError() {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Incorrect value");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }


private slots:
    void on_Choose_color_clicked();

    void on_red_slider_valueChanged(int value);

    void on_RGB_R_editingFinished();

    void on_RGB_G_editingFinished();

    void on_RGB_B_editingFinished();

    void on_XYZ_X_editingFinished();

    void on_XYZ_Y_editingFinished();

    void on_XYZ_Z_editingFinished();

    void on_Lab_L_editingFinished();

    void on_Lab_a_editingFinished();

    void on_Lab_b_editingFinished();

    void on_green_slider_valueChanged(int value);

    void on_blue_slider_valueChanged(int value);

    void on_X_slider_valueChanged(int value);

    void on_Y_slider_valueChanged(int value);

    void on_Z_slider_valueChanged(int value);

    void on_L_slider_valueChanged(int value);

    void on_a_slider_valueChanged(int value);

    void on_b_slider_valueChanged(int value);

protected:
    Ui::Widget *ui;
};
#endif // WIDGET_H
