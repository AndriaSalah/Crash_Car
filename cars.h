#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>

using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
class cars
{
public:
    float x;
    float y;
    float r;
    float g;
    float b;
    boolean selected = false;
    float speed = 4.5;
    int counter = rand() % 301 - 300;

    cars(float x, float y, float r, float g, float b) {
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = g;
        this->b = b;
        
        srand(time(NULL)); 
    }
    void draw_car_mohab() {
        glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(0.38, 0.55, 0);
        glRotatef(90, 0, 0, 1);

        // the wheels 
        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(35, 41);
        glVertex2i(15, 41);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(-40, 41);
        glVertex2i(-20, 41);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(35, -41);
        glVertex2i(15, -41);
        glEnd();

        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(-40, -41);
        glVertex2i(-20, -41);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(r, g, b);
        glVertex2i(-60, 40);
        glVertex2i(60, 40);
        glVertex2i(60, -40);
        glVertex2i(-60, -40);
        glEnd();

        // yallow rect
        glBegin(GL_POLYGON);

        glColor3f(1, 1, 0);
        glVertex2i(50, 40);
        glVertex2i(50, 30);
        glVertex2i(60, 30);
        glVertex2i(60, 40);
        glEnd();

        // another yallow rect
        glBegin(GL_POLYGON);

        glColor3f(1, 1, 0);
        glVertex2i(50, -40);
        glVertex2i(50, -30);
        glVertex2i(60, -30);
        glVertex2i(60, -40);
        glEnd();

        // the mid
        glBegin(GL_POLYGON);
        glVertex2i(55, 30);
        glColor3f(0, 1, 1);
        glVertex2i(55, -30);
        glVertex2i(60, -30);
        glColor3f(1, 0, 1);
        glVertex2i(60, 30);
        glEnd();

        // outline  rect
        glLineWidth(2);
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(50, 40);
        glVertex2i(50, 30);
        glVertex2i(60, 30);
        glEnd();
        // outline another rect
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(50, -40);
        glVertex2i(50, -30);
        glVertex2i(60, -30);
        glEnd();

        // outline mid
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(55, 30);
        glVertex2i(55, -30);
        glEnd();


        // back mid 
        glBegin(GL_POLYGON);
        glColor3f(0, 1, 1);
        glVertex2i(-55, 40);
        glVertex2i(-55, -40);
        glColor3f(1, 0, 1);
        glVertex2i(-60, -40);
        glVertex2i(-60, 40);
        glEnd();

        // mirrors
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2i(-5, 40);
        glVertex2i(-5, 45);
        glVertex2i(-1, 46);
        glVertex2i(2, 40);
        glEnd();

        glLineWidth(2);
        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-5, 40);
        glVertex2i(-5, 45);
        glVertex2i(-1, 46);
        glVertex2i(2, 40);
        glEnd();

        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2i(-5, -40);
        glVertex2i(-5, -45);
        glVertex2i(-1, -46);
        glVertex2i(2, -40);
        glEnd();


        glLineWidth(2);
        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-5, -40);
        glVertex2i(-5, -45);
        glVertex2i(-1, -46);
        glVertex2i(2, -40);
        glEnd();

        glColor3f(0, 0, 0);
        glLineWidth(2);
        glBegin(GL_LINE_STRIP);
        glVertex2i(46, 30);
        glVertex2i(20, 25);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(46, -30);
        glVertex2i(20, -25);
        glEnd();

        glColor3f(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2i(0, 20);
        glVertex2i(0, -20);
        glVertex2i(16, -27);
        glVertex2i(16, 27);
        glEnd();


        glLineWidth(2);
        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(0, 20);
        glVertex2i(0, -20);
        glVertex2i(16, -27);
        glVertex2i(16, 27);
        glVertex2i(0, 20);
        glEnd();


        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-2, 20);
        glVertex2i(-20, 20);
        glVertex2i(-20, -20);
        glVertex2i(-2, -20);
        glEnd();

        glColor3f(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2i(-2, 21);
        glVertex2i(-20, 21);
        glVertex2i(-23, 30);
        glVertex2i(3, 30);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-2, 21);
        glVertex2i(-20, 21);
        glVertex2i(-23, 30);
        glVertex2i(3, 30);
        glVertex2i(-2, 21);
        glEnd();

        glColor3f(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2i(-2, -21);
        glVertex2i(-20, -21);
        glVertex2i(-23, -30);
        glVertex2i(3, -30);
        glEnd();


        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-2, -21);
        glVertex2i(-20, -21);
        glVertex2i(-23, -30);
        glVertex2i(3, -30);
        glVertex2i(-2, -21);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-21, 20);
        glVertex2i(-26, 36);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-21, -20);
        glVertex2i(-26, -36);
        glEnd();

        glColor3f(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex2i(-21, 20);
        glVertex2i(-33, 20);
        glVertex2i(-33, -20);
        glVertex2i(-21, -20);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-21, 20);
        glVertex2i(-33, 20);
        glVertex2i(-33, -20);
        glVertex2i(-21, -20);
        glVertex2i(-21, 20);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-34, 20);
        glVertex2i(-50, 34);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(-34, -20);
        glVertex2i(-50, -34);
        glEnd();

        // outline
        glLineWidth(3);
        glBegin(GL_LINE_LOOP);

        glColor3f(0, 0, 0);
        glVertex2i(-60, 40);
        glVertex2i(60, 40);
        glVertex2i(60, -40);
        glVertex2i(-60, -40);
        glEnd();
        glPopMatrix();
    }

    void draw_car_badr() {

        glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(1.8, 2.2, 0);
        glRotatef(-90, 0, 0, 1);
        glBegin(GL_POLYGON);
        // upper left tier
        glColor3f(0, 0, 0);
        glVertex2i(-12, 9);
        glVertex2i(-8, 9);
        glVertex2i(-8, 10);
        glVertex2i(-12, 10);

        glEnd();
        glBegin(GL_POLYGON);
        //lower left tier
        glColor3f(0, 0, 0);
        glVertex2i(-8, -9.5);
        glVertex2i(-8, -8.5);
        glVertex2i(-12, -8);
        glVertex2i(-12, -9);
        glVertex2i(-8, -9.5);
        glEnd();
        glBegin(GL_POLYGON);
        // upper right tier
        glColor3f(0, 0, 0);
        glVertex2i(4, 10);
        glVertex2i(8, 10);
        glVertex2i(8, 9);
        glVertex2i(4, 9);
        glVertex2i(4, 10);
        glEnd();
        glBegin(GL_POLYGON);
        //lower right tier
        glColor3f(0, 0, 0);
        glVertex2i(4, -8);
        glVertex2i(8, -8);
        glVertex2i(8, -9);
        glVertex2i(4, -9);
        glVertex2i(4, -8);
        glEnd();

        glPointSize(1);
        glBegin(GL_POLYGON);
        //body
        glColor3f(0.80, 0.10, 0.10);
        glVertex2i(-18, 0);
        //lower left
        glVertex2i(-17.5, -5);
        glVertex2i(-16.5, -7);
        glVertex2i(-15.5, -8);
        glVertex2i(-15, -8.2);
        glVertex2i(0, -9);
        //lower right
        glVertex2i(11, -8.5);
        glVertex2i(11.5, -8);
        glVertex2i(12.5, -7);
        glVertex2i(13.5, -5);
        glVertex2i(14.5, 0);
        //uper right
        glVertex2i(13.5, 5.5);
        glVertex2i(12.5, 7.5);
        glVertex2i(11.5, 8);
        glVertex2i(10.5, 9);
        glVertex2i(0, 10);
        //upper left
        glVertex2i(-15, 9.2);
        glVertex2i(-15.5, 9);
        glVertex2i(-16.5, 8);
        glVertex2i(-17.5, 6);
        glVertex2i(-17.5, 5.6);
        glVertex2i(-18, 0);
        glEnd();

        glBegin(GL_POLYGON);
        //Right mirror
        glColor3f(0, 0, 0);
        glVertex2i(-4, 9);
        glVertex2i(-2, 9);
        glVertex2i(-2, 12);
        glVertex2i(-3, 12);
        glVertex2i(-4, 9);
        glEnd();

        glBegin(GL_POLYGON);
        //shape
        glColor3f(0, 0, 0);
        glVertex2i(-17, 3);
        glVertex2i(13, 3);
        glVertex2i(14, 0);
        glVertex2i(13, -3);
        glVertex2i(-17, -3);
        glVertex2i(-18, 0);

        glEnd();

        glBegin(GL_POLYGON);
        //left mirror
        glColor3f(0, 0, 0);
        glVertex2i(-4, -8);
        glVertex2i(-2, -8);
        glVertex2i(-2, -11);
        glVertex2i(-3, -11);
        glVertex2i(-4, -8);
        glEnd();

        glBegin(GL_POLYGON);
        //right light
        glColor3f(1, 1, 0);
        glVertex2i(-16.5, 5.5);
        glVertex2i(-16.5, 6.5);
        glVertex2i(-15.5, 8);
        glVertex2i(-14.5, 8);
        glVertex2i(-14.5, 5.5);
        glEnd();

        glBegin(GL_POLYGON);
        //left light
        glColor3f(1, 1, 0);
        glVertex2i(-16.5, -4.5);
        glVertex2i(-16.5, -5.5);
        glVertex2i(-15.5, -7);
        glVertex2i(-14.5, -7);
        glVertex2i(-14.5, -4.5);
        glEnd();

        glBegin(GL_POLYGON);
        //back glass
        glColor3f(0.40, 0.80, 0.80);
        glVertex2i(5, 6);
        glVertex2i(8, 6);
        glVertex2i(8, -5);
        glVertex2i(5, -5);
        glEnd();

        glBegin(GL_POLYGON);
        //side glass
        glColor3f(0.40, 0.80, 0.80);
        glVertex2i(-2, 6);
        glVertex2i(-3, 8);
        glVertex2i(7, 8);
        glVertex2i(5, 6);
        glEnd();
        glBegin(GL_POLYGON);
        //side glass
        glColor3f(0.40, 0.80, 0.80);
        glVertex2i(-2, -5);
        glVertex2i(-3, -7);
        glVertex2i(7, -7);
        glVertex2i(5, -5);
        glEnd();

        glBegin(GL_POLYGON);
        //front glass
        glColor3f(0.40, 0.80, 0.80);
        glVertex2i(-2, 6);
        glVertex2i(-4, 7);
        glVertex2i(-5, 6);
        glVertex2i(-6, 3);
        glVertex2i(-6, -2);
        glVertex2i(-5, -5);
        glVertex2i(-4, -6);
        glVertex2i(-2, -5);


        glEnd();
        //back light
        glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex2i(11.5, -7);
        glVertex2i(12.5, -7);
        glVertex2i(12.5, -5);
        glVertex2i(11.5, -5);

        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.10, 0.10, 0.10);
        glVertex2i(-1, 5);
        glVertex2i(2, 5);
        glVertex2i(2, -4);
        glVertex2i(-1, -4);


        glEnd();



        glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex2i(11.5, 7);
        glVertex2i(12.5, 7);
        glVertex2i(12.5, 5);
        glVertex2i(11.5, 5);


        glEnd();

        
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);

        glVertex2i(-1, 5);
        glVertex2i(2, 5);
        glVertex2i(2, 5);

        glVertex2i(2, -4);
        glVertex2i(2, -4);

        glVertex2i(-1, -4);
        glVertex2i(-1, -4);
        glVertex2i(-1, 5);




        glVertex2i(9, 1);
        glVertex2i(9, -1);


        glVertex2i(11, 5);
        glVertex2i(12, 3);
        glVertex2i(12, 3);
        glVertex2i(12, 0);
        glVertex2i(12, 0);
        glVertex2i(12, -3);
        glVertex2i(12, -3);
        glVertex2i(11, -5);




        glVertex2i(11.5, 7);
        glVertex2i(12.5, 7);
        glVertex2i(12.5, 7);

        glVertex2i(12.5, 5);
        glVertex2i(12.5, 5);

        glVertex2i(11.5, 5);

        glVertex2i(11.5, -7);
        glVertex2i(12.5, -7);
        glVertex2i(12.5, -7);

        glVertex2i(12.5, -5);
        glVertex2i(12.5, -5);

        glVertex2i(11.5, -5);

        glVertex2i(8, 6);
        glVertex2i(10, 8);
        glVertex2i(8, -5);
        glVertex2i(10, -7);



        glVertex2i(-15, 1);
        glVertex2i(-14, 0);
        glVertex2i(-14, 0);
        glVertex2i(-15, -1);
        glVertex2i(-16, 1);
        glVertex2i(-15.5, 0);
        glVertex2i(-15.5, 0);
        glVertex2i(-16, -1);



        glVertex2i(5, -5);
        glVertex2i(8, -5);

        glVertex2i(5, 6);
        glVertex2i(8, 6);

        glVertex2i(-2, 6);
        glVertex2i(-4, 7);
        glVertex2i(-4, 7);
        glVertex2i(-5, 6);
        glVertex2i(-5, 6);
        glVertex2i(-6, 3);
        glVertex2i(-6, 3);
        glVertex2i(-6, -2);
        glVertex2i(-6, -2);
        glVertex2i(-5, -5);
        glVertex2i(-5, -5);
        glVertex2i(-4, -6);
        glVertex2i(-4, -6);
        glVertex2i(-2, -5);


        glVertex2i(-3, -7);
        glVertex2i(7, -7);

        glVertex2i(8, -5);
        glVertex2i(8, 6);


        glVertex2i(7, 8);
        glVertex2i(-3, 8);



        glVertex2i(-2, 6);
        glVertex2i(-3, 8);
        glVertex2i(-2, -5);
        glVertex2i(-3, -7);

        glVertex2i(5, 6);
        glVertex2i(7, 8);
        glVertex2i(5, -5);
        glVertex2i(7, -7);

        glVertex2i(-2, 6);
        glVertex2i(5, 6);
        glVertex2i(-2, -5);
        glVertex2i(5, -5);
        glVertex2i(-2, 6);
        glVertex2i(-2, -5);
        glVertex2i(5, 6);
        glVertex2i(5, -5);

        glVertex2i(-14.5, 5.5);
        glVertex2i(-14.5, 8);


        glVertex2i(-14.5, -4.5);
        glVertex2i(-14.5, -7);

        glVertex2i(-16.5, 5.5);
        glVertex2i(-14.5, 5.5);

        glVertex2i(-16.5, -4.5);
        glVertex2i(-14.5, -4.5);

        glVertex2i(-13, 7);
        glVertex2i(-6, 6);
        glVertex2i(-13, -6);
        glVertex2i(-6, -5);

        glVertex2i(-16.5, -4.5);
        glVertex2i(-16.5, -5.5);
        glVertex2i(-16.5, -5.5);
        glVertex2i(-15.5, -7);

        glVertex2i(-15.5, -7);
        glVertex2i(-13.5, -7);

        glVertex2i(-16.5, -4.5);
        glVertex2i(-17, 0);


        glVertex2i(-16.5, 5.5);
        glVertex2i(-16.5, 6.5);
        glVertex2i(-16.5, 6.5);
        glVertex2i(-15.5, 8);

        glVertex2i(-15.5, 8);
        glVertex2i(-13.5, 8);

        glVertex2i(-16.5, 5.5);
        glVertex2i(-17, 0);
        glEnd();
        glPopMatrix();
    
    }
    void draw_car_m() {

        glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(0.18, 0.5, 0);
        glRotatef(90, 0, 0, 1);


        glLineWidth(2);
        glBegin(GL_POLYGON);
        //main body quad
        glColor3f(r, g, b);
        glVertex2i(10, -85);
        glVertex2i(10, 85);
        glVertex2i(100, 85);
        glVertex2i(100, -85);



        glEnd();
        glBegin(GL_POLYGON);
        //front bumber
        glVertex2i(100, 85);
        glVertex2i(110, 75);
        glVertex2i(115, 65);
        glVertex2i(118, 55);
        glVertex2i(120, 0);
        glVertex2i(118, -55);
        glVertex2i(115, -65);
        glVertex2i(110, -75);
        glVertex2i(100, -85);

        glEnd();

        glBegin(GL_LINE_STRIP);
        //fornt bumper lining
        glColor3f(0, 0, 0);
        glVertex2i(90, 75);
        glVertex2i(95, 70);
        glVertex2i(105, 50);
        glVertex2i(107, 0);
        glVertex2i(105, -50);
        glVertex2i(95, -70);
        glVertex2i(90, -75);

        glEnd();
        //rear bumper
        glBegin(GL_POLYGON);
        glColor3f(r, g, b);
        glVertex2i(10, 85);
        glVertex2i(8, 75);
        glVertex2i(3, 65);
        glVertex2i(1, 55);
        glVertex2i(-1, 0);
        glVertex2i(1, -55);
        glVertex2i(3, -65);
        glVertex2i(8, -80);
        glVertex2i(10, -85);

        glEnd();
        //rear bumper lining
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(14, 80);
        glVertex2i(12, 75);
        glVertex2i(7, 65);
        glVertex2i(5, 55);
        glVertex2i(3, 0);
        glVertex2i(5, -55);
        glVertex2i(7, -65);
        glVertex2i(12, -75);
        glVertex2i(14, -80);
        glEnd();


        //roof of the car
        glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2i(35, 40);
        glVertex2i(55, 40);
        glVertex2i(55, -40);
        glVertex2i(35, -40);

        //rear window of the car
        glColor3f(0, 0.5, 0.5);
        glVertex2i(35, 30);
        glVertex2i(25, 30);
        glVertex2i(25, -30);
        glVertex2i(35, -30);

        //tires of the car
        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(20, 85);
        glVertex2i(20, 90);
        glVertex2i(40, 90);
        glVertex2i(40, 85);

        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(20, -85);
        glVertex2i(20, -90);
        glVertex2i(40, -90);
        glVertex2i(40, -85);

        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(80, 85);
        glVertex2i(80, 90);
        glVertex2i(100, 90);
        glVertex2i(100, 85);

        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(80, -85);
        glVertex2i(80, -90);
        glVertex2i(100, -90);
        glVertex2i(100, -85);

        glEnd();

        glBegin(GL_LINE_LOOP);
        // rear window lining
        glColor3f(0, 0, 0);
        glVertex2i(35, 30);
        glVertex2i(25, 30);
        glVertex2i(25, -30);
        glVertex2i(35, -30);
        glEnd();

        glBegin(GL_LINE_LOOP);
        //roof lining
        glColor3f(0, 0, 0);
        glVertex2i(35, 40);
        glVertex2i(55, 40);
        glVertex2i(55, -40);
        glVertex2i(35, -40);

        glEnd();

        glBegin(GL_POLYGON);
        //side window 1
        glColor3f(0, 0.5, 0.5);
        glVertex2i(40, 40);
        glVertex2i(35, 65);
        glVertex2i(60, 65);
        glVertex2i(50, 40);

        glEnd();

        glBegin(GL_LINE_LOOP);
        //side window 1
        glColor3f(0, 0, 0);
        glVertex2i(40, 40);
        glVertex2i(35, 65);
        glVertex2i(60, 65);
        glVertex2i(50, 40);

        glEnd();

        glBegin(GL_POLYGON);
        //side window 2
        glColor3f(0, 0.5, 0.5);
        glVertex2i(40, -40);
        glVertex2i(35, -65);
        glVertex2i(60, -65);
        glVertex2i(50, -40);

        glEnd();

        glBegin(GL_LINE_LOOP);
        //side window 2 lining
        glColor3f(0, 0, 0);
        glVertex2i(40, -40);
        glVertex2i(35, -65);
        glVertex2i(60, -65);
        glVertex2i(50, -40);

        glEnd();

        glBegin(GL_POLYGON);
        //front window
        glColor3f(0, 0.5, 0.5);
        glVertex2i(55, 40);
        glVertex2i(70, 55);
        glVertex2i(74, 35);
        glVertex2i(77, 20);

        glVertex2i(79, 0);

        glVertex2i(77, -20);
        glVertex2i(74, -35);
        glVertex2i(70, -55);
        glVertex2i(55, -40);

        glEnd();

        glBegin(GL_LINE_LOOP);
        //front window lining
        glColor3f(0, 0, 0);
        glVertex2i(55, 40);
        glVertex2i(70, 55);
        glVertex2i(74, 35);
        glVertex2i(77, 20);
        glVertex2i(79, 0);
        glVertex2i(77, -20);
        glVertex2i(74, -35);
        glVertex2i(70, -55);
        glVertex2i(55, -40);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1, 1, 0);
        glVertex2i(96, 70);
        glVertex2i(102, 75);
        glVertex2i(106, 70);
        glVertex2i(106, 55);
        glVertex2i(106, 50);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1, 1, 0);
        glVertex2i(96, -70);
        glVertex2i(102, -75);
        glVertex2i(106, -70);
        glVertex2i(106, -55);
        glVertex2i(106, -50);

        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2i(96, 70);
        glVertex2i(102, 75);
        glVertex2i(106, 70);
        glVertex2i(106, 55);
        glVertex2i(106, 50);

        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2i(96, -70);
        glVertex2i(102, -75);
        glVertex2i(106, -70);
        glVertex2i(106, -55);
        glVertex2i(106, -50);

        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex2i(109, 5);
        glVertex2i(111, 0);
        glVertex2i(109, -5);

        glEnd();

        glBegin(GL_LINES);
        glVertex2i(77, 35);
        glVertex2i(95, 55);
        glVertex2i(77, -35);
        glVertex2i(95, -55);
        glVertex2i(22, 35);
        glVertex2i(12, 55);
        glVertex2i(22, -35);
        glVertex2i(12, -55);


        glEnd();
        glPopMatrix();
    }
    void draw_car_o() {

        glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(0.18, 0.5, 0);
        glRotatef(270, 0, 0, 1);


        glLineWidth(2);
        glBegin(GL_POLYGON);
        //main body quad
        glColor3f(r, g, b);
        glVertex2i(10, -85);
        glVertex2i(10, 85);
        glVertex2i(100, 85);
        glVertex2i(100, -85);



        glEnd();
        glBegin(GL_POLYGON);
        //front bumber
        glVertex2i(100, 85);
        glVertex2i(110, 75);
        glVertex2i(115, 65);
        glVertex2i(118, 55);
        glVertex2i(120, 0);
        glVertex2i(118, -55);
        glVertex2i(115, -65);
        glVertex2i(110, -75);
        glVertex2i(100, -85);

        glEnd();

        glBegin(GL_LINE_STRIP);
        //fornt bumper lining
        glColor3f(0, 0, 0);
        glVertex2i(90, 75);
        glVertex2i(95, 70);
        glVertex2i(105, 50);
        glVertex2i(107, 0);
        glVertex2i(105, -50);
        glVertex2i(95, -70);
        glVertex2i(90, -75);

        glEnd();
        //rear bumper
        glBegin(GL_POLYGON);
        glColor3f(r, g, b);
        glVertex2i(10, 85);
        glVertex2i(8, 75);
        glVertex2i(3, 65);
        glVertex2i(1, 55);
        glVertex2i(-1, 0);
        glVertex2i(1, -55);
        glVertex2i(3, -65);
        glVertex2i(8, -80);
        glVertex2i(10, -85);

        glEnd();
        //rear bumper lining
        glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2i(14, 80);
        glVertex2i(12, 75);
        glVertex2i(7, 65);
        glVertex2i(5, 55);
        glVertex2i(3, 0);
        glVertex2i(5, -55);
        glVertex2i(7, -65);
        glVertex2i(12, -75);
        glVertex2i(14, -80);
        glEnd();


        //roof of the car
        glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2i(35, 40);
        glVertex2i(55, 40);
        glVertex2i(55, -40);
        glVertex2i(35, -40);

        //rear window of the car
        glColor3f(0, 0.5, 0.5);
        glVertex2i(35, 30);
        glVertex2i(25, 30);
        glVertex2i(25, -30);
        glVertex2i(35, -30);

        //tires of the car
        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(20, 85);
        glVertex2i(20, 90);
        glVertex2i(40, 90);
        glVertex2i(40, 85);

        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(20, -85);
        glVertex2i(20, -90);
        glVertex2i(40, -90);
        glVertex2i(40, -85);

        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(80, 85);
        glVertex2i(80, 90);
        glVertex2i(100, 90);
        glVertex2i(100, 85);

        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(80, -85);
        glVertex2i(80, -90);
        glVertex2i(100, -90);
        glVertex2i(100, -85);

        glEnd();

        glBegin(GL_LINE_LOOP);
        // rear window lining
        glColor3f(0, 0, 0);
        glVertex2i(35, 30);
        glVertex2i(25, 30);
        glVertex2i(25, -30);
        glVertex2i(35, -30);
        glEnd();

        glBegin(GL_LINE_LOOP);
        //roof lining
        glColor3f(0, 0, 0);
        glVertex2i(35, 40);
        glVertex2i(55, 40);
        glVertex2i(55, -40);
        glVertex2i(35, -40);

        glEnd();

        glBegin(GL_POLYGON);
        //side window 1
        glColor3f(0, 0.5, 0.5);
        glVertex2i(40, 40);
        glVertex2i(35, 65);
        glVertex2i(60, 65);
        glVertex2i(50, 40);

        glEnd();

        glBegin(GL_LINE_LOOP);
        //side window 1
        glColor3f(0, 0, 0);
        glVertex2i(40, 40);
        glVertex2i(35, 65);
        glVertex2i(60, 65);
        glVertex2i(50, 40);

        glEnd();

        glBegin(GL_POLYGON);
        //side window 2
        glColor3f(0, 0.5, 0.5);
        glVertex2i(40, -40);
        glVertex2i(35, -65);
        glVertex2i(60, -65);
        glVertex2i(50, -40);

        glEnd();

        glBegin(GL_LINE_LOOP);
        //side window 2 lining
        glColor3f(0, 0, 0);
        glVertex2i(40, -40);
        glVertex2i(35, -65);
        glVertex2i(60, -65);
        glVertex2i(50, -40);

        glEnd();

        glBegin(GL_POLYGON);
        //front window
        glColor3f(0, 0.5, 0.5);
        glVertex2i(55, 40);
        glVertex2i(70, 55);
        glVertex2i(74, 35);
        glVertex2i(77, 20);

        glVertex2i(79, 0);

        glVertex2i(77, -20);
        glVertex2i(74, -35);
        glVertex2i(70, -55);
        glVertex2i(55, -40);

        glEnd();

        glBegin(GL_LINE_LOOP);
        //front window lining
        glColor3f(0, 0, 0);
        glVertex2i(55, 40);
        glVertex2i(70, 55);
        glVertex2i(74, 35);
        glVertex2i(77, 20);
        glVertex2i(79, 0);
        glVertex2i(77, -20);
        glVertex2i(74, -35);
        glVertex2i(70, -55);
        glVertex2i(55, -40);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1, 1, 0);
        glVertex2i(96, 70);
        glVertex2i(102, 75);
        glVertex2i(106, 70);
        glVertex2i(106, 55);
        glVertex2i(106, 50);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1, 1, 0);
        glVertex2i(96, -70);
        glVertex2i(102, -75);
        glVertex2i(106, -70);
        glVertex2i(106, -55);
        glVertex2i(106, -50);

        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2i(96, 70);
        glVertex2i(102, 75);
        glVertex2i(106, 70);
        glVertex2i(106, 55);
        glVertex2i(106, 50);

        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0, 0, 0);
        glVertex2i(96, -70);
        glVertex2i(102, -75);
        glVertex2i(106, -70);
        glVertex2i(106, -55);
        glVertex2i(106, -50);

        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex2i(109, 5);
        glVertex2i(111, 0);
        glVertex2i(109, -5);

        glEnd();

        glBegin(GL_LINES);
        glVertex2i(77, 35);
        glVertex2i(95, 55);
        glVertex2i(77, -35);
        glVertex2i(95, -55);
        glVertex2i(22, 35);
        glVertex2i(12, 55);
        glVertex2i(22, -35);
        glVertex2i(12, -55);


        glEnd();


        y -= speed;
        if (y < -290)
        {
            if (rand() % 2 == 0)
            {
                x = -53;
            }
            else if (rand() % 3 == 0)
            {
                x = 53;
            }
            else
            {
                x = 0;
            }
            y = 300;
            glTranslatef(x, y, 0);
        }



        glPopMatrix();
    }
};