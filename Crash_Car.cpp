#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
#include "cars.h"
#include "power_up.h"
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


void InitGraphics(int argc, char* argv[]);
void SetTransformations();
void Display();
float tile1_movement = -140;
float tile2_movement = -40;
float tile3_movement = 80;
float speed_move = 3.8;
float speed_tiles = 2;
//float car1_movment = 300;
//float car2_movment = 700;
//float car3_movment = 600;
int score = 0;
int t = 0;
float intpart;
float scoref = 0;
boolean crashed = false;
boolean power_up_nottaken = true;
int power_up_time = 0;
boolean start=true;
char identity;
cars car_m(0, -195, 0.7, 0, 0, 'm');
cars car_o(0, 300, 1, 0.5, 0, 'o');
cars car_o1(40, 700, 1, 0, 1, 'o');
cars car_o2(-40, 600, 0.36, 0.25, 0.14, 'o');
power_up invincible(0, 400);
//power_up invincible= new invincible();

int main(int argc, char* argv[]) {
    InitGraphics(argc, argv);
    srand(time(NULL));
    return 0;
}

void timer(int value)
{
    const int desiredFPS = 125;
    glutTimerFunc(1000 / desiredFPS, timer, ++value);
    glutPostRedisplay();
}
void restart() {
    car_m.x = 0;
    car_m.y = -195;
    car_o.x = 0;
    car_o.y = 300 ;
    car_o1.x = 40;
    car_o1.y = 700;
    car_o2.x = -40;
    car_o2.y = 600;
    speed_tiles = 2;
    car_o.speed = 2.3;
    car_o1.speed = 2.3;
    car_o2.speed = 2.3;
    invincible.speed = 1;
    invincible.y = 400;
    score = 0;
    crashed = false;

    glutDisplayFunc(Display);

}

void OnKeyPress(unsigned char key, int x, int y) {
    switch (key) {
    case 'a'://		a key
    case 'A':
        if (!crashed) {
            if (car_m.x - speed_move > -55) {
                car_m.x -= speed_move;

                break;
            }

        }
        break;
    case 'd'://		d key
    case 'D':
        if (!crashed) {
            if (car_m.x + speed_move < 55) {
                car_m.x += speed_move;
                break;
            }
        }
        break;

    case 'w'://		d key
    case 'W':
        if (!crashed) {
            if (car_m.y + speed_move < 200) {
                car_m.y += speed_move;

                break;
            }

        }
        break;
    case 's':
    case 'S':
        if (!crashed) {
            if (car_m.y - speed_move > -195) {
                car_m.y -= speed_move;

                break;
            }
        }
        break;

    case 'r':
    case 'R':
        if (crashed) {
            restart();
        }
    }
   


}




void power_up_check() {
    if ((abs(car_m.x - invincible.x) < 60) & (abs(car_m.y - invincible.y) < 70)) {
        invincible.draw = false;
        power_up_nottaken = false;
        invincible.y = 400;
        power_up_time = score + 10;
        //cout << power_up_time << endl;

    }
    else if (score >= power_up_time) {
        //cout << power_up_time << endl;
        power_up_nottaken = true;
    }



}

void InitGraphics(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GL_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1020, 720);
    glutCreateWindow("Bouncing car");
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(Display);
    glutKeyboardFunc(OnKeyPress);
    SetTransformations();
    glutMainLoop();

}

void SetTransformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}


void Drawscore(int score, float x, float y, float z)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    string s = "score : " + to_string(score);


    for (int i = 0; i < s.length(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.at(i));
    }

}

void crash_check() {

    if (((abs(car_m.x - car_o.x) < 25) & (abs(car_o.y + 100) < 15) | //  main car 
        (abs(car_m.x - car_o1.x) < 25) & (abs(car_o1.y + 100) < 15) |
        (abs(car_m.x - car_o2.x) < 25) & (abs(car_o2.y + 100) < 15))) {// car 2



        speed_tiles = 0;
        car_o.speed = 0;
        car_o1.speed = 0;
        car_o2.speed = 0;
        invincible.speed = 0;
        crashed = true;
        if (crashed) {
            glColor3f(0.6, 0, 0);
            glRasterPos3f(-25, 0, 0);

            string s = "GAME OVER";


            for (int i = 0; i < s.length(); i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.at(i));
            }
        }
    }

}


void draw_street() {
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.1, 0.60);
    glVertex2i(-75, 200);
    glVertex2i(75, 200);
    glVertex2i(75, -200);
    glVertex2i(-75, -200);
    glEnd();
}

void draw_tiles() {
    glPushMatrix();
    glTranslatef(0, tile1_movement, 0);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2i(-25, -200);
    glVertex2i(-30, -200);
    glVertex2i(-30, -120);
    glVertex2i(-25, -120);

    glVertex2i(25, -200);
    glVertex2i(30, -200);
    glVertex2i(30, -120);
    glVertex2i(25, -120);
    glEnd();

    tile1_movement -= speed_tiles;
    if (tile1_movement <= -280) {
        glLoadIdentity();
        tile1_movement = 400;
        glTranslatef(0, tile1_movement, 0);
    }
    glPopMatrix();
    // --------------------------------------------------------------
    //first row tile 2
    //--------------------------------------------------------------
    glPushMatrix();
    glTranslatef(0, tile2_movement, 0);
    glBegin(GL_QUADS);

    glColor3f(1, 1, 1);//cyan
    glVertex2i(-25, -100);
    glVertex2i(-30, -100);
    glVertex2i(-30, -20);
    glVertex2i(-25, -20);

    glVertex2i(25, -100);
    glVertex2i(30, -100);
    glVertex2i(30, -20);
    glVertex2i(25, -20);

    glEnd();
    tile2_movement -= speed_tiles;
    if (tile2_movement <= -280) {
        glLoadIdentity();
        tile2_movement = 400;
        glTranslatef(0, tile2_movement, 0);
    }
    glPopMatrix();
    // --------------------------------------------------------------
    //first row tile 3
    //--------------------------------------------------------------
    glPushMatrix();
    glTranslatef(0, tile3_movement, 0);
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);//cyan
    glVertex2i(-25, 0);
    glVertex2i(-30, 0);
    glVertex2i(-30, 80);
    glVertex2i(-25, 80);

    glVertex2i(25, 0);
    glVertex2i(30, 0);
    glVertex2i(30, 80);
    glVertex2i(25, 80);
    glEnd();
    tile3_movement -= speed_tiles;
    if (tile3_movement <= -280) {
        glLoadIdentity();
        tile3_movement = 400;
        glTranslatef(0, tile3_movement, 0);
    }

    glPopMatrix();
}


void Display() {

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    draw_street();
    draw_tiles();
    car_m.draw_car_m();
    car_o.draw_car_o();
    car_o1.draw_car_o();
    car_o2.draw_car_o();

    glPushMatrix();
    Drawscore(score, 150, -190, 0);
    if (!crashed) {
        scoref += 0.01;
        if (modf(scoref, &intpart) < 0.01)
        {
            score += 1;
        }

    }
    invincible.draw_power_up_invincible(score);
    power_up_check();
    if (power_up_nottaken) {
        crash_check();
    }



   
    glFinish();
    glutSwapBuffers();
}




