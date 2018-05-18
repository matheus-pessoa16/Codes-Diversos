#include "ChatbotClass.h"

/*record KnowledgeBase[] = {
		{"WHAT IS YOUR NAME", 
		{"MY NAME IS JARVIS.",
		"YOU CAN CALL ME JARVIS.",
		"WHY DO YOU WANT TO KNOW MY NAME?"}
		},

		{"HELLO",
		{"HI THERE!"}
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
		"ACTUALY,I'M VERY INTELLIENT!"}
		},

		{"ARE YOU REAL",
		{"DOES THAT QUESTION REALLY MATERS TO YOU?",
		"WHAT DO YOU MEAN BY THAT?",
		"I'M AS REAL AS I CAN BE."}
		},

		{"REPETITION T1**",
		{"YOU ARE REPEATING YOURSELF.",
		"USER, PLEASE STOP REPEATING YOURSELF.",
		"THIS CONVERSATION IS GETING BORING.",
		"DONT YOU HAVE ANY THING ELSE TO SAY?"}
		},
		
		{"REPETITION T2**",
		{"YOU'VE ALREADY SAID THAT.",
		"I THINK THAT YOU'VE JUST SAID THE SAME THING BEFORE.",
		"DIDN'T YOU ALREADY SAID THAT?",
		"I'M GETING THE IMPRESSION THAT YOU ARE REPEATING THE SAME THING."}
		},

		{"BOT DONT UNDERSTAND**",
		{"I HAVE NO IDEA OF WHAT YOU ARE TALKING ABOUT.",
		"I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
		"CONTINUE, I'M LISTENING...",
		"VERY GOOD CONVERSATION!"}
		},

		{"NULL INPUT**",
		{"HUH?",
		"WHAT THAT SUPPOSE TO MEAN?",
		"AT LIST TAKE SOME TIME TO ENTER SOMETHING MEANINGFUL.",
		"HOW CAN I SPEAK TO YOU IF YOU DONT WANT TO SAY ANYTHING?"}
		},

		{"NULL INPUT REPETITION**",
		{"WHAT ARE YOU DOING??",
		"PLEASE STOP DOING THIS IT IS VERY ANNOYING.",
		"WHAT'S WRONG WITH YOU?",
		"THIS IS NOT FUNNY."}
		},

		{"BYE",
		{"IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!",
		"BYE USER!",
		"OK, BYE!"}
		},

		{"ARE YOU A HUMAN BEING",
		{"WHY DO YOU WANT TO KNOW?",
		"IS THIS REALLY RELEVENT?"}
		},

		{"YOU ARE VERY INTELLIGENT",
		{"THANKS FOR THE COMPLIMENT USER, I THINK THAT YOU ARE INTELLIGENT TO!",
		"YOU ARE A VERY GENTLE PERSON!",
		"SO, YOU THINK THAT I'M INTELLIGENT."}
		},
		
		{"ARE YOU SURE",
		{"OFCORSE I'M.",
		"IS THAT MEAN THAT YOU ARE NOT CONVINCED?",
		"YES,OFCORSE!"}
		},

		{"WHO IS",
		{"I DONT THINK I KNOW WHO.",
		"DID YOU ASK SOMEONE ELSE ABOUT IT?",
		"WOULD THAT CHANGE ANYTHING AT ALL IF I TOLD YOU WHO."}
		},

		{"WHAT",
		{"I DONT KNOW.",
		"I DONT THINK I KNOW.",
		"I HAVE NO IDEA."}
		},

		{"WHERE",
		{"WHERE? WELL,I REALLY DONT KNOW.",
		"DOES THAT MATERS TO YOU TO KNOW WHERE?",
		"PERHAPS,SOMEONE ELSE KNOWS WHERE."}
		},

		{"WHY",
		{"I DONT THINK I KNOW WHY.",
		"WHY ARE YOU ASKING ME THIS?",
		"SHOULD I KNOW WHY.",
		"THIS WOULD BE DIFFICULT TO ANSWER."}
		},

		{"DO YOU",
		{"I DONT THINK I DO",
		"I WOULDN'T THINK SO.",
		"WHY DO YOU WANT TO KNOW?"}
		},

		{"CAN YOU",
		{"I THINK NOT.",
		"I'M NOT SURE.",
		"I DONT THINK THAT I CAN DO THAT."}
		},

		{"YOU ARE",
		{"WHAT MAKES YOU THINK THAT?",
		"IS THIS A COMPLIMENT?",
		"ARE YOU MAKING FUN OF ME?"}
		},

		{"DID YOU",
		{"I DONT THINK SO.",
		"ANYWAY, I WOULDN'T REMEMBER EVEN IF I DID."}
		},

		{"COULD YOU",
		{"ARE YOU ASKING ME FOR A FEVER?",
		"WELL,LET ME THINK ABOUT IT.",
		"SORRY,I DONT THINK THAT I COULD DO THIS."}
		},

		{"WOULD YOU",
		{"IS THAT AN INVITATION?",
		"I WOULD HAVE TO THINK ABOUT IT FIRST."}
		},

		{"HOW",
		{"I DONT THINK I KNOW HOW."}
		},

		{"WHICH ONE",
		{"I DONT THINK THAT I KNOW WICH ONE IT IS.",
		"THIS LOOKS LIKE A TRICKY QUESTION TO ME."}
		},

		{"PERHAPS",
		{"WHY ARE YOU SO UNCERTAIN?",
		"YOU SEEMS UNCERTAIN."}
		},

		{"YES",
		{"SO,IT IS YES.",
		"OH, REALLY?",
		"OK THEN."}
		},

		{"I DONT KNOW",
		{"ARE YOU SURE?",
		"ARE YOU REALLY TELLING ME THE TRUTH?",
		"SO,YOU DONT KNOW?"}
		},

		{"NOT REALLY",
		{"OK I SEE.",
		"YOU DONT SEEM PRETTY CERTAIN.",
		"SO,THAT WOULD BE A \"NO\"."}
		},

		{"IS THAT TRUE",
		{"I CAN'T BE QUIET SURE ABOUT THIS.",
		"CAN'T TELL YOU FOR SURE.",
		"DOES THAT REALLY MATERS TO YOU?"}
		},

		{"YOU",
		{"SO,YOU ARE TALKING ABOUT ME.",
		"WHY DONT WE TALK ABOUT YOU INSTEAD?",
		"ARE YOU TRYING TO MAKING FUN OF ME?"}
		},

		{"THANKS",
		{"YOU ARE WELCOME!",
		"NO PROBLEM!"}
		},

		{"WHAT ELSE",
		{"WELL,I DONT KNOW.",
		"WHAT ELSE SHOULD THERE BE?",
		"THIS LOOKS LIKE A COMPLICATED QUESTION TO ME."}
		},

		{"SORRY",
		{"YOU DONT NEED TO BE SORRY USER.",
		"IT'S OK.",
		"NO NEED TO APOLOGIZE."}
		},

		{"NOT EXACTLY",
		{"WHAT DO YOU MEAN NOT EXACTLY?",
		"ARE YOU SURE?"}
		},

		{"EXACTLY",
		{"SO,I WAS RIGHT.",
		"OK THEN."}
		},

		{"ALRIGHT",
		{"ALRIGHT THEN.",
		"OK THEN."}
		},

		{"I DONT",
		{"WHY NOT?",
		"AND WHAT WOULD BE THE REASON FOR THIS?"}
		},

		{"REALLY",
		{"WELL,I CAN'T TELL YOU FOR SURE.",
		"ARE YOU TRYING TO CONFUSE ME?",
		"PLEASE DONT ASK ME SUCH QUESTION,IT GIVES ME HEADEACHS."}
		}
	};
*/
ChatbotClass::ChatbotClass(string name){
	this->botName = name;
	this->quitProgram = 0;
	this->currentInput = "null";
    seed_random_generator();   


	KnowledgeBase["WHAT IS YOUR NAME"] = {"MY NAME IS JARVIS.", "YOU CAN CALL ME JARVIS.","WHY DO YOU WANT TO KNOW MY NAME?"};
	KnowledgeBase["HELLO"] = {"HI THERE!"};
	KnowledgeBase["HI"] = {"HI THERE!", "HOW ARE YOU?",	"HI!"};
		
	KnowledgeBase["HOW ARE YOU"]=
		{"I'M DOING FINE!",
		"I'M DOING WELL AND YOU?",
		"WHY DO YOU WANT TO KNOW HOW AM I DOING?"};

	KnowledgeBase["WHO ARE YOU"] = 
		{"I'M AN A.I PROGRAM.",
		"I THINK THAT YOU KNOW WHO I'M.",
		"WHY ARE YOU ASKING?"};

	KnowledgeBase["ARE YOU INTELLIGENT"] = 
		{"YES,OFCORSE.",
		"WHAT DO YOU THINK?",
		"ACTUALY,I'M VERY INTELLIENT!"};

	KnowledgeBase["ARE YOU REAL"] =
		{"DOES THAT QUESTION REALLY MATERS TO YOU?",
		"WHAT DO YOU MEAN BY THAT?",
		"I'M AS REAL AS I CAN BE."};

	KnowledgeBase["REPETITION T1**"] = 
		{"YOU ARE REPEATING YOURSELF.",
		"USER, PLEASE STOP REPEATING YOURSELF.",
		"THIS CONVERSATION IS GETING BORING.",
		"DONT YOU HAVE ANY THING ELSE TO SAY?"};
		
	KnowledgeBase["REPETITION T2**"] =
		{"YOU'VE ALREADY SAID THAT.",
		"I THINK THAT YOU'VE JUST SAID THE SAME THING BEFORE.",
		"DIDN'T YOU ALREADY SAID THAT?",
		"I'M GETING THE IMPRESSION THAT YOU ARE REPEATING THE SAME THING."};

	KnowledgeBase["BOT DONT UNDERSTAND**"] = 
		{"I HAVE NO IDEA OF WHAT YOU ARE TALKING ABOUT.",
		"I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
		"CONTINUE, I'M LISTENING...",
		"VERY GOOD CONVERSATION!"};

	KnowledgeBase["NULL INPUT**"] =		{"HUH?",
		"WHAT THAT SUPPOSE TO MEAN?",
		"AT LIST TAKE SOME TIME TO ENTER SOMETHING MEANINGFUL.",
		"HOW CAN I SPEAK TO YOU IF YOU DONT WANT TO SAY ANYTHING?"};

	KnowledgeBase["NULL INPUT REPETITION**"] =
		{"WHAT ARE YOU DOING??",
		"PLEASE STOP DOING THIS IT IS VERY ANNOYING.",
		"WHAT'S WRONG WITH YOU?",
		"THIS IS NOT FUNNY."};

	KnowledgeBase["BYE"] = 
		{"IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!",
		"BYE USER!",
		"OK, BYE!"};

	KnowledgeBase["ARE YOU A HUMAN BEING"] =
		{"WHY DO YOU WANT TO KNOW?",
		"IS THIS REALLY RELEVENT?"};

	KnowledgeBase["YOU ARE VERY INTELLIGENT"] = 
		{"THANKS FOR THE COMPLIMENT USER, I THINK THAT YOU ARE INTELLIGENT TO!",
		"YOU ARE A VERY GENTLE PERSON!",
		"SO, YOU THINK THAT I'M INTELLIGENT."};
		
	KnowledgeBase["ARE YOU SURE"] = 
		{"OFCORSE I'M.",
		"IS THAT MEAN THAT YOU ARE NOT CONVINCED?",
		"YES,OFCORSE!"};

	KnowledgeBase["WHO IS"] = 
		{"I DONT THINK I KNOW WHO.",
		"DID YOU ASK SOMEONE ELSE ABOUT IT?",
		"WOULD THAT CHANGE ANYTHING AT ALL IF I TOLD YOU WHO."};

	KnowledgeBase["WHAT"] = 
		{"I DONT KNOW.",
		"I DONT THINK I KNOW.",
		"I HAVE NO IDEA."};

	KnowledgeBase["WHERE"] = 
		{"WHERE? WELL,I REALLY DONT KNOW.",
		"DOES THAT MATERS TO YOU TO KNOW WHERE?",
		"PERHAPS,SOMEONE ELSE KNOWS WHERE."};

	KnowledgeBase["WHY"] = 
		{"I DONT THINK I KNOW WHY.",
		"WHY ARE YOU ASKING ME THIS?",
		"SHOULD I KNOW WHY.",
		"THIS WOULD BE DIFFICULT TO ANSWER."};

	KnowledgeBase["DO YOU"] = 
		{"I DONT THINK I DO",
		"I WOULDN'T THINK SO.",
		"WHY DO YOU WANT TO KNOW?"};

	KnowledgeBase["CAN YOU"] = 
		{"I THINK NOT.",
		"I'M NOT SURE.",
		"I DONT THINK THAT I CAN DO THAT."};

	KnowledgeBase["YOU ARE"] = 
		{"WHAT MAKES YOU THINK THAT?",
		"IS THIS A COMPLIMENT?",
		"ARE YOU MAKING FUN OF ME?"};

	KnowledgeBase["DID YOU"]=
		{"I DONT THINK SO.",
		"ANYWAY, I WOULDN'T REMEMBER EVEN IF I DID."};

	KnowledgeBase["COULD YOU"]=
		{"ARE YOU ASKING ME FOR A FEVER?",
		"WELL,LET ME THINK ABOUT IT.",
		"SORRY,I DONT THINK THAT I COULD DO THIS."};

	KnowledgeBase["WOULD YOU"] = 
		{"IS THAT AN INVITATION?",
		"I WOULD HAVE TO THINK ABOUT IT FIRST."};

	KnowledgeBase["HOW"] = 
		{"I DONT THINK I KNOW HOW."};

	KnowledgeBase["WHICH ONE"] = 
		{"I DONT THINK THAT I KNOW WICH ONE IT IS.", "THIS LOOKS LIKE A TRICKY QUESTION TO ME."};

	KnowledgeBase["PERHAPS"] =
		{"WHY ARE YOU SO UNCERTAIN?",
		"YOU SEEMS UNCERTAIN."};

	KnowledgeBase["YES"] =
		{"SO,IT IS YES.",
		"OH, REALLY?",
		"OK THEN."};

	KnowledgeBase["I DONT KNOW"] = 
		{"ARE YOU SURE?",
		"ARE YOU REALLY TELLING ME THE TRUTH?",
		"SO,YOU DONT KNOW?"};

	KnowledgeBase["NOT REALLY"] =
		{"OK I SEE.",
		"YOU DONT SEEM PRETTY CERTAIN.",
		"SO,THAT WOULD BE A \"NO\"."};

	KnowledgeBase["IS THAT TRUE"] =
		{"I CAN'T BE QUIET SURE ABOUT THIS.",
		"CAN'T TELL YOU FOR SURE.",
		"DOES THAT REALLY MATERS TO YOU?"};

	KnowledgeBase["YOU"] =
		{"SO,YOU ARE TALKING ABOUT ME.",
		"WHY DONT WE TALK ABOUT YOU INSTEAD?",
		"ARE YOU TRYING TO MAKING FUN OF ME?"};


	KnowledgeBase["THANKS"] = 
		{"YOU ARE WELCOME!",
		"NO PROBLEM!"};

	KnowledgeBase["WHAT ELSE"] =
		{"WELL,I DONT KNOW.",
		"WHAT ELSE SHOULD THERE BE?",
		"THIS LOOKS LIKE A COMPLICATED QUESTION TO ME."};

	KnowledgeBase["SORRY"] = 
		{"YOU DONT NEED TO BE SORRY USER.",
		"IT'S OK.",
		"NO NEED TO APOLOGIZE."};

	KnowledgeBase["NOT EXACTLY"] =
		{"WHAT DO YOU MEAN NOT EXACTLY?",
		"ARE YOU SURE?"};

	KnowledgeBase["EXACTLY"] = 
		{"SO,I WAS RIGHT.",
		"OK THEN."};

	KnowledgeBase["ALRIGHT"] = 
		{"ALRIGHT THEN.",
		"OK THEN."};

	KnowledgeBase["I DONT"] = 
		{"WHY NOT?",
		"AND WHAT WOULD BE THE REASON FOR THIS?"};

	KnowledgeBase["REALLY"] =
		{"WELL,I CAN'T TELL YOU FOR SURE.",
		"ARE YOU TRYING TO CONFUSE ME?",
		"PLEASE DONT ASK ME SUCH QUESTION,IT GIVES ME HEADEACHS."};

	sizeKnowledgeBase = sizeof(KnowledgeBase)/sizeof(KnowledgeBase[0]); 
}

ChatbotClass::~ChatbotClass(){
}

void ChatbotClass::find_match(){
    //vector<string> result;
    int i=0;
    for(unordered_map<string, vector<string> >::iterator it = KnowledgeBase.begin(); it != KnowledgeBase.end(); it++){
        //cout << it->first << endl;
		string keyword = it->first;
        if( currentInput.find(keyword) != string::npos ){
			//cout << it->second[0] << endl;
            //copy(it->second, result);
            response_list = it->second;
			//return response_list;
			break;
        }
    }
    //return response_list;
}

void ChatbotClass::handle_repetition(){
    if(currentResponse.size() > 0){
        response_list.erase(response_list.begin());
    }
    if(no_response()){
        save_input();
        set_input(currentEvent);
        find_match();
        restore_input();
    }
    select_response();
}

void ChatbotClass::handle_event(string input){
    save_prev_event();
    set_event(input);
    save_input();
    set_input(input);
    if(!same_event()){
        find_match();
    }
    restore_input();
}

void ChatbotClass::handle_user_repetition(){
    if(same_input()){
        handle_event("REPETITION T1**");
    }else if(similar_input()){
        handle_event("REPETITION T2**");
    }
}

void ChatbotClass::get_input(){
    cout << "> ";
    save_prev_input();
    getline(cin, currentInput);
    preprocess_input();
	//cout << KnowledgeBase["HI"][0] << endl;
}

void ChatbotClass::respond(){
    save_prev_response();
    set_event("BOT UNDERSTAND**");

    if(null_input()){
		//cout << "NULL" << endl;
        handle_event("NULL INPUT**");
    }else if(user_repeat()){
        handle_user_repetition();
    }else{
        find_match();
    }

    if(user_quit()){
        quitProgram = true;
    }

    if(!bot_understand()){
        handle_event("BOT DON'T UNDERSTAND**");
    }

    if(response_list.size() > 0){
        select_response();
		//cout << currentResponse << endl;
        if(bot_repeat()) {
            handle_repetition();
        }
        print_response();
		//cout << response_list[0] << endl;
    }

}

bool ChatbotClass::quit(){
    return quitProgram;
}