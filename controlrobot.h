#ifndef CONTROLROBOT2_H
#define CONTROLROBOT2_H


#include <exception>
#include <iostream>
#include "Robot.h"
#include "utility.h"
#include <string>
#include <QDebug>
#include <QByteArray>


using namespace std;

int lenVect;


vector<string> splitV;


Robot robot = new Robot();
bool clickAndHold = false;

int lenSingleData;
int lenSingleNthData;

void mainControl_Robot(QList<QByteArray> singleData)
{


        try{

        lenSingleData  = singleData.length();

        //for(int k = 0 ; k < lenSingleData ; k ++)
        {


             lenSingleNthData = singleData[0].length();

            if(lenSingleNthData>0)
            {

            qDebug() << "\nline = "<<singleData[0] <<"|\n";



//            qDebug() << singleData[0] << "\n";

            if ( singleData[0] == COMMAND_MOUSE_LEFT_CLICK ) {
                qDebug() <<("left click");

                robot.mouseLeftCLick(false);
            }

            else if (singleData[0] == COMMAND_MOUSE_RIGHT_CLICK) {
                robot.mouseRightClick();
            }

            else if (singleData[0] == COMMAND_MOUSE_PAD_SHORT_CLICK) {
                qDebug() <<("short click");

                robot.mouseLeftCLick(false);
            }
            else if (singleData[0] == COMMAND_MOUSE_LEFT_CLICKHOLD){
                qDebug() <<("left hold click");

                robot.mouseLeftCLick(true);
                clickAndHold = true;

            }

            else if (singleData[0] == COMMAND_MOUSE_PAD_UP){

                qDebug() <<("pad up");

                if (clickAndHold == true){
                    clickAndHold = false;
                    robot.mouseLeftCLickUp();

                }


            }
            else if (singleData[0] == COMMAND_CLOSE_WINDOW) {
                qDebug() <<("close window");

                robot.AltF4();
            }

            else if (singleData[0] == COMMAND_TAB_WINDOW) {

            }

            else if (singleData[0] == COMMAND_ENTER) {
                robot.pressEnter();
                qDebug() <<("command neter");


            }

            else if (singleData[0] == COMMAND_SCROLL_VERTICAL_DOWN) {
                robot.mouseScroll(1);
            }

            else if (singleData[0] == COMMAND_SCROLL_VERTICAL_UP) {
                robot.mouseScroll(2);
            }

            else if (singleData[0] == COMMAND_ESC) {
                robot.pressESC();
            }

            else if (singleData[0] == COMMAND_COPY) {
                robot.copyCommand();
            }

            else if (singleData[0] == COMMAND_CUT) {
                robot.cutCommand();
            }



            else if (singleData[0] == COMMAND_PEST) {
                robot.pestCommand();
            }

            else if (singleData[0] == TYPE_KEY_ALPHSBET) {

                if (lenSingleData == 2){

                        robot.keyboard(singleData[1].toStdString());
                }
            }
            else if (singleData[0] == TYPE_KEY_DELETE) {

                robot.keyTypeDelete();
            }



            if (singleData[0] == COMMAND_MOUSE_MOVE && lenSingleData == 3) {



                int x = (singleData[1].toInt());
                int y = (singleData[2].toInt());
                robot.mouseMoveTo(x, y);


            }

            }
        }

    }

    catch (exception &ex){

    }





}






#endif // CONTROLROBOT2_H
