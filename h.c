#include <math.h>
#include <time.h>
#include <stdio.h>
#include "raylib.h"

#define W 700
#define H 400
#define N 13

typedef struct{
	float x,y,r,vx,vy;
	Color color;
}P;

typedef struct{
	float dw,dh;
}O;

P p[N];

O o[N];

//------------------------------------------functions----------------------
void A(P *p,O *o)
{
	p->x += p->vx;
	p->y += p->vy;

	float x = p->x;
	float y = p->y;
	float r = p->r;
	float dw = o->dw;
	float dh = o->dh;

	if (x-r<0)
	{
		p->x = r;
		p->vx = -p->vx;
	}

	if (x+r>dw)
	{
		p->x = dw-r;
		p->vx = -p->vx;
	}

	if (y-r<0)
	{
		p->y = r;
		p->vy = -p->vy;
	}

	if (y+r>dh)
	{
		p->y = dh-r;
		p->vy = -p->vy;
	}
}

void B(P *p)
{
	DrawCircle(p->x,p->y,p->r,p->color);
}

void C()
{
	for (int i = 0; i<N; ++i)
	{
		A(p+i,o+i);
	}
}

void D()
{
	for (int i = 0; i<N; ++i)
	{
		B(p+i);
	}
}

void Initparticle()
{
	SetRandomSeed(time(NULL));

	float radius;

	for (int i = 0; i<N; ++i)
	{
		radius = GetRandomValue(45,50);
		p[i].r = radius;
		p[i].x = GetRandomValue(radius,W-radius);
		p[i].y = GetRandomValue(radius,H-radius);
		p[i].vx = GetRandomValue(-5,5);
		p[i].vy = GetRandomValue(-5,5);
		p[i].color = RED;
	}
}

void screen()
{
	for (int i = 0; i<N; ++i)
	{
		o[i].dw = GetScreenWidth();
		o[i].dh = GetScreenHeight();
	}
}

//-----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//--------------------------------------------------------
void logic()
{
	P p1;
	P p2;

	for (int i = 0; i<N; i++)
	{
		for (int j = i+1; j<N; j++)
		{
			if (j==i)
				break;

			p1 = p[i];
			p2 = p[j];

			Vector2 c1 = {p1.x,p1.y};
			Vector2 c2 = {p2.x,p2.y};

			bool collide = CheckCollisionCircles(c1,p1.r,c2,p2.r);

			if (collide)
			{
				float dx = (p1.x - p2.x);
				float dy = (p1.y - p2.y);

				float abs_d = sqrt(pow(dx,2) + pow(dy,2));

				float nx = dx/abs_d;
				float ny = dy/abs_d;

				float overlap = p2.r + p1.r - abs_d;
				p[i].x += nx *overlap/2;
				p[i].y += ny * overlap/2;
				p[i].x += -ny * overlap/2;
				p[j].y += -ny *overlap/2;
			}
		}
	}
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//-------------------------------------------End of function---------------

//------------------------------------function for raylib------------------

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	SetTargetFPS(60);

	InitWindow(W,H,"kagura");

	Initparticle();

	while(!WindowShouldClose())
	{
		screen();
		BeginDrawing();
		ClearBackground(BLACK);
		     //----
		     logic();
//		     DrawCircle(W/2,H/2,45,YELLOW);
		     C();
		     D();


		     //---
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
