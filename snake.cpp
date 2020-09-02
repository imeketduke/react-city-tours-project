#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;
int width = 40;
int height = 20;
int x, y, tamaqX, tamaqY, score;
int tailX[500], tailY[50];
int numberTail=0;
enum allDirections { STOP = 0 , LEFT, RIGHT, UP, DOWN };
allDirections dir;

void Main(){
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	tamaqX = rand() % width;
	tamaqY = rand() % height;
	score = 0;
}
void Kartina(){
	system("cls");
	for(int i=0; i<width+1; i++){
		cout<<"a";
	}
	cout<<endl;
	
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(j==0 || j==width-1){
				cout<<"a";
			}
			if(i==y && j==x){
				cout<<"O";
			}
			else if(i==tamaqY && j==tamaqX){
				cout<<"T";
			}
			else{
				bool print = false;
				for(int k = 0; k<numberTail; k++){
					if(tailX[k]==j && tailY[k] == i){
						cout<<"o";
						print = true;
					}
				} 
				if(!print){
					cout<<" ";
				}
			}
			
		}
		cout<<endl;
	}
	
	for(int i=0; i<width+1; i++){
		cout<<"a";
	}
	cout<<endl;
	cout<<"\n\n\n\n\ Score: "<< score<<endl;
}
void Input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
		}
	}
}
void Logic(){
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i=1; i<numberTail; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
		if(dir==LEFT) x--;
		else if(dir==RIGHT) x++;
		else if(dir==UP) y--;
		else if(dir==DOWN) y++;

	if(x>width || x<0 || y>height || y<0){
		gameOver = true;	
	}
	for(int i=0; i<numberTail; i++){
		if(tailX[i] == x && tailY[i]==y){
			gameOver = true;
		}
	}
	if(x == tamaqX && y==tamaqY){
		score++;
		tamaqX = rand() % width;
		tamaqY = rand() % height;
		numberTail++;
	}
}
int main(){
	Main();
	while(!gameOver){
		Kartina();
		Input();
		Logic();
	}
	return 0;
}
