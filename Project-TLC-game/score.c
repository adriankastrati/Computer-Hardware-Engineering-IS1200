struct score{
    char name[3];
    int points;
    char position; 
};

#define MAX_SCORES 32

struct score score_list[MAX_SCORES];

void init_highscore_list(){
    int i;
    int n;
    for(i = 0; i < MAX_SCORES; i++){
        for(n = 0; n < 3; n++){
            score_list[i].name[n] = '-';
        }
        score_list[i].points = 0;
        score_list[i].position = i;
    }

}

void delete_score_list(){
    int i;
    int n;
    for(i = 0; i < MAX_SCORES; i++){
        for(n = 0; n < 3; n++){
            score_list[i].name[n] = '-';
        }
        score_list[i].points = 0;
        score_list[i].position = i;
    }

    //write over value on kit
}

/*
char name[3];
int points;
char position; 
*/

void update_list(struct score save_score){
    int updated = 0;
    struct score temp0;
    struct score temp1;
    //
    int i;

    for(i = 31; i >= 0; i--){
        if((score_list[i].points <= save_score.points) && !updated){
            temp0 = score_list[i];
            score_list[i] = save_score;
        }

        else{
            
            temp1 = score_list[i];
            if(i == 1){
                break;
            }

            score_list[i] = temp0;
            temp0 = score_list[i - 1];
        }
    }
    
        //write over value on kit

}





