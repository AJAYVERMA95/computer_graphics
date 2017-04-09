
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const float DEG2RAD = 3.14/180;

void drawTextHelvetica_18(float x,float y,float r,float g,float b,char const *text){
  int len = strlen(text);
  glColor3f(r,g,b);
  glRasterPos2f(x,y);
  for(int i=0;i<len;i++){
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
  }
}

void drawTextHelvetica_10(float x,float y,float r,float g,float b,char const *text){
  int len = strlen(text);
  glColor3f(r,g,b);
  glRasterPos2f(x,y);
  for(int i=0;i<len;i++){
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,text[i]);
  }
}

void drawRectangle(GLfloat bottomLeft_x,GLfloat bottomLeft_y,GLfloat length,GLfloat breadth){
  glBegin(GL_QUADS);
    glVertex2f(bottomLeft_x,bottomLeft_y);
    glVertex2f(bottomLeft_x,bottomLeft_y + breadth);
    glVertex2f(bottomLeft_x + length,bottomLeft_y + breadth);
    glVertex2f(bottomLeft_x + length,bottomLeft_y);
  glEnd();
  glFlush();
}

void drawTriangle() {
  glBegin(GL_TRIANGLES);
    glVertex2f(600+50,100+50+75);
    glVertex2f(600+50+125,100+50+150);
    glVertex2f(600+50+125,100+50);
  glEnd();
  glFlush();
}

void drawCurve() {
  GLfloat ctrlpoints[4][3] = {
    { 600, 200, 0.0}, { 0, 200, 0.0},{100, 400, 0.0},{600, 400, 0.0} };
  glLineWidth(3.0);
  glShadeModel(GL_FLAT);
  glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints[0][0]);
  glEnable(GL_MAP1_VERTEX_3);
  int i;
  glBegin(GL_LINE_STRIP);
    for (i = 0; i <= 30; i++)
      glEvalCoord1f((GLfloat) i/30.0);
  glEnd();
  glFlush();
}

void drawEllipse(float origin_x,float origin_y,float a,float b){
  float x,y;
  glColor3f(1, 0.271, 0);
  glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
      float rad = i*DEG2RAD;
      glVertex2f(cos(rad)* a + origin_x, sin(rad)* b + origin_y);
    }
  glEnd();
}

void drawDashedLine(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2) {
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1,0xAAAA);
  glLineWidth(1.0);
  glColor3f(0.0,0.0,0.0);
  glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
  glEnd();
  glDisable(GL_LINE_STIPPLE);
  glFlush();
}

void drawSlide()
{
  glClearColor(0.0, 0.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  drawEllipse(100,600,100,200);
  drawTextHelvetica_18(50,600,0,0,0,"CANNULA");

  glColor3f(1.0, 1.0, 1.0);
  drawRectangle(600,100,800,600); //big rectangle

  glColor3f(1.0,0.0,1.0);
  drawRectangle(600+50,100+50,400,150); //pink rectangle
  drawTextHelvetica_18(800,270,0,0,0,"INSULIN RESERVOIR");
  glColor3f(0.0,0.0,0.804);
  drawRectangle(600+50,100+50+150+50,400,125); //dark blue rectangle
  drawTextHelvetica_18(750,400,0,0,0,"DISPLAY SCREEN");
  glColor3f(0.118,0.565,1.0);
  drawRectangle(600+50+40,100+50+150+50+125+75,360,100); //dodger blue rectangle
  drawRectangle(600+50,100+50+150+50+125+75+33.33,40,33.333);
  drawTextHelvetica_18(800,580,0,0,0,"BATTERY");
  glColor3f(0.0,1.0,0.0);
  drawRectangle(600+50+400+60,100+50+150+50,200,300); //green rectangle
  drawTextHelvetica_18(1130,500,0,0,0,"CIRCUIT BOARD");
  glColor3f(1.0,0.0,0.0);
  drawRectangle(600+50+400+60+120,100+50,70,250); //red rectangle
  drawTextHelvetica_10(1245,290,0,0,0,"MICRO-");
  drawTextHelvetica_10(1235,270,0,0,0,"PROCESSOR");
  glColor3f(0.0,1.0,0.0);
  drawTriangle();
  glColor3f(0.541,0.169,0.886);
  drawRectangle(600+50+400+60+50,100+50+20,70,105); //purple rectangle
  drawTextHelvetica_10(1170,250,0,0,0,"MOTOR");
  drawDashedLine(600+50+240,100+50,600+50+240,100+50+150);
  drawDashedLine(600+50+250+10,100+50,600+50+250+10,100+50+150);
  drawDashedLine(600+50+250+10,100+50+60,600+50+400+60+120,100+50+60);
  drawDashedLine(600+50+250+10,100+50+60+25,600+50+400+60+120,100+50+60+25);
  drawCurve();
}

void init() {
  // glMatrixMode(GL_PROJECTION);        //Switch to setting the camera perspective
  // glLoadIdentity(); //Reset the camera with default perspective
  gluOrtho2D(0.0,1500,0.0,1000);
}

int main(int argc, char *argv[]) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1280,800);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Insulin Meter");
  init();
  glutDisplayFunc(drawSlide);
  glutMainLoop();

  return 0;
}
