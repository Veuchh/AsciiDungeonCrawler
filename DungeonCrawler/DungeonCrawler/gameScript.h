#pragma once

class GAME_SCRIPT
{
public:
	bool isRunning = false;
	virtual void Start();
	virtual void Run();
	virtual void Update();
	virtual void Stop();
};