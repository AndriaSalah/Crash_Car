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
    char identifier;
    float speed = 4.5;
    int counter = rand() % 301 - 300;

    cars(float x, float y, float r, float g, float b, char identifier) {
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = g;
        this->b = b;
        this->identifier = identifier;
        srand(time(NULL)); 
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