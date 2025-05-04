#ifndef _AUSTEN_QUIZ_H_
#define _AUSTEN_QUIZ_H_
#include <iostream>
#include <QRadioButton>
#include <QLabel>
#include <QDialog>

class QPushButton;

using namespace std;

class AustenQuiz: public QDialog{
    Q_OBJECT

    public:
        void q_1();
        void q_2();
        void q_3();
        void q_4();
        void q_5();
        void q_6();
        void q_7();
        void q_8();
        void q_9();
        void q_10();

        QLabel *qL1;

        QRadioButton *qR1;
        QRadioButton *qR2;
        QRadioButton *qR3;
        QRadioButton *qR4;

        QRadioButton *correct;

        QPushButton *sub_Button;
        int points=0;
    private slots:
        void onSubmit(const QString &message);
    signals:
        void done();

};
#endif
