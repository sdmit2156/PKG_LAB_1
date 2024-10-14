#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::RGB_to_XYZ()
{
    updating = true;
    double rgb_r=ui->RGB_R->text().toDouble();
    double rgb_g=ui->RGB_G->text().toDouble();
    double rgb_b=ui->RGB_B->text().toDouble();
    double Rn=rgb_f(rgb_r/255)*100;
    double Gn=rgb_f(rgb_g/255)*100;
    double Bn=rgb_f(rgb_b/255)*100;
    double xyz_x=0.412453*Rn+0.357580*Gn+0.180423*Bn;
    double xyz_y=0.212671*Rn+0.715160*Gn+0.072169*Bn;
    double xyz_z=0.019334*Rn+0.119193*Gn+0.950227*Bn;
    if(xyz_x>95) xyz_x=95; if(xyz_x<0) xyz_x=0;
    if (xyz_y>100) xyz_y =100; if(xyz_y<0) xyz_y=0;
    if (xyz_z>109) xyz_y =109; if(xyz_z<0) xyz_z=0;
    ui->XYZ_X->setText(QString::number(int(xyz_x)));
    ui->XYZ_Y->setText(QString::number(int(xyz_y)));
    ui->XYZ_Z->setText(QString::number(int(xyz_z)));
    ui->X_slider->setValue(int(xyz_x));
    ui->Y_slider->setValue(int(xyz_y));
    ui->Z_slider->setValue(int(xyz_z));
    Change_color(rgb_r, rgb_g, rgb_b);
    updating = false;
}

double Widget::rgb_f(double x)
{
    if (x>=0.04045){
        return pow(((x+0.055)/1.055),2.4);
    }
    else{
        return x/12.92;
    }
}

double Widget::xyz_lab_f(double x)
{
    if (x>=0.008856){
        return pow(x,0.33333333333333333);
    }
    else{
        return 7.787*x+16/116;
    }
}

double Widget::lab_xyz_f(double x)
{
    if (pow(x, 3)>=0.008856)
        return pow(x,3);
    else
        return (x-16/116)/7.787;
}

double Widget::xyz_rgb_f(double x)
{
    if(x>=0.0031308)
        return 1.055*pow(x,0.41666667)-0.055;
    else
        return 12.92*x;
}

void Widget::XYZ_to_RGB()
{
    updating = true;
    double x = ui->XYZ_X->text().toDouble();
    double y = ui->XYZ_Y->text().toDouble();
    double z = ui->XYZ_Z->text().toDouble();
    double Rn = 3.2406*x/100-1.5372*y/100-0.4986*z/100;
    double Gn=-0.9689*x/100+1.8758*y/100+0.0415*z/100;
    double Bn=0.0557*x/100-0.2040*y/100+1.0570*z/100;
    double R=xyz_rgb_f(Rn)*255;
    double G=xyz_rgb_f(Gn)*255;
    double B=xyz_rgb_f(Bn)*255;
    if (G>255) G=255; if (G<0) G=0;
    if (R>255) R=255; if (R<0) R=0;
    if (B>255) B=255; if (B<0) B=0;
    ui->RGB_R->setText(QString::number(int(R)));
    ui->RGB_G->setText(QString::number(int(G)));
    ui->RGB_B->setText(QString::number(int(B)));
    ui->red_slider->setValue(int(R));
    ui->green_slider->setValue(int(G));
    ui->blue_slider->setValue(int(B));
    Change_color(R, G, B);
    updating = false;
}

void Widget::XYZ_TO_LAB()
{
    updating = true;
    double x = ui->XYZ_X->text().toDouble();
    double y = ui->XYZ_Y->text().toDouble();
    double z = ui->XYZ_Z->text().toDouble();
    double L = 116*xyz_lab_f(y/100)-16;
    double a = 500*(xyz_lab_f(x/95.047)-xyz_lab_f(y/100));
    double b = 200*(xyz_lab_f(y/100)-xyz_lab_f(z/108.883));
    if (L>100) L=100; if(L<0) L=0;
    if(a>128) a=128; if(a<-127) a=-127;
    if(b>128) b=128; if(b<-127) b=-127;
    ui->Lab_L->setText(QString::number(int(L)));
    ui->Lab_a->setText(QString::number(int(a)));
    ui->Lab_b->setText(QString::number(int(b)));
    ui->L_slider->setValue(int(L));
    ui->a_slider->setValue(int(a));
    ui->b_slider->setValue(int(b));
    updating = false;
}

void Widget::LAB_TO_XYZ()
{
    updating = true;
    double L = ui->Lab_L->text().toDouble();
    double a = ui->Lab_a->text().toDouble();
    double b = ui->Lab_b->text().toDouble();
    double y=lab_xyz_f((L+16)/116)*95.047;
    double x=lab_xyz_f(a/500+(L+16)/116)*100;
    double z=lab_xyz_f((L+16)/116-b/200)*108.883;
    if(x>95) x=95; if(y<0) y=0;
    if (y>100) y =100; if(x<0) x=0;
    if (z>109) z =109; if(z<0) z=0;
    ui->XYZ_X->setText(QString::number(int(x)));
    ui->XYZ_Y->setText(QString::number(int(y)));
    ui->XYZ_Z->setText(QString::number(int(z)));
    ui->X_slider->setValue(int(x));
    ui->Y_slider->setValue(int(y));
    ui->Z_slider->setValue(int(z));
    updating = false;
}

void Widget::Change_color(int r, int g, int b)
{
    QString style = "background-color: rgb("+QString::number(r)+", "+QString::number(g)+", "+QString::number(b)+")";
    ui->Choose_color->setStyleSheet(style);
}

void Widget::on_Choose_color_clicked()
{
    QColor new_color = QColorDialog::getColor(Qt::white, this);
    if (new_color.isValid()) {
        updating = true;
        ui->RGB_R->setText(QString::number(new_color.red()));
        ui->RGB_G->setText(QString::number(new_color.green()));
        ui->RGB_B->setText(QString::number(new_color.blue()));
        ui->red_slider->setValue(new_color.red());
        ui->green_slider->setValue(new_color.green());
        ui->blue_slider->setValue(new_color.blue());
        QString style = "background-color: rgb("+QString::number(new_color.red())+", "+QString::number(new_color.green())+", "+QString::number(new_color.blue())+")";
        ui->Choose_color->setStyleSheet(style);
        RGB_to_XYZ();
        XYZ_TO_LAB();
        updating = false;
    }
}

void Widget::on_red_slider_valueChanged(int value)
{
    if (!updating){
        ui->RGB_R->setText(QString::number(value));
        RGB_to_XYZ();
        XYZ_TO_LAB();
    }

}


void Widget::on_RGB_R_editingFinished()
{
    if(ui->RGB_R->text().toInt()>255||ui->RGB_R->text().toInt()<0)
        showError();
    else{
        QString arg1 = ui->RGB_R->text();
        RGB_to_XYZ();
        XYZ_TO_LAB();
        ui->red_slider->setValue(arg1.toInt());
    }
}


void Widget::on_RGB_G_editingFinished()
{
    if(ui->RGB_G->text().toInt()>255||ui->RGB_G->text().toInt()<0)
        showError();
    else{
        QString arg1 = ui->RGB_G->text();
        RGB_to_XYZ();
        XYZ_TO_LAB();
        ui->green_slider->setValue(arg1.toInt());
    }
}


void Widget::on_RGB_B_editingFinished()
{
    if(ui->RGB_B->text().toInt()>255||ui->RGB_B->text().toInt()<0)
        showError();
    else{
        QString arg1 = ui->RGB_B->text();
        RGB_to_XYZ();
        XYZ_TO_LAB();
        ui->blue_slider->setValue(arg1.toInt());
    }
}


void Widget::on_XYZ_X_editingFinished()
{
    if(ui->XYZ_X->text().toInt()>95||ui->XYZ_X->text().toInt()<0)
        showError();
    else{
        QString arg1 = ui->XYZ_X->text();
        XYZ_TO_LAB();
        XYZ_to_RGB();
        ui->X_slider->setValue(arg1.toInt());
    }
}


void Widget::on_XYZ_Y_editingFinished()
{
    if(ui->XYZ_Y->text().toInt()>100||ui->XYZ_Y->text().toInt()<0)
        showError();
    else{
        QString arg1 = ui->XYZ_Y->text();
        XYZ_TO_LAB();
        XYZ_to_RGB();
        ui->Y_slider->setValue(arg1.toInt());
    }
}


void Widget::on_XYZ_Z_editingFinished()
{
    if(ui->XYZ_Z->text().toInt()>109||ui->XYZ_Z->text().toInt()<0)
        showError();
    else{
        QString arg1 = ui->XYZ_Z->text();
        XYZ_TO_LAB();
        XYZ_to_RGB();
        ui->Z_slider->setValue(arg1.toInt());
    }
}


void Widget::on_Lab_L_editingFinished()
{
    if(ui->Lab_L->text().toInt()>100||ui->Lab_L->text().toInt()<0)
        showError();
    else{
        QString arg1 = ui->Lab_L->text();
        LAB_TO_XYZ();
        XYZ_to_RGB();
        ui->L_slider->setValue(arg1.toInt());
    }
}


void Widget::on_Lab_a_editingFinished()
{
    if(ui->Lab_a->text().toInt()>128||ui->Lab_a->text().toInt()<-127)
        showError();
    else{
        QString arg1 = ui->Lab_a->text();
        LAB_TO_XYZ();
        XYZ_to_RGB();
        ui->a_slider->setValue(arg1.toInt());
    }
}


void Widget::on_Lab_b_editingFinished()
{
    if(ui->Lab_b->text().toInt()>128||ui->Lab_b->text().toInt()<-127)
        showError();
    else{
    QString arg1 = ui->Lab_b->text();
    LAB_TO_XYZ();
    XYZ_to_RGB();
    ui->b_slider->setValue(arg1.toInt());
    }
}


void Widget::on_green_slider_valueChanged(int value)
{
    if (!updating){
    ui->RGB_G->setText(QString::number(value));
    RGB_to_XYZ();
    XYZ_TO_LAB();
    }
}


void Widget::on_blue_slider_valueChanged(int value)
{
    if (!updating){

    ui->RGB_B->setText(QString::number(value));
    RGB_to_XYZ();
    XYZ_TO_LAB();
    }
}

void Widget::on_X_slider_valueChanged(int value)
{
    if (!updating){

    ui->XYZ_X->setText(QString::number(value));
    XYZ_TO_LAB();
    XYZ_to_RGB();

}
}


void Widget::on_Y_slider_valueChanged(int value)
{
    if (!updating){

    ui->XYZ_Y->setText(QString::number(value));
    XYZ_TO_LAB();
    XYZ_to_RGB();

}
}


void Widget::on_Z_slider_valueChanged(int value)
{
    if (!updating){

    ui->XYZ_Z->setText(QString::number(value));
    XYZ_TO_LAB();
    XYZ_to_RGB();
    }
}


void Widget::on_L_slider_valueChanged(int value)
{
    if (!updating){

    ui->Lab_L->setText(QString::number(value));
    LAB_TO_XYZ();
    XYZ_to_RGB();
    }
}


void Widget::on_a_slider_valueChanged(int value)
{
    if (!updating){

    ui->Lab_a->setText(QString::number(value));
    LAB_TO_XYZ();
    XYZ_to_RGB();
    }
}


void Widget::on_b_slider_valueChanged(int value)
{
    if (!updating){
    ui->Lab_b->setText(QString::number(value));
    LAB_TO_XYZ();
    XYZ_to_RGB();
    }
}

