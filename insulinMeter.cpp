#include "GL/freeglut.h"
#include "GL/gl.h"
void aRectangle(GLfloat bottomLeft_x,GLfloat bottomLeft_y,GLfloat length,GLfloat breadth){
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

void showCurve() {
  GLfloat ctrlpoints[4][3] = {
    { 600, 200, 0.0}, { 0, 200, 0.0},{100, 600, 0.0},{600, 600, 0.0} };
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

void drawRectangle()
{
  glClearColor(0.0, 0.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 1.0, 1.0);
  aRectangle(600,100,800,600); //big rectangle

  glColor3f(1.0,0.0,1.0);
  aRectangle(600+50,100+50,400,150); //pink rectangle
  glColor3f(0.0,0.0,0.804);
  aRectangle(600+50,100+50+150+50,400,125); //dark blue rectangle
  glColor3f(0.118,0.565,1.0);
  aRectangle(600+50+40,100+50+150+50+125+75,360,100); //dodger blue rectangle
  aRectangle(600+50,100+50+150+50+125+75+33.33,40,33.333);
  glColor3f(0.0,1.0,0.0);
  aRectangle(600+50+400+60,100+50+150+50,200,300); //green rectangle
  glColor3f(1.0,0.0,0.0);
  aRectangle(600+50+400+60+120,100+50,70,250); //red rectangle
  glColor3f(0.0,1.0,0.0);
  drawTriangle();
  glColor3f(0.541,0.169,0.886);
  aRectangle(600+50+400+60+50,100+50+20,70,105);
  drawDashedLine(600+50+240,100+50,600+50+240,100+50+150);
  drawDashedLine(600+50+250+10,100+50,600+50+250+10,100+50+150);
  drawDashedLine(600+50+250+10,100+50+60,600+50+400+60+120,100+50+60);
  drawDashedLine(600+50+250+10,100+50+60+25,600+50+400+60+120,100+50+60+25);
  showCurve();
}

void init() {
  // glMatrixMode(GL_PROJECTION);        //Switch to setting the camera perspective
  // glLoadIdentity(); //Reset the camera with default perspective
  gluOrtho2D(0.0,1500,0.0,1000);
}

int main(int argc, char *argv[]) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1000,1000);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Insulin Meter");
  init();
  glutDisplayFunc(drawRectangle);
  glutMainLoop();

  return 0;
}
