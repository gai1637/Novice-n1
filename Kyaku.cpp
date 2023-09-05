#include "Kyaku.h"
#include"Novice.h"
Kyaku::Kyaku(bool a,int b) {
	pos = { 1280,0 };
	tenbai = a;

}
void Kyaku::Run() {
	if (pos.x>640-size/2) {
		pos.x--;
	}
}