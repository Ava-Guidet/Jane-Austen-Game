#include "austen_quiz.h"
#include <iostream>
#include <QPushButton>
#include <QMessageBox>
#include <QString>

using namespace std;

void AustenQuiz::onSubmit(const QString &message){
    QStringList ans= correct->text().split(" ");
    ans.removeAt(0);
    QString newAns= ans.join(" ");
    QMessageBox msg;
    msg.setIconPixmap(QPixmap("/Users/avg/downloads/310_jane-austen_image1.png"));

    if(correct && correct->isChecked()){
        msg.setText("That was the correct answer!! You get a point!");
        points++;
    } else{
        QString display_Ans= "That was the wrong answer. The correct one was: "+ newAns;
        msg.setText("Oops! " + display_Ans);
    }
    msg.exec();
    QMessageBox info;
    info.setText("Regency Context:\n\n"+message);
    info.setIconPixmap(QPixmap("/Users/avg/downloads/infoJane.png"));
    info.exec();
    emit done();
}

void AustenQuiz::q_1(){
    qL1= new QLabel("1. What did Mr. Bennet do when Lydia ran away?");

    qR1= new QRadioButton("a. He didn't do anything, he didn't care");
    qR2= new QRadioButton("b. He sent the servants to look for her");
    qR3= new QRadioButton("c. He sent Elizabeth to London to look for her");
    qR4= new QRadioButton("d. He went to London alone to look for her");

    correct= qR4;
    sub_Button= new QPushButton("Submit", this);
    QString msg= "In the Regency, when it came to physical mobility—particularly the freedom associated with it—there were clear differences based on gender."
                " Men like Mr. Bennet were able to travel to places like London by themselves, for example, without consequence. This independence was a privilege belonging to men only.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
    
    
}
void AustenQuiz::q_2(){
    qL1= new QLabel("2. Elizabeth's quest to see her sister, who was sick at Netherfield, was seen as: ");

    qR1= new QRadioButton("a. Abnormal");
    qR2= new QRadioButton("b. Selfless");
    qR3= new QRadioButton("c. Selfish");
    qR4= new QRadioButton("d. Normal");
    
    correct= qR1;
    sub_Button= new QPushButton("Submit", this);
    QString msg= "Today, a woman walking alone may be considered normal, yet in the novel, Elizabeth's solo excursion was considered abnormal."
                " Why? Women were expected to be accompanied by a chaperone when walking. Walking alone was seen as unfeminine or could be thought to suggest sexual intentions.";

    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
}
void AustenQuiz::q_3(){
    qL1= new QLabel("3. What did Mr. Bingley do when he believed Jane had no feelings for him?");

    qR1= new QRadioButton("a. He didn't care");
    qR2= new QRadioButton("b. He set her up with someone else");
    qR3= new QRadioButton("c. He proposed to Elizabeth instead");
    qR4= new QRadioButton("d. He left Netherfield");

    correct= qR4;

    sub_Button= new QPushButton("Submit", this);
    QString msg= "Mr. Bingley exercised his freedom to relocate when he left Netherfield because it no longer served him."
                " In this period, men could decide for themselves where they wanted to live, whereas the only time in a woman's life when she could willingly move was when she married.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
    
}
void AustenQuiz::q_4(){
    qL1= new QLabel("4. What was Mrs. Bennet's main concern?");

    qR1= new QRadioButton("a. Planning parties");
    qR2= new QRadioButton("b. Writing letters to her sister");
    qR3= new QRadioButton("c. Ensuring that her daughters were married");
    qR4= new QRadioButton("d. Thoroughly educating her daughters");

    correct= qR3;

    sub_Button= new QPushButton("Submit", this);
    QString msg= "While Mrs. Bennet may seem obsessive about marriage, this intense focus on it was logical at the time."
                " It was virtually the only way in which women could have financial security in economic and social systems that favored men.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
    
}
void AustenQuiz::q_5(){

    qL1= new QLabel("5. Why was Elizabeth frustrated with her friend Charlotte?");

    qR1= new QRadioButton("a. She married Mr. Collins");
    qR2= new QRadioButton("b. She married Mr. Darcy");
    qR3= new QRadioButton("c. She eloped with Mr. Wickham");
    qR4= new QRadioButton("d. No legitimate reason");

    correct= qR1;
    sub_Button= new QPushButton("Submit", this);
    QString msg= "Men inherited livings and they had access to a sufficient amount of job opportunities, allowing them to be self-sufficient."
                " Women, however, were largely dependent on marriage, as they were less equipped to financially support themselves.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
}
void AustenQuiz::q_6(){
    
    qL1= new QLabel("6. How did Mrs. Bennet react when Elizabeth declined Mr. Collins' proposal?");

    qR1= new QRadioButton("a. She understood");
    qR2= new QRadioButton("b. She was happy about it");
    qR3= new QRadioButton("c. She didn't care");
    qR4= new QRadioButton("d. She was mad at her");

    correct= qR4;
    
    sub_Button= new QPushButton("Submit", this);
    QString msg="Women had limited job opportunities and could inherit a one-time sum of money, making them unable to support themselves as well as men could." 
                " Thus, marrying a man was essential to be able to be financially secure as a woman."
                " Mrs. Bennet was mad, then, because marrying Mr. Collins would have guaranteed security for the Bennet women, as they would be able to continue residing at the Longbourn estate, which he was to inherit.";

    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
    
}
void AustenQuiz::q_7(){
    
    qL1= new QLabel("7. Why was Mr. Wickham interested in marrying Georgiana?");

    qR1= new QRadioButton("a. He always loved her");
    qR2= new QRadioButton("b. He wanted her inheritence");
    qR3= new QRadioButton("c. He was going to marry her as a favor to Mr. Darcy");
    qR4= new QRadioButton("d. Lady Catherine De Bourgh told him to marry her");

    correct= qR2;

    sub_Button= new QPushButton("Submit", this);
    QString msg= "Marriage presented many restrictions on the rights of women, treating them virtually as the property of their husbands."
                " Upon marriage, all legal and financial possessions became their husbands', under coverture. Consequently, a marriage to Georgiana would ensure that Mr. Wickham would possess her inheritance.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });

}
void AustenQuiz::q_8(){
    qL1= new QLabel("8. What did Elizabeth think of Lydia's trip to Brighton?");

    qR1= new QRadioButton("a. She thought she shouldn't go because she would get herself into trouble");
    qR2= new QRadioButton("b. She thought it would be good for her to be independent");
    qR3= new QRadioButton("c. She believed it would teach Lydia how to be a lady");
    qR4= new QRadioButton("d. She was jealous of her");

    correct= qR1;
    sub_Button= new QPushButton("Submit", this);
    QString msg= "As we've seen in the novel, Lydia was quite obsessive when it came to marriage and finding a man,"
                " essentially throwing herself at the militia regiment. Elizabeth was wary of Lydia's trip because women in the Regency era had to appear chaste,"
                " as they were heavily judged on the way they looked and carried themselves."
                " Chastity was said to aid them in having other moral qualities and increase their appeal to potential suitors.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });

}
void AustenQuiz::q_9(){
    qL1= new QLabel("9. Why was Lydia's elopement taken so seriously? ");

    qR1= new QRadioButton("a. Mrs. Bennet wanted to be there when she got married");
    qR2= new QRadioButton("b. It was not in Lydia's character");
    qR3= new QRadioButton("c. Eloping would damage her reputation");
    qR4= new QRadioButton("d. Mr. Wickham was a complete stranger to the Bennets");
    correct= qR3;
    sub_Button= new QPushButton("Submit", this);
    QString msg= "Lydia's elopement would have resulted in damage to her reputation. A woman's reputation was extremely delicate and easily ruined in Regency England."
                " For example, if a woman ever appeared unchaste, it would damage her reputation. It was believed to be a serious offense, as it could have, allegedly, affected the morality of England.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
    
}
void AustenQuiz::q_10(){
    qL1= new QLabel("10. What was Mr. Collins' reaction to Lydia's elopment?");

    qR1= new QRadioButton("a. He believed it would damage the family's reputation as a whole");
    qR2= new QRadioButton("b. He was happy for them and wished them well");
    qR3= new QRadioButton("c. He was jealous of Mr. Wickham");
    qR4= new QRadioButton("d. He didn't believe Mr. Wickham was good enough for Lydia");
    correct= qR1;
    sub_Button= new QPushButton("Submit", this);
    QString msg= "Mr. Collins explained how the family name would be damaged as a result of the elopment...but how? A woman's ruined reputation not only affected her, but her family as well."
                " A woman in this predicament would often be shunned by her family, friends, and society in order to keep the family's reputation intact,"
                " as well as to protect society and England since her unchaste tendencies would damage the morality of both.";
    connect (sub_Button, &QPushButton::clicked, this, [this,msg](){
        this->onSubmit(msg);
    });
    
}
