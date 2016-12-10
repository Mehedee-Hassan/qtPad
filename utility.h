
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<string>
#include<QByteArray>

using namespace std;





//=======================================================
//              command and flags
//=======================================================



const QByteArray COMMAND_MOUSE_PAD_TOUCH_D           = "1";
const QByteArray COMMAND_MOUSE_MOVE                  = "3";
const QByteArray FLAG_STAR_PAD                       = "4";
const QByteArray COMMAND_MOUSE_PAD_SHORT_CLICK       = "5";
const QByteArray COMMAND_CLOSE_WINDOW                = "7";
const QByteArray COMMAND_TAB_WINDOW                  = "8";
const QByteArray COMMAND_ENTER                       = "9";
const QByteArray COMMAND_SCROLL_VERTICAL_DOWN        = "10";
const QByteArray COMMAND_SCROLL_VERTICAL_UP          = "11";
const QByteArray COMMAND_ESC                         = "12";
const QByteArray COMMAND_MOUSE_LEFT_CLICK        = "13";
const QByteArray COMMAND_MOUSE_RIGHT_CLICK           = "14";
const QByteArray COMMAND_MOUSE_LEFT_CLICKHOLD        = "15";
const QByteArray COMMAND_MOUSE_PAD_UP                = "16";
const QByteArray FLAG_SEARCH                         = "18";
const QByteArray COMMAND_COPY                        = "19";
const QByteArray COMMAND_PEST                        = "20";
const QByteArray COMMAND_CUT                         = "21";
const QByteArray TYPE_KEY_ALPHSBET                   = "22";
const QByteArray TYPE_KEY_DELETE                     = "23";



//=======================================================
//              command and flags
//=======================================================





QList<QByteArray> utility_splitQbA(QByteArray message , char delimiter){




    int len = message.length();

    QList<QByteArray> returnVector;

    QByteArray tmpString = "";

    int j = 0;

    for (int i = 0; i < len; i++){

        // cout<<message[i]<<" ";


        if (i+1 == len){

            tmpString += message[i];
            //cout << test << endl;

            returnVector.push_back(tmpString);
            tmpString = "";

        }
        else
        if (message[i] != delimiter || j > 0){
            tmpString += message[i];
            j = 0;
        }
        else if(message[i] == delimiter ){

            j++;
            //cout << test << endl;
            returnVector.append(tmpString);
            tmpString = "";
        }

    }

    return returnVector;



}





//vector<string> splitString(char * message, char delimiter){


//    int len = strlen(message);

//    vector <string> returnVector;

//    string tmpString = "";
//    int j = 0;

//    for (int i = 0; i < len; i++){

//        // cout<<message[i]<<" ";



//        if (message[i + 1] == '\0'){

//            tmpString += message[i];
//            //cout << test << endl;

//            returnVector.push_back(tmpString);
//            tmpString = "";

//        }
//        else
//        if (message[i] != delimiter && (++j) >1){
//            tmpString += message[i];
//        }
//        else{

//            //cout << test << endl;
//            returnVector.push_back(tmpString);
//            tmpString = "";
//            j = 0;
//        }

//    }

//    return returnVector;
//}





//vector<string> splitString2(const char * message, char delimiter){


//    int len = strlen(message);

//    vector <string> returnVector;

//    string tmpString = "";
//    int j = 0;

//    for (int i = 0; i < len; i++){

//        // cout<<message[i]<<" ";



//        if (message[i + 1] == '\0'){

//            tmpString += message[i];
//            //cout << test << endl;

//            returnVector.push_back(tmpString);
//            tmpString = "";
//            j++;
//        }
//        else
//        if (message[i] != delimiter){
//            tmpString += message[i];
//        }
//        else{

//            //cout << test << endl;
//            returnVector.push_back(tmpString);
//            tmpString = "";
//            j++;
//        }

//    }





//    return returnVector;
//}



//string* splitStringStrArray(char * message, char delimiter){


//    int len = strlen(message);

//    string returnVector[3];

//    string tmpString = "";
//    int j = 0;

//    for (int i = 0; i < len; i++){

//        // cout<<message[i]<<" ";



//        if (message[i + 1] == '\0'){

//            tmpString += message[i];
//            //cout << test << endl;

//            returnVector[j] = tmpString;
//            tmpString = "";
//            j++;
//        }
//        else
//        if (message[i] != delimiter){
//            tmpString += message[i];
//        }
//        else{

//            //cout << test << endl;
//            returnVector[j] = tmpString;

//            tmpString = "";
//            j++;
//        }

//    }





//    return returnVector;
//}



//template <typename Ttype> Ttype fromString(const std::string& str){

//    std::istringstream ss(str);


//    Ttype returnString;
//    ss >> returnString;

//    return returnString;

//}




//int getIntFromString(string str){

//    int data = -1;

//    try{

//        if (!str.empty()){
//            data = fromString<int>(str);
//            cout << "FLAG = " << data << endl;
//        }

//    }
//    catch (exception &e){
//        cout << " exception " << endl;

//    }

//    return data;
//}



//float getFloatFromString(string str){

//    float data = -1;

//    try{

//        if (!str.empty()){
//            data = fromString<float>(str);
//            cout << "FLAG = " << data << endl;
//        }

//    }
//    catch (exception &e){
//        cout << " exception " << endl;

//    }

//    return data;
//}





//bool matchFirstN(char    *str,   char    *toMatch,  int N){


//    if(strlen(str) >= strlen(toMatch))
//        for(int i = 0 ; i < N ; i++){

//            if(str[i] != toMatch[i])
//                return false;


//        }


//    return true;
//}






