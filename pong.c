#include <stdio.h>

void pong_display(int coord_rocket_1, int coord_rocket_2, int ball_x, int ball_y);
int keyboard(int rocket);

int main() {
    int score1 = 0, score2 = 0;
    int coord_rocket_1 = 12, coord_rocket_2 = 12;
    int ball_x = 39, ball_y = 12;
    int dx = 1, dy = 1;
    while (score1 != 21 && score2 != 21) {
        printf("                                   PING-PONG\n");
        
        // check for winning
        if (ball_x == 64) {
            score1++;
            ball_x = 39, ball_y = 12;
            coord_rocket_1 = 12, coord_rocket_2 = 12;
            dx *= -1;
        }
      
        if (ball_x == 14) {
            score2++;
            ball_x = 39, ball_y = 12;
            coord_rocket_1 = 12, coord_rocket_2 = 12;
            dx *= -1;
        }
      
        pong_display(coord_rocket_1, coord_rocket_2, ball_x, ball_y);
        printf("Scores: %d:%d\n", score1, score2);
        coord_rocket_1 = keyboard(coord_rocket_1);
        coord_rocket_2 = keyboard(coord_rocket_2);
      
        // moving of the ball
        ball_x += dx;
        ball_y += dy;
      
        if (((ball_x == 15)
            && (ball_y >= coord_rocket_1 - 1 && ball_y <= coord_rocket_1 + 1))
            || ((ball_x == 63)
            && (ball_y >= coord_rocket_2 - 1
            && ball_y <= coord_rocket_2 + 1))) {
            dx *= -1;
        }
      
        if (ball_y == 1 || ball_y == 23) {
            dy *= -1;
        }
      
        printf("\e[1;1H\e[2J");
    }
  
    if (score1 == 21) {
        printf("Поздравляю, Игрок1!\nВы набрали 21 очко.\n");
    }
  
    if (score2 == 21) {
        printf("Поздравляю, Игрок2!\nВы набрали 21 очко.\n");
    }
  
    return 0;
}

void pong_display(int coord_rocket_1, int coord_rocket_2, int ball_x, int ball_y) {
    char ball = '*';
    char slash = '|';
    char dash = '-';
    char space = ' ';
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if ((i == 0) || (i == 24)) {
                printf("%c", dash);
            } else if ((j == 0 || j == 79)
                || (((j == 15
                && (i == coord_rocket_1 || i == coord_rocket_1 - 1
                || i == coord_rocket_1 + 1))
                || (j == 64
                && (i == coord_rocket_2 || i == coord_rocket_2 - 1
                || i == coord_rocket_2 + 1))))) {
                printf("%c", slash);
            } else if (i == ball_y && j == ball_x) {
                printf("%c", ball);
            } else {
                printf("%c", space);
            }
        }
        printf("\n");
    }
}

int keyboard(int rocket) {
    char key, sp;
    scanf("%c", &key);
    scanf("%c", &sp);
    if ((key == 'k' || key == 'a') && (rocket > 2)) {
        return --rocket;
    } else if ((key == 'z' || key == 'm') && (rocket < 22)) {
        return ++rocket;
    } else {
        return rocket;
    }
}
