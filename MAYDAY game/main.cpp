// Subham Chakraborty :)
#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "User32.lib")
#include <iostream>
#include <SDL.h>
#include <vector>
#include <SDL_ttf.h>
#include <map>
#include <windows.h>
#include <mutex>
#include <algorithm>
using namespace std;
long int seed;
int getmaxx, getmaxy;
SDL_Rect screen;
SDL_Renderer *render;
SDL_Texture *plane, *plane2,*stall0,*stall1,*stall2,*seedtexture;
map<string, pair<SDL_Texture*,pair<int,int>>> text0;
map<string, pair<SDL_Texture*,pair<int, int>>> text1;
string mygawh;
long long int restart = 0, velx=0, scoreness=0,condition=1,condition2=1,delayder;
mutex m;
vector<string> texts = { "START", "SETTINGS","CREDITS","EXIT","BACK","PAUSE","BETA-0.21","MADE BY: Subham Chakraborty (S.Bolt)","ENTER SEED:","SCORE:","ARE YOU SURE?","NO","YES","SEED","PAUSED!","RESUME?","Well Played!" ,"RESTART","SEED:" };
void logik(int speedyy) {
	Uint32 start;
	while (condition) {
		start = SDL_GetTicks();
		if (condition2) {
			m.lock();
			velx -= speedyy;
			scoreness++;
			m.unlock();
		}
		if ((1000.0 / delayder) > (SDL_GetTicks() - start)) {
			SDL_Delay((1000.0 / delayder) - (SDL_GetTicks() - start));
		}
	}
	return;
}
pair<pair<int, int>, pair<int, int>> button(int x, int x1, int y1, string s, int recy) {
	SDL_Rect rect,rect2;
	SDL_Texture* button;
	if (x == 1){
		rect.w = text1[s].second.first + 10;
		rect.h = text1[s].second.second + 10;
		rect.x = x1 - rect.w / 2;
		rect.y = y1 - rect.h / 2;
		rect2.w = text1[s].second.first;
		rect2.h = text1[s].second.second;
		rect2.x = x1 - rect2.w / 2;
		rect2.y = y1 - rect2.h / 2;
		button = text1[s].first;
	}
	else {
		rect.w = text0[s].second.first + 10;
		rect.h = text0[s].second.second + 10;
		rect.x = x1 - rect.w / 2;
		rect.y = y1 - rect.h / 2;
		rect2.w = text0[s].second.first;
		rect2.h = text0[s].second.second;
		rect2.x = x1 - rect2.w / 2;
		rect2.y = y1 - rect2.h / 2;
		button = text0[s].first;
	}
	SDL_SetRenderDrawColor(render, 255,255,255,1);
	if (!recy) {
		SDL_RenderDrawRect(render, &rect);
	}
	SDL_RenderCopy(render, button, NULL, &rect2);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	return make_pair(make_pair(rect.x-1,rect.y-1),make_pair(rect.x+rect.w,rect.y+rect.h));
}
pair<long long int, pair<int, int>> mountains(int x, long long int x1, long long int y1,SDL_Rect holyshit) {
	float z = 0.5 - 0.05 * (x - 1);
	int omg = 0;
	long long int x2 = x1 - (getmaxy - 202 - y1) / 2 + (getmaxy - 202 - z * (getmaxy - 202 - 102) - 102);
	long long int y2 = getmaxy - 202;
	long long int x3 = (x2 + x1 - (getmaxy - 202 - y1) / 2) / 2;
	long long int y3 = (z * (getmaxy - 202 - 102) + 102);
	SDL_RenderDrawLine(render, x1, y1, x3, y3);
	SDL_RenderDrawLine(render, x3, y3, x2, y2);
	if (x1 <= (holyshit.x+holyshit.w) && x2 >= holyshit.x) {
		bool cond1 = ((int)((float)(y3 - y1) / (x3 - x1)) * (holyshit.x + 4 - x1) <= (holyshit.y + 9 - y1)) && (holyshit.x + 4 < x3);
		bool cond2 = ((int)((float)(y3 - y1) / (x3 - x1)) * (holyshit.x + 11 - x1) <= (holyshit.y + 26 - y1)) && (holyshit.x + 11 < x3);
		bool cond3 = ((int)((float)(y3 - y1) / (x3 - x1)) * ((holyshit.x+holyshit.w) - 40 - x1) <= (holyshit.y + 28 - y1)) && ((holyshit.x+holyshit.w) - 40 < x3);
		bool cond4 = ((int)((float)(y3 - y1) / (x3 - x1)) * ((holyshit.x+holyshit.w) - 15 - x1) <= (holyshit.y + 25 - y1)) && ((holyshit.x+holyshit.w) - 15 < x3);
		bool cond5 = ((int)((float)(y3 - y1) / (x3 - x1)) * ((holyshit.x+holyshit.w) - 7 - x1) <= (holyshit.y + 19 - y1)) && ((holyshit.x+holyshit.w) - 7 < x3);
		bool cond6 = ((int)((float)(y3 - y2) / (x3 - x2)) * (holyshit.x + 4 - x2) <= (holyshit.y + 9 - y2)) && (holyshit.x + 4 > x3);
		bool cond7 = ((int)((float)(y3 - y2) / (x3 - x2)) * (holyshit.x + 11 - x2) <= (holyshit.y + 26 - y2)) && (holyshit.x + 11 > x3);
		bool cond8 = ((int)((float)(y3 - y2) / (x3 - x2)) * ((holyshit.x+holyshit.w) - 40 - x2) <= (holyshit.y + 28 - y2)) && ((holyshit.x+holyshit.w) - 40 > x3);
		bool cond9 = ((int)((float)(y3 - y2) / (x3 - x2)) * ((holyshit.x+holyshit.w) - 15 - x2) <= (holyshit.y + 25 - y2)) && ((holyshit.x+holyshit.w) - 15 > x3);
		bool cond10 = ((int)((float)(y3 - y2) / (x3 - x2)) * ((holyshit.x+holyshit.w) - 7 - x2) <= (holyshit.y + 19 - y2)) && ((holyshit.x+holyshit.w) - 7 > x3);
		bool cond11 = ((int)((float)17 / 7) * (x3 - holyshit.x - 4) >= (y3 - holyshit.y - 9)) && (x3 > holyshit.x + 4 && x3 < holyshit.x + 11);
		bool cond12 = ((int)((float)(2) / ((holyshit.x+holyshit.w) - 40 - holyshit.x - 11)) * (x3 - holyshit.x - 11) >= (y3 - holyshit.y - 26)) && (x3 > holyshit.x + 11 && x3 < (holyshit.x+holyshit.w) - 40);
		bool cond13 = ((int)((float)(-3) / 25) * (x3 - (holyshit.x+holyshit.w) + 15) >= (y3 - holyshit.y - 25)) && (x3 > (holyshit.x+holyshit.w) - 40 && x3 < (holyshit.x+holyshit.w) - 15);
		bool cond14 = ((int)((float)(-6) / 8) * (x3 - (holyshit.x+holyshit.w) + 7) >= (y3 - holyshit.y - 19)) && (x3 > (holyshit.x+holyshit.w) - 15 && x3 < (holyshit.x+holyshit.w) - 7);
		omg = cond1 || cond2 || cond3 || cond4 || cond5 || cond6 || cond7 || cond8 || cond9 || cond10 || cond11 || cond12 || cond13 || cond14;
	}
	return make_pair(x2, make_pair((x1 <= getmaxx && x2 >= 0), omg));
}
vector<pair<long long int, pair<long long int, long long int>>> mountaingen(long long int mountaingen) {
	int m = 9;
	vector<pair<long long int, pair<long long int, long long int>>> idk(100000);
	idk[0].first = (((mountaingen) % 10) * ((mountaingen / 100000) % 10) + ((mountaingen / 10) % 10) * ((mountaingen / 1000000) % 10) + ((mountaingen / 100) % 10) * ((mountaingen / 10000000) % 10) + ((mountaingen / 1000) % 10) * ((mountaingen / 100000000) % 10) + ((mountaingen / 10000) % 10) * ((mountaingen / 1000000000) % 10)) % m;
	idk[0].second.first = 0;
	idk[0].second.second = 0;
	long long int k = 1;
	long long int k2 = 1;
	long long int total = 0;
	long long int fuel = 0.001 * total;
	cout << fuel << " " << total << endl;
	vector<long long int> cells(fuel);
	for (int i = 1; i < 100000; i++) {
		for (int j = (i > 100) * (i - 100); j < i; j++) {
			idk[i].first = (idk[i].first + idk[j].first * (j + 1) * (((mountaingen / k) % 10 + j + i) % m) + j + i) % m;
			k *= 10;
			if (k == 10000000000) {
				k = 1;
			} 
		}
		idk[i].first %= m;
		long long int breh = exp(idk[i - 1].first);
		long long int breh2 = (pow((idk[i].first << ((mountaingen) % 10)) / 100, idk[i].first));
		long long int breh3 = (pow((idk[i].first << ((mountaingen / 10) % 10)) / 100, idk[i].first)) * 2;
		long long int breh4 = (pow((idk[i].first << ((mountaingen / 100) % 10)) / 100, idk[i].first)) * 3;
		long long int breh5 = (pow((idk[i].first << ((mountaingen / 1000) % 10)) / 100, idk[i].first)) * 4;
		long long int breh6 = (pow((idk[i].first << ((mountaingen / 10000) % 10)) / 100, idk[i].first)) * 5;
		idk[i].first = (idk[i].first + breh % m + ((breh2 % m) << (mountaingen / 1000000000) % 10) + ((breh3 % m) << (mountaingen / 100000000) % 10) + ((breh4 % m) << (mountaingen / 10000000) % 10) + ((breh5 % m) << (mountaingen / 1000000) % 10) + ((breh6 % m) << (mountaingen / 100000) % 10)) % m;
		idk[i].first++;
		long long int z1 = getmaxy - 202 - (0.5 - 0.05 * (idk[i - 1].first - 1)) * (getmaxy - 202 - 102) - 102;
		long long int z2 = getmaxy - 202 - (0.5 - 0.05 * (idk[i].first - 1)) * (getmaxy - 202 - 102) - 102;
		// getmaxy()-202 to z1-1 or z2-1<- y
		long long int m1 = min(z1, z2);
		for (int j = (i > 100) * (i - 100); j < i; j++) {
			idk[i].second.second = (idk[i].second.second + idk[j].second.second * (j + 1) * (((mountaingen / k2) % 10 + j + i) % m1) + j + i) % m1;
			k2 *= 10;
			if (k2 == 10000000000) {
				k2 = 1;
			}
		}
		idk[i].second.second %= m1;
		idk[i].second.second = (idk[i].second.second + abs(breh) % m1 + ((breh2 % m1) << (mountaingen / 1000000000) % 10) % m1 + ((breh3 % m1) << (mountaingen / 100000000) % 10) % m1 + ((breh4 % m1) << (mountaingen / 10000000) % 10) % m1 + ((breh5 % m1) << (mountaingen / 1000000) % 10) % m1 + ((breh6 % m1) << (mountaingen / 100000) % 10) % m1) % m1;
		idk[i].second.first = (idk[i].second.second) / 2.0;
		total += z2 - idk[i].second.first;
	}
	/*long long int fuel = 0.001 * total;
	cout << fuel << " " << total<<endl;
	vector<long long int> cells(fuel);
	long long int mommy = fuel;
	cells[0] = (((mountaingen) % 10) * ((mountaingen / 100000) % 10) + ((mountaingen / 10) % 10) * ((mountaingen / 1000000) % 10) + ((mountaingen / 100) % 10) * ((mountaingen / 10000000) % 10) + ((mountaingen / 1000) % 10) * ((mountaingen / 100000000) % 10) + ((mountaingen / 10000) % 10) * ((mountaingen / 1000000000) % 10)) % mommy;
	if (cells[0] == 0) {
		cells[0]++;
	}
	int i = 1;
	k = 1;
	m = 10;
	srand(mountaingen);
	cout << RAND_MAX << endl;
	for (long long int jj = 1; jj<fuel; jj++) {
		for (int j = (jj > 100) * (jj - 100); j < jj; j++) {
			cells[jj] = (cells[jj] + (cells[j] * (j + 1) * (((mountaingen / k) % 10 + j + jj) % m))%mommy + j + jj) % mommy;
			k *= 10;
			if (k == 10000000000) {
				k = 1;
			}
		}
		cells[jj] %= mommy;
		long long int breh = exp(idk[i - 1].first);
		long long int breh2 = (pow((idk[i].first << ((mountaingen) % 10)) / 100, idk[i].first));
		long long int breh3 = (pow((idk[i].first << ((mountaingen / 10) % 10)) / 100, idk[i].first)) * 2;
		long long int breh4 = (pow((idk[i].first << ((mountaingen / 100) % 10)) / 100, idk[i].first)) * 3;
		long long int breh5 = (pow((idk[i].first << ((mountaingen / 1000) % 10)) / 100, idk[i].first)) * 4;
		long long int breh6 = (pow((idk[i].first << ((mountaingen / 10000) % 10)) / 100, idk[i].first)) * 5;
		long long int breh7 = (breh2  + ((mountaingen / 1000000000) % 10)) % mommy;
		long long int breh8 = ((breh3  << (mountaingen / 100000000) % 10)) % mommy;
		long long int breh9 = (((breh4) << (mountaingen / 10000000) % 10)) % mommy;
		long long int breh10 = (((breh5)  << (mountaingen / 1000000) % 10)) % mommy;
		long long int breh11 = (((breh6) << (mountaingen / 100000) % 10)) % mommy;
		cout << breh<<" " << breh2 << " " <<breh3 << " "<<breh4<<" "<<breh6 << endl;
		cells[jj] = (cells[jj] + breh % mommy + breh7+ breh8 + breh9 + breh10 + breh11) % mommy;
		i++;
	    if (i == 100000) {
			i = 1;
		}
	}*/
	sort(cells.begin(), cells.end());
	for (long long int jj = 1; jj < fuel; jj++) {
		if (cells[jj - 1] + 15 > cells[jj]) {
			cells[jj] = cells[jj - 1] + 15;
		}
	}
	for (long long int jj = 0; jj < fuel; jj++) {
		cout << cells[jj]<< " ";
	}
	return idk;
}
long long int sady() {
	SDL_RenderClear(render);
	bool quit = false;
	SDL_Event e;
	SDL_Color textColor = { 255, 255, 255, 1 };
	string text="";
	srand(time(0));
	long long int x=0;
	while (text.size() < 10) {
		long long int seedint = rand();
		if (seedint < 0) {
			seedint *= -1;
		}
		while (seedint && text.size() < 10) {
			text += char(48 + (seedint % 10));
			x = x * 10 + (seedint % 10);
			seedint /= 10;
		}
	}
	TTF_Font* font = TTF_OpenFont("font/COPRGTL.TTF", 30);
	SDL_Color txtcolor = { 255,255,255};
	SDL_Surface *temp;
	SDL_Rect idk,idk2,idk3;
	bool cond1, cond2;
	int xx, yy,bruh,curr=0;
	idk.x = getmaxx/2 - 110;
	idk.y = getmaxy / 2 -20;
	idk2.x = getmaxx / 2 - 115;
	idk2.y = getmaxy / 2-15;
	idk2.w = 225;
	idk2.h = 30;
	idk3.x = getmaxx / 2 - 200;
	idk3.y = getmaxy / 2 - 200;
	idk3.w = 400;
	idk3.h = 400;
	SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
	SDL_RenderDrawRect(render, &idk2);
	SDL_RenderDrawRect(render, &idk3);
	SDL_SetRenderDrawColor(render, 0,0,0,0);
	button(1, getmaxx / 2, getmaxy / 2 - 50,"ENTER SEED:",1);
	pair<pair<int, int>, pair<int, int>> but1 = button(0, getmaxx / 2-70, getmaxy / 2 +80, "BACK", 0);
	pair<pair<int, int>, pair<int, int>> but2 = button(0, getmaxx / 2 + 65, getmaxy / 2 + 80, "START", 0);
	SDL_RenderPresent(render);
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = 1;
			}
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_BACKSPACE && text.size() > 0) {
					text.pop_back();
					x /= 10;
				}
				else if (e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
				{
					SDL_SetClipboardText(text.c_str());
				}
				else if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
				{
					char* tempText = SDL_GetClipboardText();
					text = tempText;
					SDL_free(tempText);
					x = 0;
					for (int i = 0; i < text.size(); i++) {
						x = x * 10 + (text[i]-'0');
					}
				}
				else if (text.size()<10){
					for (int i = 0; i < 10; i++) {
						if (e.key.keysym.sym == 48 + i) {
							text += char(48 + i);
							x =x*10+ i;
						}
					}
				}
			}
			bruh = SDL_GetMouseState(&xx, &yy);
			cond1 = xx > but1.first.first && xx<but1.second.first && yy>but1.first.second && yy < but1.second.second;
			cond2 = xx > but2.first.first && xx<but2.second.first && yy>but2.first.second && yy < but2.second.second;
			SDL_RenderClear(render);
			SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
			SDL_RenderDrawRect(render, &idk2);
			SDL_RenderDrawRect(render, &idk3);
			if (cond1) {
				but1 = button(1, getmaxx / 2 - 70, getmaxy / 2 + 80, "BACK", 0);
				but2 = button(0, getmaxx / 2 + 65, getmaxy / 2 + 80, "START", 0);
				curr = 1;
			}
			else if (cond2) {
				but1 = button(0, getmaxx / 2 - 70, getmaxy / 2 + 80, "BACK", 0);
				but2 = button(1, getmaxx / 2 + 65, getmaxy / 2 + 80, "START", 0);
				curr = 2;
			}
			else {
				but1 = button(0, getmaxx / 2 - 70, getmaxy / 2 + 80, "BACK", 0);
				but2 = button(0, getmaxx / 2 + 65, getmaxy / 2 + 80, "START", 0);
				curr = 0;
			}
			button(1, getmaxx / 2, getmaxy / 2 - 100, "ENTER SEED:", 1);
			SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
			if (text != "") {
				char* ik = &text[0];
				temp = TTF_RenderText_Solid(font, ik, txtcolor);
				seedtexture = SDL_CreateTextureFromSurface(render, temp);
				idk.w = temp->w;
				idk.h = temp->h;
				SDL_RenderCopy(render, seedtexture, NULL, &idk);
			}
			if (curr == 1 && (bruh & SDL_BUTTON_LMASK)) {
				return -1;
			}
			else if (curr == 2 && (bruh & SDL_BUTTON_LMASK)) {
				quit = 1;
			}
			SDL_RenderPresent(render);
		}
	}
	mygawh = text;
	return x;
}
int stall(double x,int yo) {
	if (x < 0) {
		return 1;
	}
	if (x > 100) {
		x = 100;
	}
	SDL_Rect rect1;
	rect1.x = 50;
	rect1.y = getmaxy - 150;
	rect1.w = getmaxx - 350;
	rect1.h = 50;
	SDL_SetRenderDrawColor(render, 255,255,255,1);
	SDL_RenderDrawRect(render, &rect1);
	if (yo == 2) {
		SDL_SetRenderDrawColor(render, 255, 0, 0, 1);
	}
	else if (yo == 1) {
		SDL_SetRenderDrawColor(render, 0, 0, 255, 1);
	}
	else {
		SDL_SetRenderDrawColor(render, 0, 255, 255, 1);
	}
	double e = (rect1.w)*x / 100.0;
	rect1.x++;
	rect1.y++;
	rect1.h-=2;
	rect1.w = (int)e;
	rect1.w--;
	SDL_RenderFillRect(render, &rect1);
	SDL_SetRenderDrawColor(render,0,0,0,0);
	return 0;
}
int getout() {
	SDL_Rect r1,recty;
	r1.x = getmaxx / 2 - 200;
	r1.y = getmaxy / 2 - 200;
	r1.w = 400;
	r1.h = 300;
	recty.x = getmaxx / 2 - 100;
	recty.y = getmaxy / 2 - 50;
	recty.w = 200;
	recty.h = 50;
	SDL_SetRenderDrawColor(render, 0,0,0,0);
	SDL_RenderFillRect(render, &r1);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
	SDL_RenderDrawRect(render, &r1);
	button(1, getmaxx / 2, getmaxy / 2 - 150, "ARE YOU SURE?", 1);
	pair<pair<int, int>, pair<int, int>> but1 = button(0, getmaxx / 2+50, getmaxy / 2 + 50, "NO", 0);
	pair<pair<int, int>, pair<int, int>> but2 = button(0, getmaxx / 2-50, getmaxy / 2 + 50, "YES", 0);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderPresent(render);
	bool quit = false,cond1,cond2;
	SDL_Event e;
	int xx, yy,bruh,curr=0;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type = SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
				{
					SDL_SetClipboardText(mygawh.c_str());
				}
			}
		}
		SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
		SDL_RenderFillRect(render, &r1);
		SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
		SDL_RenderDrawRect(render, &r1);
		button(0, getmaxx / 2, getmaxy / 2 - 70, "SEED", 1);
		SDL_RenderCopy(render, seedtexture, NULL, &recty);
		button(1, getmaxx / 2, getmaxy / 2 - 150, "ARE YOU SURE?", 1);
		bruh = SDL_GetMouseState(&xx, &yy);
		cond1 = xx > but1.first.first && xx<but1.second.first && yy>but1.first.second && yy < but1.second.second;
		cond2 = xx > but2.first.first && xx<but2.second.first && yy>but2.first.second && yy < but2.second.second;
		if (cond1) {
			button(1, getmaxx / 2 + 50, getmaxy / 2 + 50, "NO", 0);
		    button(0, getmaxx / 2 - 50, getmaxy / 2 + 50, "YES", 0);
			curr = 1;
		}
		else if (cond2) {
			button(0, getmaxx / 2 + 50, getmaxy / 2 + 50, "NO", 0);
			button(1, getmaxx / 2 - 50, getmaxy / 2 + 50, "YES", 0);
			curr = 2;
		}
		else {
			button(0, getmaxx / 2 + 50, getmaxy / 2 + 50, "NO", 0);
			button(0, getmaxx / 2 - 50, getmaxy / 2 + 50, "YES", 0);
			curr = 0;
		}
		if (bruh & SDL_BUTTON_LMASK) {
			if (cond1) {
				return 0;
			}
			else if (cond2) {
				return 1;
			}
		}
		SDL_RenderPresent(render);
	}
	return 0;
}
int pause() {
	SDL_Rect r1, recty;
	r1.x = getmaxx / 2 - 200;
	r1.y = getmaxy / 2 - 200;
	r1.w = 400;
	r1.h = 300;
	recty.x = getmaxx / 2 - 100;
	recty.y = getmaxy / 2 - 50;
	recty.w = 200;
	recty.h = 50;
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderFillRect(render, &r1);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
	SDL_RenderDrawRect(render, &r1);
	button(1, getmaxx / 2, getmaxy / 2 - 150, "PAUSED!", 1);
	pair<pair<int, int>, pair<int, int>> but1 = button(0, getmaxx / 2 , getmaxy / 2 + 50, "RESUME?", 0);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderPresent(render);
	bool quit = false, cond1, cond2;
	SDL_Event e;
	int xx, yy, bruh, curr = 0;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type = SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
				{
					SDL_SetClipboardText(mygawh.c_str());
				}
			}
		}
		SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
		SDL_RenderFillRect(render, &r1);
		SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
		SDL_RenderDrawRect(render, &r1);
		button(0, getmaxx / 2, getmaxy / 2 - 70, "SEED", 1);
		SDL_RenderCopy(render, seedtexture, NULL, &recty);
		button(1, getmaxx / 2, getmaxy / 2 - 150, "PAUSED!", 1);
		bruh = SDL_GetMouseState(&xx, &yy);
		cond1 = xx > but1.first.first && xx<but1.second.first && yy>but1.first.second && yy < but1.second.second;
		if (cond1) {
			button(1, getmaxx / 2 , getmaxy / 2 + 50, "RESUME?", 0);
			curr = 1;
		}
		else {
			button(0, getmaxx / 2 , getmaxy / 2 + 50, "RESUME?", 0);
			curr = 0;
		}
		if (bruh & SDL_BUTTON_LMASK) {
			if (cond1) {
				return 0;
			}
		}
		SDL_RenderPresent(render);
	}
	return 0;
}
int lost(SDL_Texture* temp2,int w) {
	SDL_Rect r1, recty,r2;
	r1.x = getmaxx / 2 - 200;
	r1.y = getmaxy / 2 - 300;
	r1.w = 400;
	r1.h = 400;
	recty.x = getmaxx / 2 - 50;
	recty.y = getmaxy / 2 - 50;
	recty.w = 200;
	recty.h = 30;
	r2.x = getmaxx / 2;
	r2.y = getmaxy / 2 - 150;
	r2.w = w;
	r2.h = 30;
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderFillRect(render, &r1);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
	SDL_RenderDrawRect(render, &r1);
	button(1, getmaxx / 2, getmaxy / 2 - 250, "Well Played!", 1);
	button(0, getmaxx / 2-75, getmaxy / 2 - 137, "SCORE:", 1);
	SDL_RenderCopy(render, temp2, NULL, &r2);
	pair<pair<int, int>, pair<int, int>> but1 = button(0, getmaxx / 2 + 50, getmaxy / 2 + 50, "BACK", 0);
	pair<pair<int, int>, pair<int, int>> but2 = button(0, getmaxx / 2 - 100, getmaxy / 2 + 50, "RESTART", 0);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	SDL_RenderPresent(render);
	bool quit = false, cond1, cond2;
	SDL_Event e;
	int xx, yy, bruh, curr = 0;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type = SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
				{
					SDL_SetClipboardText(mygawh.c_str());
				}
			}
		}
		SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
		SDL_RenderFillRect(render, &r1);
		SDL_SetRenderDrawColor(render, 255, 255, 255, 1);
		SDL_RenderDrawRect(render, &r1);
		button(0, getmaxx / 2-100, getmaxy / 2 - 37, "SEED:", 1);
		SDL_RenderCopy(render, seedtexture, NULL, &recty);
		button(1, getmaxx / 2, getmaxy / 2 - 250, "Well Played!", 1);
		button(0, getmaxx / 2 - 75, getmaxy / 2 - 137, "SCORE:", 1);
		SDL_RenderCopy(render, temp2, NULL, &r2);
		bruh = SDL_GetMouseState(&xx, &yy);
		cond1 = xx > but1.first.first && xx<but1.second.first && yy>but1.first.second && yy < but1.second.second;
		cond2 = xx > but2.first.first && xx<but2.second.first && yy>but2.first.second && yy < but2.second.second;
		if (cond1) {
			button(1, getmaxx / 2 + 75, getmaxy / 2 + 50, "BACK", 0);
			button(0, getmaxx / 2 - 75, getmaxy / 2 + 50, "RESTART", 0);
			curr = 1;
		}
		else if (cond2) {
			button(0, getmaxx / 2 + 75, getmaxy / 2 + 50, "BACK", 0);
			button(1, getmaxx / 2 - 75, getmaxy / 2 + 50, "RESTART", 0);
			curr = 2;
		}
		else {
			button(0, getmaxx / 2 + 75, getmaxy / 2 + 50, "BACK", 0);
			button(0, getmaxx / 2 - 75, getmaxy / 2 + 50, "RESTART", 0);
			curr = 0;
		}
		if (bruh & SDL_BUTTON_LMASK) {
			if (cond1) {
				return 0;
			}
			else if (cond2) {
				return 1;
			}
		}
		SDL_RenderPresent(render);
	}
	return 0;
	return 0;
}
int game() {
	long long int x = 0;
	if (restart==0) {
		x = sady();
		if (x == -1) {
			restart = false;
			return 0;
		}
	}
	else {
		x = restart;
	}
	SDL_RenderClear(render);
	vector<pair<long long int, pair<long long int, long long int>>> mountainsv = mountaingen(x);
	velx = getmaxx / 2;
	condition = 1;
	condition2 = 1;
	scoreness = 0;
	delayder = 60;
	bool quit = false, cond1, cond2,fkoff=false;
	SDL_Event e;
	SDL_Rect rect2,rect3,idky;
	rect2.x = 50;
	rect2.y = getmaxy / 2;
	rect2.w = 100;
	rect2.h = 50;
	rect3.x = getmaxx - 250;
	rect3.y = getmaxy - 150;
	rect3.w = 200;
	rect3.h = 50;
	int idk = getmaxy;
	long long int bruh = getmaxx/2, terima, storer;
	storer = bruh;
	TTF_Font* font = TTF_OpenFont("font/COPRGTL.TTF", 30);
	SDL_Color txtcolor = { 255,255,255 };
	SDL_Surface* temp;
	SDL_Texture* temp2;
	idky.x = getmaxx/2 + 60;
	idky.y = 35;
	int curr = 0, curr2 = 0, l = 0, r = 9, over = 0, speed = 6, flagged = 0,score = 0, xx,yy,prev=0,delay=10,fps=60;
	double stally = 50,tempy;
	pair<long long int, pair<int, int>> saxy;
	char kkkk[1000];
	sprintf(kkkk, "%ld", score / 100);
	pair<pair<int, int>, pair<int, int>> but1 = button(0, 100, 50, "BACK", 0);
	pair<pair<int, int>, pair<int, int>> but2 = button(0, getmaxx - 100, 50, "PAUSE", 0);
	SDL_RenderPresent(render);
	temp = TTF_RenderText_Solid(font, kkkk, txtcolor);
	temp2 = SDL_CreateTextureFromSurface(render, temp);
	Uint32 start;
	thread t1(logik, speed);
	while (quit == false) {
		score = scoreness;
		start = SDL_GetTicks();
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
				quit = true;
			}
		}
		curr2 = SDL_GetMouseState(&xx, &yy);
		cond1 = xx > but1.first.first && xx<but1.second.first && yy>but1.first.second && yy < but1.second.second;
		cond2 = xx > but2.first.first && xx<but2.second.first && yy>but2.first.second && yy < but2.second.second;
		if (GetAsyncKeyState(87) && rect2.y >103) {
			rect2.y -= speed+(delayder - 50)/20.0 - 1;
		}
		if (GetAsyncKeyState(83) && rect2.y + rect2.h < getmaxy - 203) {
			rect2.y += speed + (delayder-50)/20.0 - 1;
		}
		tempy = (0.070 * (rect2.y + 19 < (0.1 * (getmaxy - 202 - 102) + 102)) + 0.030 * (rect2.y + 19 <= (0.25 * (getmaxy - 202 - 102) + 102)) - 0.010);
		stally -=tempy;
		if (stally > 100) {
			stally = 100;
		}
		SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
		SDL_RenderClear(render);
		if (cond1) {
			button(1, 100, 50, "BACK", 0);
			button(0, getmaxx - 100, 50, "PAUSE", 0);
			curr = 1;
		}
		else if (cond2) {
			button(0, 100, 50, "BACK", 0);
			button(1, getmaxx - 100, 50, "PAUSE", 0);
			curr = 2;
		}
		else {
			button(0, 100, 50, "BACK", 0);
			button(0, getmaxx - 100, 50, "PAUSE", 0);
			curr = 0;
		}
		button(0, getmaxx / 2, 50, "SCORE:", 1);
		//if (score % 10 == 0) {
		char ik[1000];
		sprintf(ik, "%ld", scoreness / 6);
		temp = TTF_RenderText_Solid(font, ik, txtcolor);
		temp2 = SDL_CreateTextureFromSurface(render, temp);
		idky.w = temp->w;
		idky.h = temp->h;
		//}
		stall(stally,(tempy>=0.049) + (tempy>0.009));
		SDL_RenderCopy(render, temp2, NULL, &idky);
		SDL_SetRenderDrawColor(render, 255,255,255,1);
		SDL_RenderCopy(render, plane2, NULL, &rect2);
		SDL_RenderCopy(render, stall0, NULL, &rect3);
		SDL_RenderDrawLine(render, 0, 100, getmaxx, 100);
		SDL_RenderDrawLine(render, 0, getmaxy-200, getmaxx, getmaxy-200);
		SDL_SetRenderDrawColor(render, 255, 0, 255, 1);
		/*bruh -= speed;*/
		terima = velx;
		flagged = 0;
		for (int i = l; i < r; i++) {
			saxy = mountains(mountainsv[i].first, terima - mountainsv[i].second.first, getmaxy - 202 - mountainsv[i].second.second,rect2);
			terima = saxy.first;
			if (saxy.second.first == 0 && i == l) {
				flagged = 1;
				storer = terima;
			}
			if (!over) {
				over = (saxy.second.second == 1);
			}
		}
		if (curr2 & SDL_BUTTON_LMASK) {
			if (curr == 1) {
				m.lock();
				condition2 = 0;
				m.unlock();
				fkoff = getout();
				if (fkoff) {
					SDL_Delay(500);
					break;
					quit = 1;
				}
				m.lock();
				condition2 = 1;
				m.unlock();
			}
			else if (curr == 2) {
				m.lock();
				condition2 = 0;
				m.unlock();
				pause();
				m.lock();
				condition2 = 1;
				m.unlock();
			}
		}
		SDL_RenderPresent(render);
		SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
		if (over || stally <= 0.00) {
			fkoff = lost(temp2,idky.w);
			if (fkoff) {
				if (x!=0) {
					restart = x;
				}
				m.lock();
				condition = 0;
				m.unlock();
				t1.join();
				return 1;
			}
			else {
				restart = 0;
			}
			break;
		}
		r += (saxy.second.first == 1);
		l += (flagged == 1);
		velx += ((storer - velx) * (flagged == 1));
		//score++;
		if ((r % 10 == 0) && (fps < 200) && (delayder<400) && (r != prev)) {
			prev = r;
			delay--;
			fps++;
			m.lock();
			delayder++;
			m.unlock();
		}
		if ((1000.0/ fps) > (SDL_GetTicks() - start)) {
			SDL_Delay((int)((1000.0/ fps) - (SDL_GetTicks() - start)));
		}
		//SDL_Delay(delay);
	}
	m.lock();
	condition = 0;
	m.unlock();
	t1.join();
	return 0;
}
int setting() {
	return 0;
}
int credit() {
	SDL_Rect rect;
	rect.x = getmaxx / 2 - 300;
	rect.y = getmaxy / 2 - 400;
	rect.w = 600;
	rect.h = 380;
	SDL_RenderCopy(render, plane, NULL, &rect);
	button(1, getmaxx / 2, getmaxy / 2+30, "MADE BY: Subham Chakraborty (S.Bolt)", 1);
	pair<pair<int, int>, pair<int, int>> but1 = button(0, getmaxx / 2, getmaxy / 2+100, "BACK", 0);
	bool quit = false,cond1;
	SDL_Event e;
	int bruh, xx, yy,curr=0;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
				quit = true;
			}
		}
		SDL_RenderClear(render);
		bruh = SDL_GetMouseState(&xx, &yy);
		SDL_RenderCopy(render, plane, NULL, &rect);
		button(1, getmaxx / 2, getmaxy / 2 + 30, "MADE BY: Subham Chakraborty (S.Bolt)", 1);
		cond1 = xx > but1.first.first && xx<but1.second.first && yy>but1.first.second && yy < but1.second.second;
		if (cond1) {
			button(1, getmaxx / 2, getmaxy / 2 + 100, "BACK", 0);
			curr = 1;
		}
		else {
			button(0, getmaxx / 2, getmaxy / 2 + 100, "BACK", 0);
			curr = 0;
		}
		if (bruh & SDL_BUTTON_LMASK) {
			if (cond1) {
				return 0;
			}
		}
		SDL_RenderPresent(render);
	}


	return 0;
}
int menu() {
	SDL_Rect rect;
	rect.x = getmaxx / 2 - 300;
	rect.y = getmaxy / 2 - 400;
	rect.w = 600;
	rect.h = 380;
	SDL_RenderCopy(render, plane, NULL, &rect);
	pair<pair<int,int>,pair<int,int>> start = button(0, getmaxx / 2, getmaxy / 2+25, "START",0);
	pair<pair<int, int>, pair<int, int>> settings = button(0, getmaxx/2, getmaxy/2 +85, "SETTINGS", 0);
	pair<pair<int, int>, pair<int, int>> credits = button(0, getmaxx / 2, getmaxy / 2 + 150, "CREDITS", 0);
	pair<pair<int, int>, pair<int, int>> exity = button(0, getmaxx / 2, getmaxy / 2 + 215, "EXIT", 0);
	button(0, 100, getmaxy-50, "BETA-0.21",1);
	SDL_RenderPresent(render);
	bool quit = 0;
	SDL_Event e;
	int x, y,curr=0,bruh;
	bool cond1, cond2, cond3, cond4;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = 1;
			}
		}
		bruh = SDL_GetMouseState(&x, &y);
		cond1 = x > start.first.first && x<start.second.first && y>start.first.second && y < start.second.second;
		cond2 = x > settings.first.first && x<settings.second.first && y>settings.first.second && y < settings.second.second;
		cond3 = x > credits.first.first && x<credits.second.first && y>credits.first.second && y < credits.second.second;
		cond4 = x > exity.first.first && x<exity.second.first && y>exity.first.second && y < exity.second.second;
		SDL_RenderClear(render);
		if (cond1) {
			SDL_RenderCopy(render, plane, NULL, &rect);
			pair<pair<int, int>, pair<int, int>> start = button(1, getmaxx / 2, getmaxy / 2 + 25, "START", 0);
			pair<pair<int, int>, pair<int, int>> settings = button(0, getmaxx / 2, getmaxy / 2 + 85, "SETTINGS", 0);
			pair<pair<int, int>, pair<int, int>> credits = button(0, getmaxx / 2, getmaxy / 2 + 150, "CREDITS", 0);
			pair<pair<int, int>, pair<int, int>> exity = button(0, getmaxx / 2, getmaxy / 2 + 215, "EXIT", 0);
			button(0, 80, getmaxy - 50, "BETA-0.21", 1);
			curr = 1;
		}
		else if (cond2) {
			SDL_RenderCopy(render, plane, NULL, &rect);
			pair<pair<int, int>, pair<int, int>> start = button(0, getmaxx / 2, getmaxy / 2 + 25, "START", 0);
			pair<pair<int, int>, pair<int, int>> settings = button(1, getmaxx / 2, getmaxy / 2 + 85, "SETTINGS", 0);
			pair<pair<int, int>, pair<int, int>> credits = button(0, getmaxx / 2, getmaxy / 2 + 150, "CREDITS", 0);
			pair<pair<int, int>, pair<int, int>> exity = button(0, getmaxx / 2, getmaxy / 2 + 215, "EXIT", 0);
			button(0, 80, getmaxy - 50, "BETA-0.21", 1);
			curr = 2;
		}
		else if (cond3) {
			SDL_RenderCopy(render, plane, NULL, &rect);
			pair<pair<int, int>, pair<int, int>> start = button(0, getmaxx / 2, getmaxy / 2 + 25, "START", 0);
			pair<pair<int, int>, pair<int, int>> settings = button(0, getmaxx / 2, getmaxy / 2 + 85, "SETTINGS", 0);
			pair<pair<int, int>, pair<int, int>> credits = button(1, getmaxx / 2, getmaxy / 2 + 150, "CREDITS", 0);
			pair<pair<int, int>, pair<int, int>> exity = button(0, getmaxx / 2, getmaxy / 2 + 215, "EXIT", 0);
			button(0, 80, getmaxy - 50, "BETA-0.21", 1);
			curr = 3;
		}
		else if (cond4) {
			SDL_RenderCopy(render, plane, NULL, &rect);
			pair<pair<int, int>, pair<int, int>> start = button(0, getmaxx / 2, getmaxy / 2 + 25, "START", 0);
			pair<pair<int, int>, pair<int, int>> settings = button(0, getmaxx / 2, getmaxy / 2 + 85, "SETTINGS", 0);
			pair<pair<int, int>, pair<int, int>> credits = button(0, getmaxx / 2, getmaxy / 2 + 150, "CREDITS", 0);
			pair<pair<int, int>, pair<int, int>> exity = button(1, getmaxx / 2, getmaxy / 2 + 215, "EXIT", 0);
			button(0, 80, getmaxy - 50, "BETA-0.21", 1);
			curr = 4;
		}
		else {
			SDL_RenderCopy(render, plane, NULL, &rect);
			pair<pair<int, int>, pair<int, int>> start = button(0, getmaxx / 2, getmaxy / 2 + 25, "START", 0);
			pair<pair<int, int>, pair<int, int>> settings = button(0, getmaxx / 2, getmaxy / 2 + 85, "SETTINGS", 0);
			pair<pair<int, int>, pair<int, int>> credits = button(0, getmaxx / 2, getmaxy / 2 + 150, "CREDITS", 0);
			pair<pair<int, int>, pair<int, int>> exity = button(0, getmaxx / 2, getmaxy / 2 + 215, "EXIT", 0);
			button(0, 80, getmaxy - 50, "BETA-0.21", 1);
			curr = 0;
		}
		if (curr == 1 && (bruh & SDL_BUTTON_LMASK)) {
			int seriosly = game();
			while (seriosly) {
				seriosly = game();
			}
		}
		else if (curr==2 && (bruh & SDL_BUTTON_LMASK)) {
			setting();
		}
		else if (curr == 3 && (bruh & SDL_BUTTON_LMASK)) {
			credit();
		}
		else if (curr == 4 && (bruh & SDL_BUTTON_LMASK)) {
			quit = 1;
		}
		SDL_RenderPresent(render);
	}
	return 1;
}
int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);
	getmaxx = dm.w;
	getmaxy = dm.h;
	screen.x = 0;
	screen.y = 0;
	screen.w = getmaxx;
	screen.h = getmaxy;
	velx = getmaxx / 2;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	//render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* temp;
	temp = SDL_LoadBMP("images/plane.bmp");
	plane = SDL_CreateTextureFromSurface(render, temp);
	temp = SDL_LoadBMP("images/plane2.bmp");
	plane2 = SDL_CreateTextureFromSurface(render, temp);
	temp = SDL_LoadBMP("images/stall-0.bmp");
	stall0 = SDL_CreateTextureFromSurface(render, temp);
	/*temp = SDL_LoadBMP("images/stall-1.bmp");
	stall1 = SDL_CreateTextureFromSurface(render, temp);
	temp = SDL_LoadBMP("images/stall-2.bmp");
	stall2 = SDL_CreateTextureFromSurface(render, temp);*/
	TTF_Font* font = TTF_OpenFont("font/COPRGTL.TTF", 30);
	TTF_Font* font2 = TTF_OpenFont("font/COPRGTB.TTF", 31);
	SDL_Color txtcolor = { 255,255,255 };
	for (auto i : texts) {
		char* idk = &i[0];
		temp = TTF_RenderText_Solid(font, idk, txtcolor);
		text0[i].first = SDL_CreateTextureFromSurface(render, temp);
		text0[i].second.first = temp->w;
		text0[i].second.second = temp->h;
		temp = TTF_RenderText_Solid(font2, idk, txtcolor);
		text1[i].first = SDL_CreateTextureFromSurface(render, temp);
		text1[i].second.first = temp->w;
		text1[i].second.second = temp->h;
	}
	menu();
	// closing
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(plane);
	SDL_DestroyTexture(plane2);
	SDL_DestroyTexture(stall0);
	SDL_DestroyTexture(stall1);
	SDL_DestroyTexture(stall2);
	for (auto i : text0) {
		SDL_DestroyTexture(i.second.first);
		text0[i.first].first = NULL;
	}
	for (auto i : text1) {
		SDL_DestroyTexture(i.second.first);
		text1[i.first].first = NULL;
	}
	TTF_CloseFont(font);
	TTF_CloseFont(font2);
	SDL_FreeSurface(temp);
	window = NULL;
	render = NULL;
	plane = NULL;
	plane2 = NULL;
	stall0 = NULL;
	temp = NULL;
	TTF_Quit();
	SDL_Quit();
	return 0;
}