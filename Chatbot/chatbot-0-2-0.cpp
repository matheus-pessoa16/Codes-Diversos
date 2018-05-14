#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define MAX_RESP 3

using namespace std;

// TO DO:
// * VERIFICAR REPETIÇÕES DE RESPOSTAS SALVANDO A ÚLTIMA RESPOSTA DADA - DONE
// * TRATAR LOWERCASE E PONTUAÇÃO - DONE
// Esses tratamentos dão uma melhorada no bot, porém existem mais coisas.
// Siga o tutorial.
//
//

vector<string> find_match(string input);
void copy(string array[], vector<string> &v);
void inputPreProcessing(string &input);

typedef struct {
    string input;
    string responses[MAX_RESP];
}record;

record KnowledgeBase[] = {
    {"WHAT IS YOUR NAME", 
    {"MY NAME IS CHATTERBOT2.",
     "YOU CAN CALL ME CHATTERBOT2.",
     "WHY DO YOU WANT TO KNOW MY NAME?"}
    },

    {"HI", 
    {"HI THERE!",
     "HOW ARE YOU?",
     "HI!"}
    },
    
    {"HOW ARE YOU",
    {"I'M DOING FINE!",
    "I'M DOING WELL AND YOU?",
    "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}
    },

    {"WHO ARE YOU",
    {"I'M AN A.I PROGRAM.",
     "I THINK THAT YOU KNOW WHO I'M.",
     "WHY ARE YOU ASKING?"}
    },

    {"ARE YOU INTELLIGENT",
    {"YES,OFCORSE.",
     "WHAT DO YOU THINK?",
     "ACTUALY,I'M VERY INTELLIGENT!"}
    },

    {"ARE YOU REAL",
    {"DOES THAT QUESTION REALLY MATERS TO YOU?",
     "WHAT DO YOU MEAN BY THAT?",
     "I'M AS REAL AS I CAN BE."}
    }
};

size_t sizeKnowledgeBase = sizeof(KnowledgeBase)/sizeof(KnowledgeBase[0]);

int main(){

    srand((unsigned) time(NULL));  
    string in, out, lastResponse = "", previousInput;
    int n;
    vector<string> responses;

    while(1){
        cout << ">";
        getline(cin, in);
        inputPreProcessing(in);
        responses = find_match(in);

        if(in == previousInput && in.size() > 0){
            cout << "YOU'RE REPEATING YOURSELF." << endl;
        }else if(in.find( "BYE" ) != string::npos || in.find( "bye" ) != string::npos){
            cout << "IT WAS NICE TALKING TO YOU. SEE YOU NEXT TIME!" << endl;
            break;
        }else if(responses.size() == 0){
            cout << "I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT." << endl;
        }else{
            n = rand() % MAX_RESP;
            out = responses[n];
            
            while( (out.compare(lastResponse)) == 0){
                n = rand() % MAX_RESP;
                out = responses[n];
            }

            cout << out << endl;
            lastResponse = out;
        }
        previousInput = in;
    }
    return 0;
}

vector<string> find_match(string input){
    vector<string> result;
    int i=0;
    for(; i < sizeKnowledgeBase; i++){
        string keyword = KnowledgeBase[i].input;
        if( input.find(keyword) != string::npos ){
            copy(KnowledgeBase[i].responses, result);
            return result;
        }
    }
    return result;
}

void copy(string array[], vector<string> &v){
    for(int i=0; i<MAX_RESP; i++){
        v.push_back(array[i]);
    }
}

void inputPreProcessing(string &input){
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    //cout << input << endl;
    unordered_map<char, int> punctuation;
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