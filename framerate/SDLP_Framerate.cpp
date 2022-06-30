#include "SDLP_Framerate.h"

using namespace SDLP::Framerate;

FramerateCounter::FramerateCounter()
{
	countedFrames = 0;
	frameCap = -1;
}

void FramerateCounter::Place()
{
	timer.Start();
}

void FramerateCounter::StartCalculate()
{
	capTimer.Start();
	averageFps = countedFrames / (timer.GetTicks() / 1000.f);
	if (averageFps > 2000000) {
		averageFps = 0;
	}
}

void FramerateCounter::EndCalculate()
{
	int currentFrameTicks = capTimer.GetTicks();
	if (frameCap != -1) {
		if (currentFrameTicks < frameCap) {
			SDL_Delay(frameCap - currentFrameTicks);
		}
	}
	++countedFrames;
}

void FramerateCounter::Unplace()
{
	timer.Stop();
}

void FramerateCounter::Pause()
{
	timer.Pause();
}

void FramerateCounter::Unpause()
{
	timer.Unpause();
}

void FramerateCounter::SetFpsCap(float frameCap)
{
	this->frameCap = 1000 / frameCap;
}

float FramerateCounter::GetAvgFps()
{
	return averageFps;
}
