/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *Choose_color;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *RGB;
    QHBoxLayout *horizontalLayout;
    QLineEdit *RGB_R;
    QLineEdit *RGB_G;
    QLineEdit *RGB_B;
    QHBoxLayout *horizontalLayout_4;
    QSlider *red_slider;
    QSlider *green_slider;
    QSlider *blue_slider;
    QLabel *RGB_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *XYZ_X;
    QLineEdit *XYZ_Y;
    QLineEdit *XYZ_Z;
    QHBoxLayout *horizontalLayout_5;
    QSlider *X_slider;
    QSlider *Y_slider;
    QSlider *Z_slider;
    QLabel *RGB_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *Lab_L;
    QLineEdit *Lab_a;
    QLineEdit *Lab_b;
    QHBoxLayout *horizontalLayout_6;
    QSlider *L_slider;
    QSlider *a_slider;
    QSlider *b_slider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(170, 170, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        Widget->setPalette(palette);
        Choose_color = new QPushButton(Widget);
        Choose_color->setObjectName("Choose_color");
        Choose_color->setGeometry(QRect(480, 430, 291, 131));
        sizePolicy.setHeightForWidth(Choose_color->sizePolicy().hasHeightForWidth());
        Choose_color->setSizePolicy(sizePolicy);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 490, 301, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable")});
        font.setPointSize(12);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 40, 691, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        RGB = new QLabel(verticalLayoutWidget);
        RGB->setObjectName("RGB");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI Variable Display Light")});
        font1.setPointSize(16);
        font1.setBold(true);
        RGB->setFont(font1);

        verticalLayout->addWidget(RGB);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        RGB_R = new QLineEdit(verticalLayoutWidget);
        RGB_R->setObjectName("RGB_R");

        horizontalLayout->addWidget(RGB_R);

        RGB_G = new QLineEdit(verticalLayoutWidget);
        RGB_G->setObjectName("RGB_G");

        horizontalLayout->addWidget(RGB_G);

        RGB_B = new QLineEdit(verticalLayoutWidget);
        RGB_B->setObjectName("RGB_B");

        horizontalLayout->addWidget(RGB_B);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        red_slider = new QSlider(verticalLayoutWidget);
        red_slider->setObjectName("red_slider");
        red_slider->setMaximum(255);
        red_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(red_slider);

        green_slider = new QSlider(verticalLayoutWidget);
        green_slider->setObjectName("green_slider");
        green_slider->setMaximum(255);
        green_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(green_slider);

        blue_slider = new QSlider(verticalLayoutWidget);
        blue_slider->setObjectName("blue_slider");
        blue_slider->setMaximum(255);
        blue_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(blue_slider);


        verticalLayout->addLayout(horizontalLayout_4);

        RGB_2 = new QLabel(verticalLayoutWidget);
        RGB_2->setObjectName("RGB_2");
        RGB_2->setFont(font1);

        verticalLayout->addWidget(RGB_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        XYZ_X = new QLineEdit(verticalLayoutWidget);
        XYZ_X->setObjectName("XYZ_X");

        horizontalLayout_2->addWidget(XYZ_X);

        XYZ_Y = new QLineEdit(verticalLayoutWidget);
        XYZ_Y->setObjectName("XYZ_Y");

        horizontalLayout_2->addWidget(XYZ_Y);

        XYZ_Z = new QLineEdit(verticalLayoutWidget);
        XYZ_Z->setObjectName("XYZ_Z");

        horizontalLayout_2->addWidget(XYZ_Z);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        X_slider = new QSlider(verticalLayoutWidget);
        X_slider->setObjectName("X_slider");
        X_slider->setMaximum(100);
        X_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(X_slider);

        Y_slider = new QSlider(verticalLayoutWidget);
        Y_slider->setObjectName("Y_slider");
        Y_slider->setMaximum(95);
        Y_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(Y_slider);

        Z_slider = new QSlider(verticalLayoutWidget);
        Z_slider->setObjectName("Z_slider");
        Z_slider->setMaximum(109);
        Z_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(Z_slider);


        verticalLayout->addLayout(horizontalLayout_5);

        RGB_3 = new QLabel(verticalLayoutWidget);
        RGB_3->setObjectName("RGB_3");
        RGB_3->setFont(font1);

        verticalLayout->addWidget(RGB_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Lab_L = new QLineEdit(verticalLayoutWidget);
        Lab_L->setObjectName("Lab_L");

        horizontalLayout_3->addWidget(Lab_L);

        Lab_a = new QLineEdit(verticalLayoutWidget);
        Lab_a->setObjectName("Lab_a");

        horizontalLayout_3->addWidget(Lab_a);

        Lab_b = new QLineEdit(verticalLayoutWidget);
        Lab_b->setObjectName("Lab_b");

        horizontalLayout_3->addWidget(Lab_b);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        L_slider = new QSlider(verticalLayoutWidget);
        L_slider->setObjectName("L_slider");
        L_slider->setMaximum(100);
        L_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(L_slider);

        a_slider = new QSlider(verticalLayoutWidget);
        a_slider->setObjectName("a_slider");
        a_slider->setMinimum(-127);
        a_slider->setMaximum(128);
        a_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(a_slider);

        b_slider = new QSlider(verticalLayoutWidget);
        b_slider->setObjectName("b_slider");
        b_slider->setMinimum(-127);
        b_slider->setMaximum(128);
        b_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(b_slider);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Choose_color->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "Press this buttton for choosing color", nullptr));
        RGB->setText(QCoreApplication::translate("Widget", "RGB", nullptr));
        RGB_2->setText(QCoreApplication::translate("Widget", "XYZ", nullptr));
        RGB_3->setText(QCoreApplication::translate("Widget", "Lab", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
