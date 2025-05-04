#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QApplication>
#include <QString>
#include "austen.h"
#include "austen_quiz.h"




Austen::Austen(QWidget *parent):QDialog(parent){
    setWindowTitle("Pride and Prejudice Quiz");
    
    back_Button= new QPushButton("Back", this);
    connect(back_Button, &QPushButton::clicked, this, &Austen::onB);


    vlay= new QVBoxLayout(this);
    
    q= q_Queue(q_Num);
}

void Austen::onB(){
    if(q_Num>1){
        q_Num--;
        q=q_Queue(q_Num);
    }
}

void Austen::nextq(){
    if(q_Num<10){
        q_Num++;
        q=q_Queue(q_Num);
    }
    else if(q_Num==10){
        if(score>=10){
            score=10;
        }
        QMessageBox end;
        end.setIconPixmap(QPixmap("/Users/avg/downloads/extraPartyJane.png"));
        end.setText(QString("Congrats! You finished! You scored %1 out of 10 points.").arg(score));
        end.exec();
        QApplication::quit();
    }
}
AustenQuiz* Austen::q_Queue(int n){
    if(q_Num==1){
        QMessageBox start;
        start.setIconPixmap(QPixmap("/Users/avg/downloads/Keira.png"));
        QString s_msg= "Think you know the Bennets? Are you a true Janeite? Test your knowledge of Jane Austen's most beloved novel!";
        start.setText("Pride, Prejudice, and Propriety: A Jane Austen Quiz\n\n" +s_msg);
        start.exec();
    }
    if(q){
        if(q->qL1){
            vlay->removeWidget(q->qL1);
            q->qL1->deleteLater();
        }
        if(q->qR1){
            vlay->removeWidget(q->qR1);
            q->qR1->deleteLater();
        }
        if(q->qR2){
            vlay->removeWidget(q->qR2);
            q->qR2->deleteLater();
        }
        if(q->qR3){
            vlay->removeWidget(q->qR3);
            q->qR3->deleteLater();
        }
        if(q->qR4){
            vlay->removeWidget(q->qR4);
            q->qR4->deleteLater();
        }
        if(q->sub_Button){
            vlay->removeWidget(q->sub_Button);
            q->sub_Button->hide();
            q->sub_Button->setParent(nullptr);
            q->sub_Button->deleteLater();
        }
        delete q;
        q=nullptr;
    }
    q= new AustenQuiz();
    switch (n){
        case 1: 
            q->q_1();
            break;
        case 2:
            q->q_2();
            break;
        case 3:
            q->q_3();
            break;
        case 4:
            q->q_4();
            break;
        case 5: 
            q->q_5();
            break;
        case 6:
            q->q_6();
            break;
        case 7:
            q->q_7();
            break;
        case 8:
            q->q_8();
            break;
        case 9:
            q->q_9();
            break;
        case 10:
            q->q_10();
            break;
    }
    
    disconnect(q, &AustenQuiz::done, this,&Austen::nextq);
    
    vlay->addWidget(q->qL1);
    vlay->addWidget(q->qR1);
    vlay->addWidget(q->qR2);
    vlay->addWidget(q->qR3);
    vlay->addWidget(q->qR4);

    connect(q, &AustenQuiz::done, this,[this](){
        if(q->points == 1){
            score++;
        }
        nextq();
    });

    if(hlay){
        vlay->removeItem(hlay);
        delete hlay;
        hlay=nullptr;
    }

    hlay= new QHBoxLayout();
    hlay->addWidget(back_Button);
    hlay->addStretch();
    hlay->addWidget(q->sub_Button);

    vlay->addLayout(hlay);

    back_Button->setVisible(q_Num!=1);

    return q;
}
