#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>

static float go = 0,tip=180,turn2=90;
static float rotateSteps=1;
static float speed=1;
static float scaleFactor=0.5;
float angle, move, scene, roadmove,turn, on=1;
int i, start;




void wall()
{
   glRectf(0, 0, 14, 10);
}

void init(GLvoid)

{
   glClearColor(0, 0.4, 0.8, 0);           //set the Background Color Blue
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);           // Enable Smooth Shading


}

void Sun()
{
   glColor4f(1, 1, 0, 1);
    glutSolidSphere(0.6,40,40);

}


void Grass(){

   glPushMatrix();
   glTranslatef(5,1,0);
   glColor3f(0.1, 0.5 , 0.1);
   glutSolidCone(1.5,2, 10, 2);

   glPopMatrix();


   glPushMatrix();
    glTranslatef(2,3,0);
   glColor3f(0.1, 0.5 , 0.1);
   glutSolidCone(1.5,2, 10, 2);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(1,0,0);
   glColor3f(0.1, 0.5 , 0.1);
   glutSolidCone(1.5,2, 10, 2);
   glPopMatrix();

   glEnd();
}

void Grass2(){

   glPushMatrix();
   glTranslatef(-5,1,0);
    glColor3f(0.1, 0.5 , 0.1);
   glutSolidCone(1.5,2, 10, 2);
   glPopMatrix();


   glPushMatrix();
    glTranslatef(-8,3,0);
   glColor3f(0, 0.5 , 0.1);
   glutSolidCone(1.5,2, 10, 2);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-7,0,0);
   glColor3f(0.1, 0.5 , 0.1);
   glutSolidCone(1.5,2, 10, 2);
   glPopMatrix();

   glEnd();
}

void groundroad()                   //GroundRoad
{
   glColor3f(0, 1, 0);
   glPushMatrix();
   glScalef(1, 500 , 0);
   wall();                           //Green BackGround


   glColor3f(0, 1, 0);
   //glPushMatrix();
   glScalef(1.1, 10, 0);
   wall();                           //Green BackGround
   glPopMatrix();


   glPushMatrix();
   glColor3f(0, 1, 0);
   glScalef(-1, 50, 0);
   wall();                           //Green BackGround
   glPopMatrix();


   glTranslatef(5, 0, .01);

   glPushMatrix();
   glScalef(.25, 500, 1);
   glColor3f(0.4,0.4,0.4);
   wall();                           //Black Road
   glPopMatrix();


   glPushMatrix();
   glTranslatef(1.5, -1.3, .01);
   glColor3f(1, 1, 1);
   for (i = 0; i < 250; i++)
   {
       glTranslatef(0, 2, 0);
       glRectf(0, 0, .5, 1);       //White Bricks on Road
   }

   glPopMatrix();



   glPushMatrix();
   glTranslatef(4, 1.3, -1);
   glColor3f(1, 0.54902, 0);
   for (i = 0; i < 500; i++)
   {
       glTranslatef(0, 10, 0);
       Grass();
       Grass2();

   }


   glPopMatrix();
   glPushMatrix();
   glTranslatef(9, 1.3, -1);
    glColor3f(0, 1, 0);
   glRectf(0,0,1000,600);
   glPopMatrix();




   }


void drawWheel(){
    glColor3f(0.8,1.0,1.0);
    glPushMatrix();
    glRotatef(0,0,0,1);
    glutWireTorus(0.1,0.25,10,50);
    glPopMatrix();
}
void drawBody(){


    glColor3f(1.0,1.0,0);
    glPushMatrix();
    glScalef(2.0,1.0,1.0);
    glutSolidCube(1);
    glPopMatrix();
}


void truck()
{

 glPushMatrix();
    glScalef(0.5,0.5,0.5);
            glPushMatrix();
                glRotatef(tip,1,0,0);
                glRotatef(turn2,0,1,0);
               // disp();
               drawBody();

            glPushMatrix();
                glTranslatef(-1.0,-0.5,0.65);
                drawWheel();
                glTranslatef(0.0,0.0,-1.3);
                drawWheel();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(1.0,-0.5,0.65);
                drawWheel();
                glTranslatef(0.0,0.0,-1.3);
                drawWheel();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    /////////////////
    /*
   glColor3f(0,0.545098,0.545098 );
   glScalef(1, 1, 2);
   glutSolidCube(1);

   glTranslatef(0, -.25, .5);
   glColor3f(0.862745, 0.862745, 0.862745);
   glutSolidCube(.5);
*/
   }
static void keyHandler(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27://Esc Button to exit
        exit(0);
case 'q' :
    case 'Q' :
        turn2+=rotateSteps;
        break;
    case 'a':
    case 'A':
        turn2-=rotateSteps;
        break;
    case 'w':
    case 'W':
        tip+=rotateSteps;
        break;
    case 's':
    case 'S':
       tip-=rotateSteps;
        break;
    case 'e':
    case 'E':
        {
        go+=speed;
        if(speed<2)
        speed+=0.1;
        }

        break;
    case 'd':
    case 'D':
        go=-speed;
        if(speed>0)
        speed-=0.1;
        break;

    }

    glutPostRedisplay();
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();



   glPushMatrix();

   glTranslatef(-4,0.8,-2);
   glColor3f(1,1,1);



   for (int i =0;i<20;i++){
       glTranslatef(0.4,0,0);

   }
   glPushMatrix();
   glTranslatef(-9,3,-4);
   glColor3f(1,1,1);
   Sun();
   glTranslatef(.2,0,0);
   glColor3f(0,0,0);
   Sun();
   glPopMatrix();

   glPopMatrix();

   glTranslatef(-7, -5, -6);
   glTranslatef(0, 0, roadmove); //Road Movement
   //glLightfv(GL_LIGHT0, GL_POSITION, position);
   glRotatef(scene, 0, 1, 0); //Scene Rotation
   glPushMatrix();
   glRotatef(-90, 1, 0, 0);
   groundroad();       //Ground & Road
   glPopMatrix();

   glPushMatrix();
   glRotatef(90, 0, 1, 0);
   for (int k = 0; k < 20; k++)
   {

       glTranslatef(25,0 , 0);



   }
   glPopMatrix();

   glTranslatef(6, 1, 0);
   glTranslatef(turn, 0, move);
   glTranslatef(0, 0, on);
   glRotatef(-180, 1, 0, 0);
   truck();//truck

   //train();

   if (start==-1) //control from keyboard
   {

       if (roadmove < 550)
       {
           roadmove = roadmove + .05; //Ground & Road Movement

           on = on - .055; // Truck Movement
           glutPostRedisplay();
       }
       else
       {

           }

       }




   glutSwapBuffers();

}

void SpecialInput(int key, int x, int y)
{
   switch (key)
   {
   case GLUT_KEY_UP: //Truck Forward


           move = move - .05;

               break;


   case GLUT_KEY_DOWN: //Truck Reverse


           move += .3;

       break;

   case GLUT_KEY_LEFT: //Truck Left Turn


                   turn = turn - .05;

               break;


   case GLUT_KEY_RIGHT: //Truck Righ Turn
       turn = turn + .05;
       break;

   }
   glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
      switch (key)
    {
    case 27://Esc Button to exit
        exit(0);
    case 'w':
    case 'W':
        start = -1;
        tip+=rotateSteps;
        break;
    case 's':
    case 'S':
       tip-=rotateSteps;
        break;
    case 'e':
    case 'E':
        {
        go+=speed;
        if(speed<2)
        speed+=0.1;
        }

        break;
    case 'd':
    case 'D':
        go=-speed;
        if(speed>0)
        speed-=0.1;
        break;

    case 'r': //reset all scene
       angle = 0;
       move = 0;
       scene = 0;
       roadmove = 0;
       on = 0;
       turn = 0;
       break;

   case '4': //scene rotation
       scene = scene + .5;
       break;

   case '6': //scene rotation
       scene = scene - .5;
       break;

   }
   glutPostRedisplay();
}

void reshape(int w, int h) // Create The Reshape Function (the viewport)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
   glLoadIdentity(); // Reset The Projection Matrix
   if (h == 0) // Calculate The Aspect Ratio Of The Window
       gluPerspective(80, (float)w, 1.0, 5000.0);
   else
       gluPerspective(80, (float)w / (float)h, 1.0, 5000.0);
   glMatrixMode(GL_MODELVIEW); // Select The Model View Matrix
   glLoadIdentity(); // Reset The Model View Matrix
}

int main(int a, char** b)
{
   glutInit(&a, b);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH |GLUT_RGB);
   glutInitWindowSize(1920,1080);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("CAR");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(SpecialInput);


   glutMainLoop();
   return 0;
}


