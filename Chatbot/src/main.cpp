#include <iostream>
#include "ChatbotClass.h"

using namespace std;

int main(){
    cout << "Chatbot v3" << endl;
    try{
        ChatbotClass bot("jarvis");

        while(!bot.quit()){
            bot.get_input();
            bot.respond();
        }

    }catch(string str){
        cerr << str << endl;
    }catch(...){
        cerr << "The program has stop due to some unknown exception" << endl;
    }
    return 0;
}

