#ifndef Player_h
#define Player_h

class Player
{
public:
	char activePlayer = 'W';

	bool changeTurns()
	{
		if (activePlayer == 'W') { activePlayer = 'B'; }
		if (activePlayer == 'B') { activePlayer = 'W'; }
	}
};


#endif // !
