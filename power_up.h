#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
#include"cars.h"
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
class power_up
{
public:

	int x = 0, y = 400, z = 1;
	boolean draw = false;
	float speed = 1;
	power_up(int x, int y) {
		this->x = x;
		this->y = y;


	}

	void struct_power_up_invincible() {

		if (draw) {
			glPushMatrix();
			glTranslatef(x, y, 0);
			glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);
			glVertex2f(0, 5);
			glVertex2f(10, -1);
			glVertex2f(7, -15);
			glColor3f(0, 1, 0);
			glVertex2f(0, -23);
			glVertex2f(-7, -15);
			glColor3f(0, 0, 1);
			glVertex2f(-10, -1);
			glVertex2f(0, 5);
			glEnd();
			y -= speed;

			if (y < -290)
			{
				draw = false;
				y = 400;

			}
			if (z == 1) {
				if (rand() % 2 == 0)
				{
					x = -50;
				}
				else if (rand() % 3 == 0)
				{
					x = 0;
				}
				else
				{
					x = 50;
				}
				glTranslatef(x, y, 0);
				z = 0;
			}
			glPopMatrix();

		}



	};

	void draw_power_up_invincible(int score) {
		if (score != 0) {
		if (score % 20 == 0 | draw) {
			draw = true;
			struct_power_up_invincible();
			if (!draw) {
				z = 1;
			}

		}
	}

	}
	void struct_power_up_double_score() {

		if (draw) {
			glPushMatrix();
			glTranslatef(x, y, 0);
			glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);
			glVertex2f(0, 5);
			glVertex2f(10, -1);
			glVertex2f(7, -15);
			glColor3f(0, 1, 0);
			glVertex2f(0, -23);
			glVertex2f(-7, -15);
			glColor3f(0, 0, 1);
			glVertex2f(-10, -1);
			glVertex2f(0, 5);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex2f(0, 5);
			glVertex2f(10, -1);
			glVertex2f(7, -15);
			glVertex2f(0, -23);
			glVertex2f(-7, -15);
			glVertex2f(-10, -1);
			glVertex2f(0, 5);
			glEnd();
			y -= 1;

			if (y < -290)
			{
				draw = false;
				y = 400;

			}
			if (z == 1) {
				if (rand() % 2 == 0)
				{
					x = -50;
				}
				else if (rand() % 3 == 0)
				{
					x = 0;
				}
				else
				{
					x = 50;
				}
				glTranslatef(x, y, 0);
				z = 0;
			}
			glPopMatrix();

		}



	};
};


