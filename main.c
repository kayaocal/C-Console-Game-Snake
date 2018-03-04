#include "main.h"



int main()
{
	printf("main");

	//hide_cursor();
	
	
	while(true)
	{
		Sleep(SLEEP_TIME);
		system("cls");
		switch(game_state)
		{
			case MENU_STATE:
				draw_menu();
			break;

			case GAME_STATE:
				get_key();
				move_snake();
				draw_game();
			break;

			case GAME_OVER_STATE:
				draw_game_over();
			break;

			case GAME_EXIT_STATE:
				return 0;
				exit(0);
		}
		
	}
	
	return 0;
	
}

void reset_game()
{
	
	for(int i = 0; i < MAP_WIDTH; i++)
	{
		for(int j = 0; j < MAP_HEIGHT; j++)
		{
			map[i][j] = ascii_space_code;
		}	
	}
	
	for(int i = 1; i <MAP_HEIGHT -1; i++)
	{
		map[MAP_WIDTH-1][i] = ascii_v_line_code;
		map[0][i] = ascii_v_line_code;
	}
	
	for(int j = 1; j < MAP_WIDTH-1; j++)
	{
			map[j][MAP_HEIGHT - 1] = ascii_h_line_code;
			map[j][0] = ascii_h_line_code;
	}
	
	map[0][0] = (char)201;
	map[0][MAP_HEIGHT-1] = (char)200;
	map[MAP_WIDTH - 1][0] = (char)187;
	map[MAP_WIDTH - 1][MAP_HEIGHT-1] = (char)188;

	snake_pos_x = MAP_WIDTH/2;
	snake_pos_y = MAP_HEIGHT/2;
	
	if(player[0] == NULL)
	{
		VEC2_INT* snake_head = vec2_int(snake_pos_x, snake_pos_y);
		
		player[0] = snake_head;
		player[1] = vec2_int(snake_pos_x - 1, snake_pos_y);
		player[2] = vec2_int(snake_pos_x - 2, snake_pos_y);
		player[3] = vec2_int(snake_pos_x - 3, snake_pos_y);
		
		for(int i = 4; i < MAP_WIDTH * MAP_HEIGHT; i++)
		{
			player[i] = vec2_int(-1,-1); 
		}
	}else
	{
		vec2_set_int(player[0], snake_pos_x, snake_pos_y);
		vec2_set_int(player[1], snake_pos_x - 1, snake_pos_y);
		vec2_set_int(player[2], snake_pos_x - 2, snake_pos_y);
		vec2_set_int(player[3], snake_pos_x - 3, snake_pos_y);

		for(int i = 4; i < MAP_WIDTH * MAP_HEIGHT; i++)
		{
			vec2_set_int(player[i], -1, -1);
		}
	}
	
	direction = vec2_int(1,0);

	score = 0;
	
	
}

void draw_game()
{
	merge_snake_to_map();

	printf("\n SCORE : %d", score);
	for(int i = 0; i < MAP_HEIGHT; i++)
	{
		printf("\n");
		for(int j = 0; j < MAP_WIDTH; j++)
		{
			printf("%c",map_and_snake[j][i]);
		}	
	}


	if(game_state ==  GAME_STATE)
	{
		printf("\n\nAs an hungry snake, you should eat everything");
		printf("\n\nTip : Use arrows to move!");	
	}else if(game_state == GAME_OVER_STATE)
	{
		printf("\n UNFORTUNATELY GAME IS OVER :/");
	}
}

void merge_snake_to_map()
{
	for(int i = 0; i < MAP_HEIGHT; i++)
	{
		for(int j = 0; j < MAP_WIDTH; j++)
		{
			map_and_snake[j][i] = map[j][i];
		}	
	}

	int i = 0;
	while(player[i]->x > 0 && player[i]->y > 0)
	{
		map_and_snake[player[i]->x][player[i]->y] = ascii_snake_code;
		i++;
	}

	if(bait_pos == NULL)// BAIT IS NOT EXIST, so create one
	{
		int counter = 0;
		int valid = 0;
		int i = 0;
		int x_p = 0;
		int y_p = 0;
		do
		{
			valid = 0;
			srand(time(NULL)); 
			x_p = (rand() % ((MAP_WIDTH - 2) + 1 - 2)) +  2; 
			y_p =  (rand() % ((MAP_HEIGHT - 2) + 1 - 2)) +  2; 
			i = 0;
			
			if(map_and_snake[y_p][x_p] == ascii_snake_code)
				valid = -1;
			counter++;
		}while(valid == -1 && counter < 5);

		if(valid != -1)
		{
			bait_pos = vec2_int(x_p, y_p);
			
		}

	}

	if(bait_pos != NULL && game_state == GAME_STATE)
		map_and_snake[bait_pos->x][bait_pos->y] = ascii_bait_code;
}

void hide_cursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void move_snake()
{

	if(player[0]->x < 1 || player[0]->x >= MAP_WIDTH-1)
	{
		game_over_effect();
		return;
	}
	else if(player[0]->y < 1 || player[0]->y >= MAP_HEIGHT-1)
	{
		game_over_effect();
		return;
	}

	VEC2_INT* temp =  vec2_int(0,0);	
	VEC2_INT* temp2 = vec2_int(0,0);	
	int i = 0;
	
	vec2_set_int(temp, player[i]->x, player[i]->y);
	vec2_add_int(player[i], direction);
	i++;
	
	if(map_and_snake[player[0]->x][player[0]->y] == ascii_bait_code)
	{
		ate_bait();
	}else if(map_and_snake[player[0]->x][player[0]->y] == ascii_snake_code)
	{
		game_over_effect();
		return;
	}



	while(player[i]->x > 0 && player[i]->y > 0)
	{
		vec2_set_int(temp2, player[i]->x, player[i]->y);	
		vec2_set_int(player[i], temp->x, temp->y);	
		vec2_set_int(temp, temp2->x, temp2->y);	
		i++;
	}
}

void get_key()
{
    int key, key2 = 0;
    if(!kbhit())
    	return;
    key = getch();

    if (key == 0xE0 || key == 0){
    	key2 = getch();
    	switch(key2)
		{
			case UP:
			if(direction->y == 0)
    			vec2_set_int(direction, 0,-1);
    		break;

    		case DOWN:
    		if(direction->y == 0)
    			vec2_set_int(direction, 0,1);
    		break;

    		case LEFT:
    		if(direction->x == 0)
    			vec2_set_int(direction, -1,0);
    		break;

    		case RIGHT:
    		if(direction->x == 0)
    			vec2_set_int(direction, 1,0);
    		break;
    	}
	}

}

void ate_bait()
{
	VEC2_INT* temp;	
	int i = 0;
	while(player[i]->x > 0 && player[i]->y > 0)
	{
		temp = player[i];
		i++;
	}
	score += 2;
	vec2_set_int(player[i], temp->x, temp->y);
	free(bait_pos);
	bait_pos = NULL;
}

void draw_game_over()
{
	draw_snake_art();
	printf("\n");
	printf("\n");
	printf("\n \t\t\tGAME OVER");
	printf("\n \t\tYOUR SCORE IS %d", score);
	printf("\n \t\tPRESS ENTER TO START NEW GAME");

	 int key;
	 key = getch();

	 if(key == 13)
	 {
	 	game_state = GAME_STATE;
	 	reset_game();
	 }
}

void draw_snake_art()
{
	printf("\n      _                   .-=-.          .-==-.");
	printf("\n     { }      __        .\' O o \'.       /  -<\' )");
	printf("\n     { }    .\' O\'.     / o .-. O \\     /  .--v`");
	printf("\n     { }   / .-. o\\   /O  /   \\  o\\   /O /");
	printf("\n      \\ `-` /   \\ O`-'o  /     \\  O`-`o /");
	printf("\n       `-.-`     '.____.'       `.____.'");
}

void draw_menu()
{
	draw_snake_art();
	printf("\n");
	printf("\n");
	printf("\n \t\tWELCOME TO SNAKE GAME");
	printf("\n \t\tPRESS ENTER TO START GAME");
	printf("\n \t\tPRESS ESC TO QUIT GAME");

	 int key;
	 key = getch();

	 if(key == 13)
	 {
	 	game_state = GAME_STATE;
	 	reset_game();
	 }else if( key == 27)
	 {
	 	game_state = GAME_EXIT_STATE;
	 }
}

void game_over_effect()
{
	game_state = GAME_OVER_STATE;

	int i = 0;
	while(i < 3 )
	{
		draw_game();
		Sleep(600);
		system("cls");
		draw_map();
		printf("\n UNFORTUNATELY GAME IS OVER :/");
		Sleep(200);
		system("cls");
		i++;
	}
}

void draw_map()
{
	printf("\n SCORE : %d", score);

	for(int i = 0; i < MAP_HEIGHT; i++)
	{
		printf("\n");
		for(int j = 0; j < MAP_WIDTH; j++)
		{
			printf("%c",map[j][i]);
		}	
	}


}