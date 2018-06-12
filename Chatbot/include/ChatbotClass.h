#ifndef CHATBOTCLASS_H
#define CHATBOTCLASS_H

#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>
#include <algorithm>

#define MAX_RESP 4

using namespace std;

// typedef struct {
//     string input;
//     string responses[MAX_RESP];
// } record;

class ChatbotClass{

    string prevInput;
    string prevEvent;
    string prevResponse; 
    string currentEvent; 
    string currentInput;
    string currentResponse;
    string inputBackup;
    string botName;
    string userName;
    bool quitProgram;

    vector<string> response_list;

    size_t sizeKnowledgeBase;

    unordered_map<string, vector<string> > KnowledgeBase;

    public:
    ChatbotClass(string name);
    virtual ~ChatbotClass();

    void get_input();
    void respond();
    
    bool quit();

    protected: 
    private:
    void select_response(){
        shuffle(response_list, response_list.size());
        currentResponse = response_list[0];
    }

    void save_prev_input(){
        prevInput = currentInput;
    }

    void save_prev_response(){
        prevResponse = currentResponse;
    }

    void save_prev_event() {
        prevEvent = currentEvent;
    }

    void set_event(string event) {
        currentEvent = event;
    }

    void save_input() {
        inputBackup = currentInput;
    }
    void set_input(string input) {
        currentInput = input;
    }

    void restore_input() {
        currentInput = inputBackup;
    }
    void print_response() {
        if(currentResponse.size() > 0){
            cout << currentResponse << endl;
        }
    }
    void preprocess_input(){
        inputPreProcessing(currentInput);
    }

    bool bot_repeat() {
        return ( currentResponse == prevResponse && prevResponse.length() > 0 );
    }

    bool user_repeat() {
        return (prevInput.length() > 0 && // there is some content in prevInput
                ((currentInput == prevInput) || // the input is the same of the previous
                (currentInput.find(prevInput) != string::npos) || // part of prevInput is found in the current input
                (prevInput.find(currentInput) != string::npos) // part of currentInput is found in the previous input
                ));
    }
    bool bot_understand() {
        return response_list.size() > 0;
    }
    bool null_input() {
        return (currentInput.size() == 0 && prevInput.size() != 0);
    }
    bool null_input_repetition() {
         return (currentInput.size() == 0 && prevInput.size() == 0);
    }
    bool user_quit() {
        quitProgram = (currentInput.find("BYE") != string::npos);
        return quitProgram;
    }
    bool same_event() {
        return (currentEvent.length() > 0 && currentEvent == prevEvent);
    }
    bool same_input() {
        return (currentInput.length() > 0 && currentInput == prevInput);
    }

    bool no_response(){
        return response_list.size() == 0;
    }

    bool similar_input(){
        return (
                currentInput.length() > 0 &&
                (currentInput.find(prevInput) != string::npos ||
                prevInput.find(currentInput) != string::npos)
            );
    }

    void find_match();
    void handle_repetition();
    void handle_user_repetition();
    void handle_event(string input);
    
    void seed_random_generator(){
        srand((unsigned) time(NULL));
    }

    template <typename T>
    void shuffle(T &array, int size){
        int index;
        for(int i =0; i < size; i++){
            index = rand() % size;
            swap(array[i], array[index]);
        }
    }

    void copy(vector<string> &array, vector<string> &v){
        //for(int i=0; i<MAX_RESP; i++){
           // v.push_back(array[i]);
        //}
        v = array;
    }

    void inputPreProcessing(string &input){
        transform(input.begin(), input.end(), input.begin(), ::toupper);

        //cout << input << endl;
        unordered_map <char, int> punctuation;
        punctuation[','] = 1;
        punctuation['.'] = 1; 
        punctuation['!'] = 1;
        punctuation['?'] = 1;
        punctuation[';'] = 1;
        punctuation['/'] = 1;

        for(int i=0; i<input.size(); i++){
            if( punctuation.find( input[i] ) != punctuation.end()){
                input.erase( input.begin() + i );
            }
        }
    }

};

#endif // ChatbotClass_H