#pragma once
#include"Novice.h"
static void Q(int a,int b,int c,int d,int e,int f,int tex) {
	Novice::DrawQuad(a, b, a + c, b, a, b + d, a + c, b + d, 0, 0, e, f, tex, WHITE);
}

static void QE(int a, int b, int c, int d, int e, int f, int g, int tex) {
	Novice::DrawQuad(a, b, a + c, b, a, b + d, a + c, b + d, e, 0, f, g, tex, WHITE);
}