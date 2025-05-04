#ifndef _AUSTEN_H_
#define _AUSTEN_H_
#include <QtWidgets/QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "austen_quiz.h"

class QPushButton;

class Austen : public QDialog{
    Q_OBJECT
    public:
        explicit Austen(QWidget *parent=0);
        
    private slots:
        void onB();
        void nextq();
    private:

        QPushButton *back_Button=nullptr;
        AustenQuiz* q_Queue(int n);
        AustenQuiz *q=nullptr;
        QVBoxLayout *vlay=nullptr;
        QHBoxLayout *hlay=nullptr;

        int q_Num=1;
        int score=0;
        int past_pts=0;

};

#endif
