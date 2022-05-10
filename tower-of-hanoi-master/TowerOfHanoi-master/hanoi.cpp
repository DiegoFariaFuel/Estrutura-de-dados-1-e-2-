/**
  @file hanoi.cpp
  @authors JULIO LUGO, MARTIN BERTI, DARWIN GONZALEZ, ELVIS PÁEZ
  @name Hanoi tower
  @abstract This code was developed to solve Hanoi Tower given any starting position
  @date 08/12/2017

  */

#include "hanoi.h"
#include "ui_hanoi.h"
#include <QPainter>
#include <cmath>
# include <algorithm>
# include <QInputDialog>
# include <iostream>

disk*moving = NULL;
Hanoi::Hanoi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hanoi)
{
    ui->setupUi(this);
    value = 3;

    poles[0] = new pole(0, value,ui->pushButton_1);
    poles[1] = new pole(1, 0,ui->pushButton_2);
    poles[2] = new pole(2, 0,ui->pushButton_3);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(delayedAction()));
    autoplay=false;
    nthplay = false;
    ui->label_4->setNum(history.size());
}

///Animation

void Hanoi::delayedAction(){

    if(nthplay)
    {
        if(history.size() < n_pos){
            Move autom = schedule.dequeue();
            moving = poles[autom.getFrom()]->take();
            poles[autom.getTo()]->put(moving);
            moving = NULL;
            history.push(autom);
            ui->label_4->setNum(history.size());
        }else{
            autoplay = false;
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            timer->stop();
        }

        return;
    }
    
    if(autoplay){
        if(!schedule.empty()){
            Move autom = schedule.dequeue();
            moving = poles[autom.getFrom()]->take();
            poles[autom.getTo()]->put(moving);
            moving = NULL;
            history.push(autom);
            ui->label_4->setNum(history.size());
        }else{
            autoplay = false;
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            timer->stop();
        }

    }else{
        if(history.empty()){
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            timer->stop();
        }else{
            on_action_Undo_triggered();
        }
    }
}

///Painting the disks and poles

void Hanoi::paintEvent(QPaintEvent *event){
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QColor baseColor(207, 165, 100);
    p.setBrush(baseColor);
    p.drawRect(60,355,180,80);
    p.drawRect(60,345,180,70);

    p.drawRect(310,355,180,80);
    p.drawRect(310,345,180,70);

    p.drawRect(560,355,180,80);
    p.drawRect(560,345,180,70);
}


///Destructor

Hanoi::~Hanoi()
{
    delete ui;
    for (int i=0;i<3;i++){

        delete poles[i];
    }
    moving = NULL;
    history.clear();
    schedule.clear();
}

///Menus and buttons

void Hanoi::on_pushButton_clicked(pole* p){
    if(!moving){
        moving = p->take();
    }else{
        int from = moving->On()->getIndex();
        if(p->put(moving)){
            Move mov(from,p->getIndex());
            history.push(mov);
            moving = NULL;
            ui->label_4->setNum(history.size());
        }else{
            moving->On()->put(moving);
            ui->label_4->setNum(history.size());
            moving = NULL;
        }
    }
}


void Hanoi::CalculateAutoplay(int count, int from,  int dest, int aux){
    if(count < 1){
        return;
    }else{
        CalculateAutoplay(count-1,from,aux,dest);
        schedule.enqueue(Move(from,dest));
        CalculateAutoplay(count-1,aux,dest,from);
    }
}

int whereis(std::vector<std::vector<int>> &stack, int n)
{
  for(int i = 0; i < 3; i++)
    for(auto p: stack[i])
      if(p == n)
        return i;
}

/**
 * @param int n -> number of disks
 *        int z -> destination tower
 *        std::vector<std::vector<int>> stack -> Contains all three poles and their disks in real time
 * @return void
 * @brief It allows to solve Hanoi game in any tower given any position
 * */


void Hanoi::CalculateArbitraryPlay(int n, int z, std::vector<std::vector<int> > &stack)
{
    if(n == 0)
         return;

      int x = whereis(stack, n);

      if(x == z)
      {

        CalculateArbitraryPlay(n - 1, z, stack);
        return;
      }

      int y = 0;

        for(int i = 0; i < 3; i++)
          if(i != x && i != z)
            y = i;

        CalculateArbitraryPlay(n - 1, y, stack);


        schedule.enqueue(Move(x, z));
        stack[z].insert(stack[z].begin(), stack[x][0]);
        stack[x].erase(stack[x].begin());

        CalculateArbitraryPlay(n - 1, z, stack);
        return;
}

void Hanoi::on_pushButton_1_clicked()
{
    on_pushButton_clicked(poles[0]);

}

void Hanoi::on_pushButton_2_clicked()
{
   on_pushButton_clicked(poles[1]);
}

void Hanoi::on_pushButton_3_clicked()
{
     on_pushButton_clicked(poles[2]);
}

void Hanoi::on_action_New_triggered()
{

    for (int i=0;i<3;i++){

        delete poles[i];
    }
    if(moving){
        delete moving;
    }
    moving = NULL;
    history.clear();
    schedule.clear();
    ui->label_4->setNum(history.size());

    poles[0] = new pole(0, value,ui->pushButton_1);
    poles[1] = new pole(1, 0,ui->pushButton_2);
    poles[2] = new pole(2, 0,ui->pushButton_3);

}

void Hanoi::on_action_Undo_triggered()
{
   if(!history.empty()){
    Move mUndo = history.pop();
    pole* to = NULL;
    pole* from = NULL;
    to = poles[mUndo.getTo()];
    from = poles[mUndo.getFrom()];
    if(moving){
        moving->On()->put(moving);
        moving = NULL;
    }
    moving = to->take();
    from->put(moving);
    moving = NULL;
    ui->label_4->setNum(history.size());
}
}

void Hanoi::on_action_Undo_All_triggered()
{
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    timer->start(100);
}

void Hanoi::on_actionAuto_Play_triggered()

{
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    autoplay = true;
    nthplay = false;
    on_action_New_triggered();
    CalculateAutoplay(poles[0]->getNdisks(), 0,2,1);
    timer->start(100);
}

void Hanoi::on_action_2_triggered()
{
    value = 2;
    ui->action_New->trigger();
}

void Hanoi::on_action_3_triggered()
{
    value = 3;
    ui->action_New->trigger();
}

void Hanoi::on_action_4_triggered()
{
    value = 4;
    ui->action_New->trigger();
}

void Hanoi::on_action_5_triggered()
{
    value = 5;
    ui->action_New->trigger();
}

void Hanoi::on_action_6_triggered()
{
    value = 6;
    ui->action_New->trigger();
}

void Hanoi::on_action_7_triggered()
{
    value = 7;
    ui->action_New->trigger();
}

void Hanoi::on_action_8_triggered()
{
    value = 8;
    ui->action_New->trigger();
}

void Hanoi::on_actionNth_Play_triggered()
{
    std::string text = "Introduce step: ";
    n_pos = QInputDialog::getInt(0, "Input", text.c_str(),1);
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    nthplay = true;
    on_action_New_triggered();
    CalculateAutoplay(poles[0]->getNdisks(), 0,2,1);
    timer->start(100);
}

/**
 * @brief Hanoi::on_action_New_Arbitrary_triggered
   @param   void
   @return void
   @abstract This function interacts with the user and let him/her to choose which configuration wants
             and how many steps are required to finish the game or how many are required to reach the
             inserted configuration.
*/



void Hanoi::on_action_New_Arbitrary_triggered()
{

    for (int i=0;i<3;i++){

        delete poles[i];
    }
    if(moving){
        delete moving;
    }
    moving = NULL;
    history.clear();
    schedule.clear();


    std::vector<std::vector<int>> stacks(3);

    for(int i = 1; i <= value; i++)
    {
        std::string text = "Which pole do you want to put disk " + std::to_string(i) + "?";
        int p = QInputDialog::getInt(0, "Input", text.c_str(),1);
        stacks[p - 1].push_back(i);
        std::sort(stacks[p - 1].rbegin(), stacks[p - 1].rend());
    }


    poles[0] = new pole(0, stacks[0],ui->pushButton_1);
    poles[1] = new pole(1, stacks[1],ui->pushButton_2);
    poles[2] = new pole(2, stacks[2],ui->pushButton_3);

    std::string text("Do you wanna know token (1) or remaining steps (2)?");
    int p = QInputDialog::getInt(0, "Input", text.c_str(),1);

    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);

    nthplay = false;
    autoplay = true;

    for(auto &p: stacks)
        std::sort(p.begin(), p.end());

    switch(p)
    {
        case 1:
            CalculateArbitraryPlay(value, 0, stacks);
            timer->start(300);
            break;
        case 2:
            CalculateArbitraryPlay(value, 2, stacks);
            timer->start(300);
            break;

    }



}
